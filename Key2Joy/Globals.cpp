#include "stdafx.h"
#include "Globals.h"

CVJoyDriver g_VJoy;

UINT g_KeyToJoyCode[JOY_COUNT][JOY_INPUT_COUNT] = { 0 };
JOYSTICK_STATE g_KeyToJoyState[JOY_COUNT] = { 0 };

BOOL g_KeyToJoyEnabled = FALSE;

BOOL g_KeyToJoyBlockKeys = FALSE;
BOOL g_KeyToJoyAutoCenter = TRUE;

BOOL g_Exit = FALSE;
BOOL g_FirstRun = TRUE;

HANDLE g_hMainThread = NULL;

BOOL g_LaunchOnStartup = FALSE;
