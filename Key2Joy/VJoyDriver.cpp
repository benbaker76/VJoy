// testvjoy.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "VJoyDriver.h"

CVJoyDriver::CVJoyDriver()
{
	m_bufferSize = sizeof(VJOY_CONTROL_INFO) + sizeof(JOYSTICK_STATE);

	m_pControlInfo = (PVJOY_CONTROL_INFO) malloc(m_bufferSize);
	m_pJoyState = (PJOYSTICK_STATE) (m_pControlInfo + sizeof(VJOY_CONTROL_INFO) - 1);

	if(!m_pControlInfo)
		DebugPrint(("malloc failed\n"));
}

CVJoyDriver::~CVJoyDriver()
{
	Shutdown();
}

BOOL CVJoyDriver::Initialize()
{
    HDEVINFO hardwareDeviceInfo;
    SP_DEVICE_INTERFACE_DATA deviceInterfaceData;
    SP_DEVINFO_DATA devInfoData;
    GUID hidguid;
    int i;

	DebugPrint(("Initialize\n"));

    HidD_GetHidGuid(&hidguid);

    hardwareDeviceInfo = SetupDiGetClassDevs((LPGUID)&hidguid, NULL, NULL, (DIGCF_PRESENT | DIGCF_INTERFACEDEVICE));

    if(hardwareDeviceInfo == INVALID_HANDLE_VALUE)
	{
		DebugPrint(("SetupDiGetClassDevs failed: %x\n", GetLastError()));
        return FALSE;
    }

    deviceInterfaceData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);
    devInfoData.cbSize = sizeof(SP_DEVINFO_DATA);

    DebugPrint(("looking for our HID device (with UsagePage=0x%4X and Usage=0x%02X)\n", MYUSAGEPAGE, MYUSAGE));

    for(i = 0; SetupDiEnumDeviceInterfaces(hardwareDeviceInfo, 0, (LPGUID) &hidguid, i, &deviceInterfaceData); i++)
	{
        if(OpenDeviceInterface(hardwareDeviceInfo, &deviceInterfaceData))
		{
            SetupDiDestroyDeviceInfoList(hardwareDeviceInfo);
			
            return TRUE;
        }
    }

    SetupDiDestroyDeviceInfoList(hardwareDeviceInfo);

    DebugPrint(("Failure: Could not find our HID device\n"));

    return FALSE;
}

void CVJoyDriver::Shutdown()
{
	if(m_pFile != NULL)
	{
		CloseHandle(m_pFile);
		m_pFile = NULL;
	}

	if(m_pControlInfo)
	{
		free(m_pControlInfo);
		m_pControlInfo = NULL;
	}
}

BOOL CVJoyDriver::OpenDeviceInterface(IN HDEVINFO hardwareDeviceInfo, IN PSP_DEVICE_INTERFACE_DATA deviceInterfaceData)
{
    PSP_DEVICE_INTERFACE_DETAIL_DATA deviceInterfaceDetailData = NULL;
    DWORD predictedLength = 0;
    DWORD requiredLength = 0;
    BOOL deviceFound = FALSE;

    SetupDiGetDeviceInterfaceDetail(hardwareDeviceInfo, deviceInterfaceData, NULL, 0, &requiredLength, NULL);

    predictedLength = requiredLength;

    deviceInterfaceDetailData = (PSP_DEVICE_INTERFACE_DETAIL_DATA) malloc(predictedLength);

    if(!deviceInterfaceDetailData)
    {
        DebugPrint(("Error: OpenDeviceInterface: malloc failed\n"));
        return FALSE;
    }

    deviceInterfaceDetailData->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);

    if (!SetupDiGetDeviceInterfaceDetail(hardwareDeviceInfo, deviceInterfaceData, deviceInterfaceDetailData, predictedLength, &requiredLength, NULL))
    {
        DebugPrint(("Error: SetupDiGetInterfaceDeviceDetail failed\n"));
        free (deviceInterfaceDetailData);
        return FALSE;
    }
	
	DebugPrint(("Path = %s\n", deviceInterfaceDetailData->DevicePath));

    m_pFile = CreateFile(deviceInterfaceDetailData->DevicePath,
						GENERIC_READ | GENERIC_WRITE,
						FILE_SHARE_READ | FILE_SHARE_WRITE, // FILE_SHARE_READ
						NULL, // no SECURITY_ATTRIBUTES structure
						OPEN_EXISTING, // No special create flags
						0, // No special attributes
						NULL); // No template file

    if (m_pFile == INVALID_HANDLE_VALUE)
	{
        DebugPrint(("Error: CreateFile failed: %d\n", GetLastError()));
        free(deviceInterfaceDetailData);
        return FALSE;
    }

    if(CheckIfOurDevice(m_pFile))
	{
        deviceFound  = TRUE;

        DebugPrint(("Device Found!\n"));

        SendHidRequests(m_pFile);
    }

    free(deviceInterfaceDetailData);

    return deviceFound;
}

BOOL CVJoyDriver::CheckIfOurDevice(HANDLE file)
{
	HIDD_ATTRIBUTES hiddAttributes;
    PHIDP_PREPARSED_DATA Ppd;
    HIDP_CAPS Caps;
    USAGE MyUsagePage = MYUSAGEPAGE;
    USAGE MyUsage = MYUSAGE;

	if(!HidD_GetAttributes(file, &hiddAttributes))
	{
		DebugPrint(("Error: HidD_GetAttributes failed\n"));
        return FALSE;
	}

	DebugPrint(("VID: %04X, PID: %04X\n", hiddAttributes.VendorID, hiddAttributes.ProductID));

	if(hiddAttributes.VendorID != VENDOR_ID || hiddAttributes.ProductID != PRODUCT_ID)
	{
		DebugPrint(("Error: VID or PID mismatch\n"));
        return FALSE;
	}

    if (!HidD_GetPreparsedData(file, &Ppd))
    {
        DebugPrint(("Error: HidD_GetPreparsedData failed\n"));
        return FALSE;
    }

    if (!HidP_GetCaps(Ppd, &Caps))
    {
        DebugPrint(("Error: HidP_GetCaps failed\n"));
        HidD_FreePreparsedData(Ppd);
        return FALSE;
    }
	
	DebugPrint(("UsagePage: %04X, User: %02X\n", Caps.UsagePage, Caps.Usage));

    if(Caps.UsagePage != MyUsagePage || Caps.Usage != MyUsage)
	{
        DebugPrint(("Error: UsagePage or Usage mismatch\n"));
        return FALSE;
    }

    return TRUE;
}

VOID CVJoyDriver::SendHidRequests(HANDLE file)
{
    PVJOY_CONTROL_INFO controlInfo = NULL;
    PHID_DEVICE_ATTRIBUTES devAttributes = NULL;
    ULONG bufferSize;

	DebugPrint(("Sending control request to our device...\n"));

    bufferSize = sizeof(VJOY_CONTROL_INFO) + sizeof(HID_DEVICE_ATTRIBUTES);
				
    controlInfo = (PVJOY_CONTROL_INFO) malloc(bufferSize);

    if (!controlInfo)
    {
        DebugPrint(("malloc failed\n"));
        return;
    }

    controlInfo->ReportId = CONTROL_COLLECTION_REPORT_ID;
    controlInfo->ControlCode = VJOY_CONTROL_CODE_GET_ATTRIBUTES;

    if(!HidD_GetFeature(file, controlInfo, bufferSize))
    {
        DebugPrint(("failed HidD_GetFeature\n"));
    }
    else
    {
        DebugPrint(("\nSuccess: HidD_GetFeature with control code\n"
                "            VJOY_CONTROL_CODE_GET_ATTRIBUTES\n"));

        devAttributes = (PHID_DEVICE_ATTRIBUTES)controlInfo->ControlBuffer;

        DebugPrint(("Device Attributes:\n"));
        DebugPrint(("    VendorID: 0x%x,\n"
                "    ProductID: 0x%x,\n"
                "    VersionNumber: 0x%x\n",
                devAttributes->VendorID,
                devAttributes->ProductID,
                devAttributes->VersionNumber));
    }

    free(controlInfo);
    devAttributes = NULL;
}

BOOL CVJoyDriver::UpdateJoyState(int id, PJOYSTICK_STATE pJoyState)
{
	memcpy(m_pJoyState, pJoyState, sizeof(JOYSTICK_STATE));

	m_pControlInfo->ReportId = CONTROL_COLLECTION_REPORT_ID;
	m_pControlInfo->ControlCode = (id == 0 ? VJOY_CONTROL_CODE_JOYSTICK_1_STATE : VJOY_CONTROL_CODE_JOYSTICK_2_STATE);

	if(!HidD_GetFeature(m_pFile, m_pControlInfo, m_bufferSize))
	{
		DebugPrint(("failed HidD_GetFeature\n"));
		return FALSE;
	}

	return TRUE;
}
