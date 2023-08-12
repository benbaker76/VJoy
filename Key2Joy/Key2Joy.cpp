// Key2Joy.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <sys/stat.h>
#include <Commdlg.h>
#include "resource.h"
#include "SystemTraySDK.h"
#include "InterComm.h"
#include "Globals.h"
#include "KeyCodes.h"
#include "Input.h"
#include "Hook.h"
#include "Ini.h"
#include "CmdLine.h"

#define ARRAY_LENGTH(x)		(sizeof(x) / sizeof(x[0]))

#define	WM_ICON_NOTIFY WM_APP+10

#define INI_FILE	"Key2Joy.ini"

int m_joystickIndex = 0;
HINSTANCE m_hInstance;
HWND m_hWnd;
CSystemTray m_TrayIcon;
CInterComm m_InterComm;
CCmdLine m_CmdLine;
CHAR m_appDirectory[MAX_PATH+1] = { 0 };
CHAR m_iniFileName[MAX_PATH+1] = { 0 };

const char *m_commandHelp = 
	"Key2Joy v1.0 - By Ben Baker\n\n\
USAGE: Key2Joy.exe -options\n\n\
options:\n\
  -file <file>      Ini file to load\n\
  -enable <1|0>     Enable or disable program\n\
  -blockkeys <1|0>  Block key presses\n\
  -autocenter <1|0> Auto center input\n\
  -exit             Exit program\n\
  -help             Displays this Message Box";

PCHAR m_virtualJoystick[] =
{
	"VJoy Virtual Joystick 1",
	"VJoy Virtual Joystick 2"
};

int m_comboArray[] =
{
	IDC_LEFT,
	IDC_RIGHT,
	IDC_UP,
	IDC_DOWN,
	IDC_ZAXIS_NEG,
	IDC_ZAXIS_POS,
	IDC_XROTATE_NEG,
	IDC_XROTATE_POS,
	IDC_YROTATE_NEG,
	IDC_YROTATE_POS,
	IDC_ZROTATE_NEG,
	IDC_ZROTATE_POS,
	IDC_SLIDER_NEG,
	IDC_SLIDER_POS,
	IDC_DIAL_NEG,
	IDC_DIAL_POS,
	IDC_POV0_LEFT,
	IDC_POV0_RIGHT,
	IDC_POV0_UP,
	IDC_POV0_DOWN,
	IDC_POV1_LEFT,
	IDC_POV1_RIGHT,
	IDC_POV1_UP,
	IDC_POV1_DOWN,
	IDC_POV2_LEFT,
	IDC_POV2_RIGHT,
	IDC_POV2_UP,
	IDC_POV2_DOWN,
	IDC_POV3_LEFT,
	IDC_POV3_RIGHT,
	IDC_POV3_UP,
	IDC_POV3_DOWN,
	IDC_BUTTON1,
	IDC_BUTTON2,
	IDC_BUTTON3,
	IDC_BUTTON4,
	IDC_BUTTON5,
	IDC_BUTTON6,
	IDC_BUTTON7,
	IDC_BUTTON8,
	IDC_BUTTON9,
	IDC_BUTTON10,
	IDC_BUTTON11,
	IDC_BUTTON12,
	IDC_BUTTON13,
	IDC_BUTTON14,
	IDC_BUTTON15,
	IDC_BUTTON16,
	IDC_BUTTON17,
	IDC_BUTTON18,
	IDC_BUTTON19,
	IDC_BUTTON20,
	IDC_BUTTON21,
	IDC_BUTTON22,
	IDC_BUTTON23,
	IDC_BUTTON24,
	IDC_BUTTON25,
	IDC_BUTTON26,
	IDC_BUTTON27,
	IDC_BUTTON28,
	IDC_BUTTON29,
	IDC_BUTTON30,
	IDC_BUTTON31,
	IDC_BUTTON32
};

int m_buttonArray[] =
{
	IDB_LEFT,
	IDB_RIGHT,
	IDB_UP,
	IDB_DOWN,
	IDB_ZAXIS_NEG,
	IDB_ZAXIS_POS,
	IDB_XROTATE_NEG,
	IDB_XROTATE_POS,
	IDB_YROTATE_NEG,
	IDB_YROTATE_POS,
	IDB_ZROTATE_NEG,
	IDB_ZROTATE_POS,
	IDB_SLIDER_NEG,
	IDB_SLIDER_POS,
	IDB_DIAL_NEG,
	IDB_DIAL_POS,
	IDB_POV0_LEFT,
	IDB_POV0_RIGHT,
	IDB_POV0_UP,
	IDB_POV0_DOWN,
	IDB_POV1_LEFT,
	IDB_POV1_RIGHT,
	IDB_POV1_UP,
	IDB_POV1_DOWN,
	IDB_POV2_LEFT,
	IDB_POV2_RIGHT,
	IDB_POV2_UP,
	IDB_POV2_DOWN,
	IDB_POV3_LEFT,
	IDB_POV3_RIGHT,
	IDB_POV3_UP,
	IDB_POV3_DOWN,
	IDB_BUTTON1,
	IDB_BUTTON2,
	IDB_BUTTON3,
	IDB_BUTTON4,
	IDB_BUTTON5,
	IDB_BUTTON6,
	IDB_BUTTON7,
	IDB_BUTTON8,
	IDB_BUTTON9,
	IDB_BUTTON10,
	IDB_BUTTON11,
	IDB_BUTTON12,
	IDB_BUTTON13,
	IDB_BUTTON14,
	IDB_BUTTON15,
	IDB_BUTTON16,
	IDB_BUTTON17,
	IDB_BUTTON18,
	IDB_BUTTON19,
	IDB_BUTTON20,
	IDB_BUTTON21,
	IDB_BUTTON22,
	IDB_BUTTON23,
	IDB_BUTTON24,
	IDB_BUTTON25,
	IDB_BUTTON26,
	IDB_BUTTON27,
	IDB_BUTTON28,
	IDB_BUTTON29,
	IDB_BUTTON30,
	IDB_BUTTON31,
	IDB_BUTTON32
};

PCHAR* CommandLineToArgvA(PCHAR CmdLine, int* _argc);
VOID GetApplicationDir(PCHAR path);
BOOL FileExists(PCHAR fileName);
WPARAM MessageLoop(HWND hWnd);
DWORD WINAPI MainThread(LPVOID lpParam);
void StartMainThread();
void KillMainThread();
INT_PTR CALLBACK MainProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK AboutProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void FillComboBox(HWND hWnd, int nIDDlgItem);
void SelectComboBoxItem(HWND hWnd, int nIDDlgItem, PCHAR item);
void SelectComboBoxIndex(HWND hWnd, int nIDDlgItem, int index);
void SelectComboBoxItems(HWND hWnd);
void RegisterHotKeys(HWND hWnd);
void ReadJoyToKeyIni();
void WriteJoyToKeyIni();
void OpenFile();
void SaveFile();
BOOL ProcessCmdLine(LPSTR lpCmdLine);
void AddToStartup();
void RemoveFromStartup();

PCHAR* CommandLineToArgvA(PCHAR CmdLine, int* _argc)
    {
        PCHAR* argv;
        PCHAR _argv;
        size_t len;
        ULONG argc;
        CHAR a;
        ULONG i, j;

        BOOLEAN in_QM;
        BOOLEAN in_TEXT;
        BOOLEAN in_SPACE;

        len = strlen(CmdLine);
        i = ((len+2)/2)*sizeof(PVOID) + sizeof(PVOID);

        argv = (PCHAR*)GlobalAlloc(GMEM_FIXED, i + (len+2)*sizeof(CHAR));
        _argv = (PCHAR)(((PUCHAR)argv)+i);

        argc = 0;
        argv[argc] = _argv;
        in_QM = FALSE;
        in_TEXT = FALSE;
        in_SPACE = TRUE;
        i = 0;
        j = 0;

        while(a = CmdLine[i]) {
            if(in_QM) {
                if(a == '\"') {
                    in_QM = FALSE;
                } else {
                    _argv[j] = a;
                    j++;
                }
            } else {
                switch(a) {
                case '\"':
                    in_QM = TRUE;
                    in_TEXT = TRUE;
                    if(in_SPACE) {
                        argv[argc] = _argv+j;
                        argc++;
                    }
                    in_SPACE = FALSE;
                    break;
                case ' ':
                case '\t':
                case '\n':
                case '\r':
                    if(in_TEXT) {
                        _argv[j] = '\0';
                        j++;
                    }
                    in_TEXT = FALSE;
                    in_SPACE = TRUE;
                    break;
                default:
                    in_TEXT = TRUE;
                    if(in_SPACE) {
                        argv[argc] = _argv+j;
                        argc++;
                    }
                    _argv[j] = a;
                    j++;
                    in_SPACE = FALSE;
                    break;
                }
            }
            i++;
        }
        _argv[j] = '\0';
        argv[argc] = NULL;

        (*_argc) = argc;
        return argv;
    }


VOID GetApplicationDir(PCHAR path)
{
   CHAR szPath[MAX_PATH+1];
   GetModuleFileName(NULL, szPath, MAX_PATH);

   PCHAR psz = strrchr(szPath,'\\');

   if(!psz)
   {
	   strcpy(path, szPath);
	   return;
   }

   psz[1] = '\0';
   strcpy(path, szPath);
}

BOOL FileExists(PCHAR fileName)
{ 
	struct stat stFileInfo;

	if(stat(fileName ,&stFileInfo) == 0)
		return TRUE;

	return FALSE;
}

int _stdcall MessageReceived(DataMode id, PCHAR data)
{
    switch (id)
    {
    case MODE_CMDLINE:
		ProcessCmdLine(data);
        break;
    }

	return 1;
}

DWORD WINAPI MainThread(LPVOID lpParam)
{
	while(TRUE)
	{
		if(g_KeyToJoyEnabled)
			ProcessKeyToJoy();

		Sleep(20);
	}
}

void StartMainThread()
{
	DWORD dwThreadId = NULL, dwThrdParam = 1;
	g_hMainThread = CreateThread(NULL, 0, MainThread, &dwThrdParam, 0, &dwThreadId);
}

void KillMainThread()
{
	if(g_hMainThread != NULL)
	{
		CloseHandle(g_hMainThread);
		g_hMainThread = NULL;
	}
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	m_hInstance = hInstance;

	m_InterComm.Initialize(hInstance, MessageReceived);

    if (m_InterComm.CommMode() == MODE_CLIENT)
    {
		m_InterComm.SendMessage(MODE_CMDLINE, lpCmdLine);

        return 1;
    }

	GetApplicationDir(m_appDirectory);
	strcpy(m_iniFileName, m_appDirectory);
	strcat(m_iniFileName, INI_FILE);

	m_hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAIN), NULL, MainProc);

	SendMessage(m_hWnd, WM_SETICON, ICON_BIG, (LPARAM) LoadIcon(hInstance, MAKEINTRESOURCE(IDI_KEY2JOY)));
	SendMessage(m_hWnd, WM_SETICON, ICON_SMALL, (LPARAM) LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SMALL)));

	HWND hWndDialog = GetDlgItem(m_hWnd, IDC_JOYDEVICE);

	SendMessage(hWndDialog, CB_ADDSTRING, 0, (LPARAM)m_virtualJoystick[0]);
	SendMessage(hWndDialog, CB_ADDSTRING, 0, (LPARAM)m_virtualJoystick[1]);

	SelectComboBoxIndex(m_hWnd, IDC_JOYDEVICE, 0);

	for(int i=0; i<ARRAY_LENGTH(m_comboArray); i++)
		FillComboBox(m_hWnd, m_comboArray[i]);

	ReadJoyToKeyIni();
	ProcessCmdLine(lpCmdLine);

	SendDlgItemMessage(m_hWnd, IDC_ENABLED, BM_SETCHECK, g_KeyToJoyEnabled, 0);
	SendDlgItemMessage(m_hWnd, IDC_BLOCKKEYS, BM_SETCHECK, g_KeyToJoyBlockKeys, 0);
	SendDlgItemMessage(m_hWnd, IDC_AUTOCENTER, BM_SETCHECK, g_KeyToJoyAutoCenter, 0);
	SendDlgItemMessage(m_hWnd, IDC_LAUNCH, BM_SETCHECK, g_LaunchOnStartup, 0);

	if (!m_TrayIcon.Create(hInstance, m_hWnd, WM_ICON_NOTIFY, _T("Key2Joy"), ::LoadIcon(hInstance, (LPCTSTR)IDI_SMALL), IDC_KEY2JOY))
        return FALSE;

	g_VJoy.Initialize();
	StartHookThread();
	//StartMainThread();

	int retVal = MessageLoop(m_hWnd);

	//KillMainThread();
	KillHookThread();
	g_VJoy.Shutdown();
	WriteJoyToKeyIni();

	return retVal;
}

WPARAM MessageLoop(HWND hWnd)
{
	MSG msg;

	while(GetMessage(&msg, NULL, 0, 0))
    {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
    }

	DestroyWindow(hWnd);

	return msg.wParam;
}

INT_PTR CALLBACK MainProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	HWND hWndDialog;
	int i;

	switch (message)
	{
    case WM_ICON_NOTIFY:
        return m_TrayIcon.OnTrayNotification(wParam, lParam);
	
	case WM_TIMER:
		PostQuitMessage(0);
		return 1;

	case WM_CLOSE:
		PostQuitMessage(0);
		return 1;

	case WM_QUERYENDSESSION:
		WriteJoyToKeyIni();
		return 0;

	case WM_SYSCOMMAND:
		switch(wParam)
		{
		case SC_CLOSE:
			if(MessageBox(hWnd, "Are You Sure?", "Exit Key2Joy", MB_OKCANCEL) == IDOK)
				return 0;
			else
				return 1;
		case SC_MINIMIZE:
			ShowWindow(hWnd, SW_HIDE);
			return 1;
		}
		break;

	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		hWndDialog = (HWND) lParam;

		switch (wmId)
		{
		case IDC_JOYDEVICE:
			if(wmEvent == CBN_SELCHANGE)
			{
				m_joystickIndex = (int)SendMessage(hWndDialog, CB_GETCURSEL, 0, 0);
				SelectComboBoxItems(hWnd);
			}
			return 1;
		case IDC_ENABLED:
			if(wmEvent == BN_CLICKED)
				g_KeyToJoyEnabled = SendMessage(hWndDialog, BM_GETCHECK, 0, 0);
			return 1;
		case IDC_BLOCKKEYS:
			if(wmEvent == BN_CLICKED)
				g_KeyToJoyBlockKeys = SendMessage(hWndDialog, BM_GETCHECK, 0, 0);
			return 1;
		case IDC_AUTOCENTER:
			if(wmEvent == BN_CLICKED)
				g_KeyToJoyAutoCenter = SendMessage(hWndDialog, BM_GETCHECK, 0, 0);
			return 1;
		case IDC_LAUNCH:
			if(wmEvent == BN_CLICKED)
			{
				g_LaunchOnStartup = SendMessage(hWndDialog, BM_GETCHECK, 0, 0);

				if(g_LaunchOnStartup)
					AddToStartup();
				else
					RemoveFromStartup();
			}
			return 1;
		case IDB_OK:
		case IDB_CLOSE:
			if(wmEvent == BN_CLICKED)
				ShowWindow(hWnd, SW_HIDE);
			return 1;
		case IDB_OPEN:
			if(wmEvent == BN_CLICKED)
				OpenFile();
			return 1;
		case IDB_SAVE:
			if(wmEvent == BN_CLICKED)
				SaveFile();
			return 1;
		case IDM_OPEN:
			ShowWindow(hWnd, SW_SHOW);
			UpdateWindow(hWnd);
			return 1;
		case IDM_ABOUT:
			DialogBox(m_hInstance, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)AboutProc);
			return 1;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			return 1;
		default:
			for(i=0; i<ARRAY_LENGTH(m_comboArray); i++)
			{
				if(wmId == m_comboArray[i])
				{
					if(wmEvent == CBN_SELCHANGE)
					{
						int index = SendMessage(hWndDialog, CB_GETCURSEL, 0, 0);
						
						g_KeyToJoyCode[m_joystickIndex][i] = key_codes[index].VKCode;
						return TRUE;
					}
				}
			}

			for(i=0; i<ARRAY_LENGTH(m_buttonArray); i++)
			{
				if(wmId == m_buttonArray[i])
				{
					if(wmEvent == BN_CLICKED)
					{
						DialogBoxParam(m_hInstance, (LPCTSTR)IDD_INPUT, hWnd, (DLGPROC)InputProc, i);
						return TRUE;
					}
				}
			}
			return 0;
		}

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return 0;
	}

	return 0;
}


LRESULT CALLBACK AboutProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
		{
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}

	return FALSE;
}

BOOL CALLBACK InputProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int buttonIndex = 0;
	int vkCode;

	switch (message)
	{
	case WM_INITDIALOG:
		buttonIndex = lParam;
		RegisterHotKeys(hDlg);
		return TRUE;

	case WM_HOTKEY:
		if ((GetKeyState(VK_LSHIFT) & 0xF0000000))
            vkCode = VK_LSHIFT;
        else if ((GetKeyState(VK_RSHIFT) & 0xF0000000))
            vkCode = VK_RSHIFT;
        else if ((GetKeyState(VK_LCONTROL) & 0xF0000000))
            vkCode = VK_LCONTROL;
        else if ((GetKeyState(VK_RCONTROL) & 0xF0000000))
            vkCode = VK_RCONTROL;
        else if ((GetKeyState(VK_LMENU) & 0xF0000000))
            vkCode = VK_LMENU;
        else if ((GetKeyState(VK_RMENU) & 0xF0000000))
            vkCode = VK_RMENU;
		else
			vkCode = key_codes[wParam].VKCode;

		g_KeyToJoyCode[m_joystickIndex][buttonIndex] = vkCode;
		SelectComboBoxItem(m_hWnd, m_comboArray[buttonIndex], VK2Name(vkCode));
		
		EndDialog(hDlg, IDCANCEL);
		return TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}

	return FALSE;
}

void FillComboBox(HWND hWnd, int nIDDlgItem)
{
	HWND hWndDialog = GetDlgItem(hWnd, nIDDlgItem);

	//SendMessage(hWndDialog, CB_SETDROPPEDWIDTH, 64, 0);
	//SendMessage(hWndDialog, CB_ADDSTRING, 0, (LPARAM)"");

	for (int i = 0; i < ARRAY_LENGTH(key_codes); i++)
		SendMessage(hWndDialog, CB_ADDSTRING, 0, (LPARAM)key_codes[i].Name);
}

void SelectComboBoxItem(HWND hWnd, int nIDDlgItem, PCHAR item)
{
	HWND hWndDialog = GetDlgItem(hWnd, nIDDlgItem);

	SelectComboBoxIndex(hWnd, nIDDlgItem, SendMessage(hWndDialog, CB_FINDSTRINGEXACT, -1, (LPARAM)item));
}

void SelectComboBoxIndex(HWND hWnd, int nIDDlgItem, int index)
{
	HWND hWndDialog = GetDlgItem(hWnd, nIDDlgItem);

	SendMessage(hWndDialog, CB_SETCURSEL, index, 0);
}

void SelectComboBoxItems(HWND hWnd)
{
	for(int i=0; i<ARRAY_LENGTH(m_comboArray); i++)
	{
		PCHAR KeyName = VK2Name(g_KeyToJoyCode[m_joystickIndex][i]);
		
		SelectComboBoxItem(hWnd, m_comboArray[i], KeyName);
	}
}

void RegisterHotKeys(HWND hWnd)
{
	int i = 0;

	for (; i < ARRAY_LENGTH(key_codes); i++)
		RegisterHotKey(hWnd, i, 0, key_codes[i].VKCode);

	RegisterHotKey(hWnd, i++, MOD_ALT, 0);
	RegisterHotKey(hWnd, i++, MOD_CONTROL, 0);
	RegisterHotKey(hWnd, i++, MOD_SHIFT, 0);
	RegisterHotKey(hWnd, i++, MOD_WIN, 0);
}

void ReadJoyToKeyIni()
{
	CHAR buf[MAX_PATH+1];
	
	ReadKeyToJoy(m_iniFileName, buf);
	SelectComboBoxItems(m_hWnd);
}

void WriteJoyToKeyIni()
{
	WriteKeyToJoy(m_iniFileName);
}

void OpenFile()
{
	OPENFILENAME ofn;

	memset(&ofn, 0, sizeof(ofn));

	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = m_hWnd;
	ofn.hInstance = m_hInstance;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	ofn.lpstrInitialDir = m_appDirectory;
	ofn.lpstrFile = m_iniFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.nFilterIndex = 2;
	ofn.lpstrFilter = "All Files\0*.*\0Ini Files\0*.ini\0";

	if(GetOpenFileName(&ofn))
		ReadJoyToKeyIni();
}

void SaveFile()
{
	OPENFILENAME ofn;

	memset(&ofn, 0, sizeof(ofn));

	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = m_hWnd;
	ofn.hInstance = m_hInstance;
	ofn.Flags = 0;
	ofn.lpstrInitialDir = m_appDirectory;
	ofn.lpstrFile = m_iniFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.nFilterIndex = 2;
	ofn.lpstrFilter = "All Files\0*.*\0Ini Files\0*.ini\0";

	if(GetSaveFileName(&ofn))
		WriteJoyToKeyIni();
}

BOOL ProcessCmdLine(LPSTR lpCmdLine)
{
	int argc;
	PCHAR *argv;

	argv = CommandLineToArgvA(lpCmdLine, &argc);

	if(m_CmdLine.SplitLine(argc, argv) < 1)
		return FALSE;

	if (m_CmdLine.HasSwitch("-help"))
	{
		MessageBox(NULL, m_commandHelp, "Help", MB_OK);
		return TRUE;
	}

	if(m_CmdLine.HasSwitch("-exit"))
	{
		SendMessage(m_hWnd, WM_CLOSE, 0, 0);
		return TRUE;
	}

	if(m_CmdLine.HasSwitch("-blockkeys"))
	{
		if(m_CmdLine.GetArgument("-blockkeys", 0).compare("1") == 0)
			g_KeyToJoyBlockKeys = TRUE;
		else
			g_KeyToJoyBlockKeys = FALSE;

		SendDlgItemMessage(m_hWnd, IDC_BLOCKKEYS, BM_SETCHECK, g_KeyToJoyBlockKeys, 0);
	}

	if(m_CmdLine.HasSwitch("-autocenter"))
	{
		if(m_CmdLine.GetArgument("-selfcenter", 0).compare("1") == 0)
			g_KeyToJoyAutoCenter = TRUE;
		else
			g_KeyToJoyAutoCenter = FALSE;

		SendDlgItemMessage(m_hWnd, IDC_AUTOCENTER, BM_SETCHECK, g_KeyToJoyAutoCenter, 0);
	}


	if(m_CmdLine.HasSwitch("-enable"))
	{
		if(m_CmdLine.GetArgument("-enable", 0).compare("1") == 0)
			g_KeyToJoyEnabled = TRUE;
		else
			g_KeyToJoyEnabled = FALSE;

		SendDlgItemMessage(m_hWnd, IDC_ENABLED, BM_SETCHECK, g_KeyToJoyEnabled, 0);
	}

	if(m_CmdLine.HasSwitch("-file"))
	{
		string iniFileName = m_CmdLine.GetArgument("-file", 0);

		if(FileExists((PCHAR) iniFileName.c_str()))
		{
			strcpy(m_iniFileName, iniFileName.c_str());

			ReadJoyToKeyIni();
		}
	}

	for(int i=0; i<argc; i++)
		GlobalFree(argv[i]);

	return FALSE;
}

void AddToStartup()
{
	HKEY hKey;
	CHAR szPath[MAX_PATH+1];
	GetModuleFileName(NULL, szPath, MAX_PATH);
	DWORD cbData = strlen(szPath) + 1;

	if(RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS)
	{
		RegSetValueEx(hKey, "Key2Joy", 0, REG_SZ, (PUCHAR) szPath, cbData);
		RegCloseKey(hKey);
	}
}

void RemoveFromStartup()
{
	HKEY hKey;

    if(RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", &hKey) == ERROR_SUCCESS)
	{
		RegDeleteValue(hKey, "Key2Joy");
	    RegCloseKey(hKey);
	}
}
