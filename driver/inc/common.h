//
// Custom control codes are defined here. They are to be used for sideband 
// communication with the hid minidriver. These control codes are sent to 
// the hid minidriver using Hid_GetFeature() API to a custom collection 
// defined especially to handle such requests.
//
#define  VJOY_CONTROL_CODE_GET_ATTRIBUTES				0x00
#define  VJOY_CONTROL_CODE_JOYSTICK_1_STATE				0x01
#define  VJOY_CONTROL_CODE_JOYSTICK_2_STATE				0x02


//
// This is the report id of the collection to which the control codes are sent
//
#define CONTROL_JOYSTICK_1_REPORT_ID					0x01
#define CONTROL_JOYSTICK_2_REPORT_ID					0x02
#define CONTROL_COLLECTION_REPORT_ID					0x03

#include <pshpack1.h>

typedef struct _VJOY_CONTROL_INFO {

    //report ID of the collection to which the control request is sent

    UCHAR    ReportId;   

    // One byte control code (user-defined) for communication with hid 
    // mini driver
    
    UCHAR   ControlCode;

    // This is a placeholder for address of the buffer allocated by the caller
    // equal to the size of ControlBufferLength.

    UCHAR   ControlBuffer[];
    
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
