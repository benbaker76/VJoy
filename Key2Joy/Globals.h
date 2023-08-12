#include "VJoyDriver.h"
#include "JoyCodes.h"

extern CVJoyDriver g_VJoy;

extern UINT g_KeyToJoyCode[JOY_COUNT][JOY_INPUT_COUNT];
extern JOYSTICK_STATE g_KeyToJoyState[JOY_COUNT];

extern BOOL g_KeyToJoyEnabled;

extern BOOL g_KeyToJoyBlockKeys;
extern BOOL g_KeyToJoyAutoCenter;

extern BOOL g_Exit;
extern BOOL g_FirstRun;

extern HANDLE g_hMainThread;

extern BOOL g_LaunchOnStartup;