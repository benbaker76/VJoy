#define WH_KEYBOARD_LL 13

#define MOUSE_NONE		0
#define MOUSE_UP		1
#define MOUSE_DOWN		2
#define MOUSE_LEFT		3
#define MOUSE_RIGHT		4
#define MOUSE_LBUTTON	5
#define MOUSE_RBUTTON	6
#define MOUSE_MBUTTON	7

typedef struct
{
	BYTE Keys[256];
	UINT Key;
	BOOL Alt;
	BOOL Control;
	BOOL Shift;
	BOOL CapsLock;
	CHAR Char;
	BOOL KeyDown;
	BOOL Handled;
	BOOL ReMap;
} KEYEVENTARGS, *PKEYEVENTARGS;

typedef struct {
	INT Button;
	INT ClickCount;
	INT X;
	INT Y;
	SHORT MouseDelta;
	BOOL Handled;
} MOUSEEVENTARGS, *PMOUSEEVENTARGS;

void ProcessKeyToJoy(PKEYEVENTARGS e);
void ProcessKeyToJoy();

void StartVJoy();
void KillVJoy();
