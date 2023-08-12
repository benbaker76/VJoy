#include <TCHAR.h>
extern "C" 
{
#include "setupapi.h" 
#include "hidsdi.h" 
}
#include "Debug.h"

#define MYUSAGEPAGE		0xff00
#define MYUSAGE 		0x0001

#define VENDOR_ID		0xFEED
#define PRODUCT_ID		0xFACE

#define VJOY_AXIS_MIN	-32768
#define VJOY_AXIS_NIL	0
#define VJOY_AXIS_MAX	32767

#define POV_UP			0
#define POV_RIGHT		1
#define POV_DOWN		2
#define POV_LEFT		3
#define POV_NIL			4

#define VJOY_CONTROL_CODE_GET_ATTRIBUTES				0x00
#define VJOY_CONTROL_CODE_JOYSTICK_1_STATE				0x01
#define VJOY_CONTROL_CODE_JOYSTICK_2_STATE				0x02

#define CONTROL_JOYSTICK_1_REPORT_ID					0x01
#define CONTROL_JOYSTICK_2_REPORT_ID					0x02
#define CONTROL_COLLECTION_REPORT_ID					0x03

#include <pshpack1.h>

typedef struct _VJOY_CONTROL_INFO
{
    UCHAR ReportId;   
    UCHAR ControlCode;
    UCHAR ControlBuffer[];
    
} VJOY_CONTROL_INFO, * PVJOY_CONTROL_INFO;

typedef struct _JOYSTICK_STATE
{
	UCHAR ReportId;				// Report Id
	SHORT XAxis;				// X Axis
	SHORT YAxis;				// Y Axis
	SHORT ZAxis;				// Z Axis
	SHORT XRotation;			// X Rotation
	SHORT YRotation;			// Y Rotation
	SHORT ZRotation;			// Z Rotation
	SHORT Slider;				// Slider
	SHORT Dial;					// Dial
	USHORT POV;					// POV
	UINT32 Buttons;				// 32 Buttons
} JOYSTICK_STATE, * PJOYSTICK_STATE;

#include <poppack.h>

typedef struct _HID_DEVICE_ATTRIBUTES
{
    ULONG Size;
    USHORT VendorID;
    USHORT ProductID;
    USHORT VersionNumber;
    USHORT Reserved[11];

} HID_DEVICE_ATTRIBUTES, * PHID_DEVICE_ATTRIBUTES;

class CVJoyDriver
{
public:
	CVJoyDriver();
	virtual ~CVJoyDriver();

	BOOL Initialize();
	void Shutdown();
	BOOL UpdateJoyState(int id, PJOYSTICK_STATE pJoyState);

private:
	HANDLE m_pFile;
	PJOYSTICK_STATE m_pJoyState;
	PVJOY_CONTROL_INFO m_pControlInfo;
	ULONG m_bufferSize;

	VOID SendHidRequests(HANDLE file);
	BOOL SearchMatchingHwID(IN HDEVINFO DeviceInfoSet, IN PSP_DEVINFO_DATA DeviceInfoData);
	BOOL OpenDeviceInterface(IN HDEVINFO HardwareDeviceInfo, IN PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData);
	BOOL CheckIfOurDevice(HANDLE file);
};
