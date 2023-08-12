#include "stdafx.h"
#include <stdio.h>
#include "Input.h"
#include "Globals.h"

HHOOK m_hKeyboardHook;
HHOOK m_hMouseHook;
HANDLE m_hHookThread;
DWORD m_tidHook;

LRESULT CALLBACK KeyboardHookProc(INT nCode, WPARAM wParam, LPARAM lParam)
{
	BOOL Handled = FALSE;

    if (nCode < 0 || nCode != HC_ACTION)
        return CallNextHookEx(m_hKeyboardHook, nCode, wParam, lParam);

	PKBDLLHOOKSTRUCT kbd = (PKBDLLHOOKSTRUCT) lParam;
	static KEYEVENTARGS keys = { 0 };
	static BYTE keyState[256] = { 0 };

	// KeyDown event
    if ((kbd->flags & 0x80) == 0)
    {
        BOOL isAltDown = ((kbd->flags & LLKHF_ALTDOWN) != 0);
        BOOL isControlDown = (GetAsyncKeyState(VK_CONTROL) != 0);
        BOOL isShiftDown = (GetAsyncKeyState(VK_SHIFT) != 0);
        BOOL isCapsLockDown = (GetAsyncKeyState(VK_CAPITAL) != 0);

        GetKeyboardState(keyState);
        WORD inBuffer;
        CHAR ch = '\0';

        if (ToAscii(kbd->vkCode, kbd->scanCode, keyState, &inBuffer, kbd->flags) == 1)
        {
            ch = (CHAR)inBuffer;

            if ((isCapsLockDown ^ isShiftDown) && IsCharAlpha(ch))
                ch = toupper(ch);
        }

		keys.Keys[kbd->vkCode] = TRUE;
		keys.Key = kbd->vkCode;
		keys.Alt = isAltDown;
		keys.Control = isControlDown;
		keys.Shift = isShiftDown;
		keys.CapsLock = isCapsLockDown;
		keys.Char = ch;
		keys.KeyDown = TRUE;
		keys.Handled = FALSE;
		keys.ReMap = FALSE;

		if(g_KeyToJoyEnabled)
			ProcessKeyToJoy(&keys);

		Handled = keys.Handled;
    }

    // KeyUp event
    if ((kbd->flags & 0x80) != 0)
    {
        BOOL isAltDown = ((kbd->flags & LLKHF_ALTDOWN) != 0);
        BOOL isControlDown = (GetAsyncKeyState(VK_CONTROL) != 0);
        BOOL isShiftDown = (GetAsyncKeyState(VK_SHIFT) != 0);
        BOOL isCapsLockDown = (GetAsyncKeyState(VK_CAPITAL) != 0);

        GetKeyboardState(keyState);
        WORD inBuffer;
        CHAR ch = '\0';

        if (ToAscii(kbd->vkCode, kbd->scanCode, keyState, &inBuffer, kbd->flags) == 1)
        {
            ch = (CHAR)inBuffer;

            if ((isCapsLockDown ^ isShiftDown) && IsCharAlpha(ch))
                ch = toupper(ch);
        }

		keys.Keys[kbd->vkCode] = FALSE;
		keys.Key = kbd->vkCode;
		keys.Alt = isAltDown;
		keys.Control = isControlDown;
		keys.Shift = isShiftDown;
		keys.CapsLock = isCapsLockDown;
		keys.Char = ch;
		keys.KeyDown = FALSE;
		keys.Handled = FALSE;
		keys.ReMap = FALSE;

		if(g_KeyToJoyEnabled)
			ProcessKeyToJoy(&keys);

		Handled = keys.Handled;
    }

	return (Handled ? 1 : CallNextHookEx(m_hKeyboardHook, nCode, wParam, lParam));
}

LRESULT CALLBACK MouseHookProc(INT nCode, WPARAM wParam, LPARAM lParam)
{
	BOOL Handled = FALSE;

    if (nCode < 0 || nCode != HC_ACTION)
        return CallNextHookEx(m_hMouseHook, nCode, wParam, lParam);

	PMSLLHOOKSTRUCT mouse = (PMSLLHOOKSTRUCT) lParam;

	static MOUSEEVENTARGS mouseArgs;

	mouseArgs.Button = MOUSE_NONE;
    mouseArgs.MouseDelta = 0;
	mouseArgs.ClickCount = 0;
	mouseArgs.X = mouse->pt.x;
	mouseArgs.Y = mouse->pt.y;
	mouseArgs.Handled = FALSE;

    switch (wParam)
    {
        case WM_LBUTTONDOWN:
            mouseArgs.Button = MOUSE_LBUTTON;
            break;
        case WM_RBUTTONDOWN:
            mouseArgs.Button = MOUSE_RBUTTON;
            break;
		case WM_MBUTTONDOWN:
            mouseArgs.Button = MOUSE_MBUTTON;
            break;
        case WM_MOUSEWHEEL:
            mouseArgs.MouseDelta = (SHORT)((mouse->mouseData >> 16) & 0xffff);
            break;
    }

    if (mouseArgs.Button != MOUSE_NONE)
        mouseArgs.ClickCount = (wParam == WM_LBUTTONDBLCLK || wParam == WM_RBUTTONDBLCLK) ? 2 : 1;

	//if(g_MouseToNilEnabled)
	//	ProcessMouseToNil(&mouseArgs);

	Handled = mouseArgs.Handled;

	return (Handled ? 1 : CallNextHookEx(m_hMouseHook, nCode, wParam, lParam));
}

DWORD WINAPI HookThread(LPVOID lpParam)
{
	//if(g_KeyToJoyEnabled)
	m_hKeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC) KeyboardHookProc, GetModuleHandle(NULL), 0);

	//if(g_MouseToNilEnabled)
	//	m_hMouseHook = SetWindowsHookEx(WH_MOUSE_LL, (HOOKPROC) MouseHookProc, GetModuleHandle(NULL), 0);

	MSG msg;

	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int) msg.wParam;
}

void StartHookThread()
{
	DWORD dwThrdParam = 1;
	m_hHookThread = CreateThread(NULL, 0, HookThread, &dwThrdParam, 0, &m_tidHook);
}

void KillHookThread()
{
	PostThreadMessage(m_tidHook, WM_QUIT, 0, 0);

	if(m_hHookThread != NULL)
	{
		CloseHandle(m_hHookThread);
		m_hHookThread = NULL;
	}

	UnhookWindowsHookEx(m_hKeyboardHook);
	UnhookWindowsHookEx(m_hMouseHook);
}
