#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <setupapi.h>
#include <hidsdi.h>
#include <TCHAR.h>
#include "common.h"

#define MYUSAGEPAGE		0xff00
#define MYUSAGE 		0x0001

VOID SendHidRequests(HANDLE file);
VOID SendHidJoyState(HANDLE file);
BOOL SearchMatchingHwID(IN HDEVINFO DeviceInfoSet, IN PSP_DEVINFO_DATA DeviceInfoData);
BOOL OpenDeviceInterface(IN HDEVINFO HardwareDeviceInfo, IN PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData);

BOOLEAN CheckIfOurDevice(HANDLE file);

typedef struct _HID_DEVICE_ATTRIBUTES
{
    ULONG           Size;
    USHORT          VendorID;
    USHORT          ProductID;
    USHORT          VersionNumber;
    USHORT          Reserved[11];

} HID_DEVICE_ATTRIBUTES, * PHID_DEVICE_ATTRIBUTES;

int __cdecl main(int argc, char *argv[])
{
    HDEVINFO hardwareDeviceInfo;
    SP_DEVICE_INTERFACE_DATA deviceInterfaceData;
    SP_DEVINFO_DATA devInfoData;
    GUID hidguid;
    int i;

    UNREFERENCED_PARAMETER(argc);
    UNREFERENCED_PARAMETER(argv);

    HidD_GetHidGuid(&hidguid);

    hardwareDeviceInfo = SetupDiGetClassDevs ((LPGUID)&hidguid, NULL, NULL, (DIGCF_PRESENT | DIGCF_INTERFACEDEVICE));

    if(INVALID_HANDLE_VALUE == hardwareDeviceInfo)
	{
		printf("SetupDiGetClassDevs failed: %x\n", GetLastError());
        return 1;
    }

    deviceInterfaceData.cbSize = sizeof (SP_DEVICE_INTERFACE_DATA);
    devInfoData.cbSize = sizeof(SP_DEVINFO_DATA);

    printf("\n....looking for our HID device (with UsagePage=0x%4X and Usage=0x%02X)\n", MYUSAGEPAGE, MYUSAGE);

    for(i = 0; SetupDiEnumDeviceInterfaces (hardwareDeviceInfo, 0, (LPGUID) &hidguid, i, &deviceInterfaceData); i++)
	{
        if(OpenDeviceInterface(hardwareDeviceInfo, &deviceInterfaceData))
		{
            SetupDiDestroyDeviceInfoList (hardwareDeviceInfo);
			
            return 0;
        }
    }

    SetupDiDestroyDeviceInfoList (hardwareDeviceInfo);

    printf("Failure: Could not find our HID device \n");

    return 0;
}

BOOL OpenDeviceInterface (IN HDEVINFO hardwareDeviceInfo, IN PSP_DEVICE_INTERFACE_DATA deviceInterfaceData)
{
    PSP_DEVICE_INTERFACE_DETAIL_DATA    deviceInterfaceDetailData = NULL;

    DWORD predictedLength = 0;
    DWORD requiredLength = 0;
    HANDLE file = NULL;
    BOOL deviceFound = FALSE;

    SetupDiGetDeviceInterfaceDetail(hardwareDeviceInfo, deviceInterfaceData, NULL, 0, &requiredLength, NULL);

    predictedLength = requiredLength;

    deviceInterfaceDetailData = (PSP_DEVICE_INTERFACE_DETAIL_DATA) malloc (predictedLength);

    if(!deviceInterfaceDetailData)
    {
        printf("Error: OpenDeviceInterface: malloc failed\n");
        return FALSE;
    }

    deviceInterfaceDetailData->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);

    if (!SetupDiGetDeviceInterfaceDetail(hardwareDeviceInfo, deviceInterfaceData, deviceInterfaceDetailData, predictedLength, &requiredLength, NULL))
    {
        printf("Error: SetupDiGetInterfaceDeviceDetail failed\n");
        free (deviceInterfaceDetailData);
        return FALSE;
    }
	
	printf("Path = %s\n", deviceInterfaceDetailData->DevicePath);

    file = CreateFile(deviceInterfaceDetailData->DevicePath,
						GENERIC_READ | GENERIC_WRITE,
						FILE_SHARE_READ | FILE_SHARE_WRITE, // FILE_SHARE_READ
						NULL, // no SECURITY_ATTRIBUTES structure
						OPEN_EXISTING, // No special create flags
						0, // No special attributes
						NULL); // No template file

    if (file == INVALID_HANDLE_VALUE)
	{
        printf("Error: CreateFile failed: %d\n", GetLastError());
        free (deviceInterfaceDetailData);
        return FALSE;
    }

    if(CheckIfOurDevice(file))
	{
        deviceFound  = TRUE;

        printf("...sending control request to our device\n");

        SendHidRequests(file);
		SendHidJoyState(file);
    }

	CloseHandle(file);

    free (deviceInterfaceDetailData);

    return deviceFound;
}


BOOLEAN CheckIfOurDevice(HANDLE file)
{
    PHIDP_PREPARSED_DATA Ppd;
    HIDP_CAPS Caps;
    USAGE MyUsagePage = MYUSAGEPAGE;
    USAGE MyUsage = MYUSAGE;

    if (!HidD_GetPreparsedData (file, &Ppd))
    {
        printf("Error: HidD_GetPreparsedData failed \n");
        return FALSE;
    }

    if (!HidP_GetCaps (Ppd, &Caps))
    {
        printf("Error: HidP_GetCaps failed \n");
        HidD_FreePreparsedData (Ppd);
        return FALSE;
    }
	
	printf("UsagePage: %04X, User: %02X\n", Caps.UsagePage, Caps.Usage);

    if((Caps.UsagePage == MyUsagePage) && (Caps.Usage == MyUsage))
	{
        printf("Success: Found my device.. \n");
        return TRUE;
    }

    return FALSE;
}


VOID SendHidRequests(HANDLE file)
{
    PVJOY_CONTROL_INFO controlInfo = NULL;
    PHID_DEVICE_ATTRIBUTES devAttributes = NULL;
    ULONG bufferSize;

    bufferSize = sizeof (VJOY_CONTROL_INFO) + sizeof (HID_DEVICE_ATTRIBUTES);
				
    controlInfo = (PVJOY_CONTROL_INFO) malloc (bufferSize);

    if (!controlInfo )
    {
        printf("malloc failed\n");
        return;
    }

    controlInfo->ReportId = CONTROL_COLLECTION_REPORT_ID;
    controlInfo->ControlCode = VJOY_CONTROL_CODE_GET_ATTRIBUTES;

    if(!HidD_GetFeature(file, controlInfo, bufferSize))
    {
        printf("failed HidD_GetFeature \n");
    }
    else
    {
        printf("\nSuccess: HidD_GetFeature with control code \n"
                "            VJOY_CONTROL_CODE_GET_ATTRIBUTES \n");

        devAttributes = (PHID_DEVICE_ATTRIBUTES)controlInfo->ControlBuffer;

        printf("Device Attributes: \n");
        printf("    VendorID: 0x%x, \n"
                "    ProductID: 0x%x, \n"
                "    VersionNumber: 0x%x\n",
                devAttributes->VendorID,
                devAttributes->ProductID,
                devAttributes->VersionNumber);
    }

    free(controlInfo);
    devAttributes = NULL;
}

VOID SendHidJoyState(HANDLE file)
{
    PVJOY_CONTROL_INFO  controlInfo = NULL;
    PJOYSTICK_STATE joyState = NULL;
    ULONG bufferSize;

    bufferSize = sizeof (VJOY_CONTROL_INFO) + sizeof (JOYSTICK_STATE);
				
    controlInfo = (PVJOY_CONTROL_INFO) malloc (bufferSize);
	joyState = (PJOYSTICK_STATE) (controlInfo + sizeof (VJOY_CONTROL_INFO) - 1);

    if (!controlInfo)
    {
        printf("malloc failed\n");
        return;
    }

    controlInfo->ReportId = CONTROL_COLLECTION_REPORT_ID;
    controlInfo->ControlCode = VJOY_CONTROL_CODE_JOYSTICK_1_STATE;
	joyState->XAxis = 32767;
	joyState->YAxis = 32767;
	joyState->ZAxis = 32767;
	joyState->XRotation = 32767;
	joyState->YRotation = 32767;
	joyState->ZRotation = 32767;
	joyState->Slider = 32767;
	joyState->Dial = 32767;
	joyState->POV = (4 << 12) | (4 << 8) | (4 << 4) | 4;
	joyState->Buttons = (1 << 31);

    if(!HidD_GetFeature(file, controlInfo, bufferSize))
        printf("failed HidD_GetFeature \n");

    free(controlInfo);
    joyState = NULL;
}
