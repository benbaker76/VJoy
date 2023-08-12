// Install.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

static BOOL IsOS64Bit(void);
static void PrintLastError(const WCHAR* apiname);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{

    STARTUPINFO         StartupInfo;
	PROCESS_INFORMATION ProcessInformation;
	TCHAR *AppPath = IsOS64Bit() ? TEXT("amd64\\") : TEXT("i386\\");
	TCHAR command[MAX_PATH] = { 0 };

	StringCchCopy(command, sizeof(command) / sizeof(TCHAR), AppPath);
	StringCchCat(command, sizeof(command) / sizeof(lpCmdLine), lpCmdLine);

	ZeroMemory(&ProcessInformation, sizeof(ProcessInformation));
	ZeroMemory(&StartupInfo, sizeof(StartupInfo));
	StartupInfo.cb = sizeof(STARTUPINFO);

	CreateProcess(NULL, command, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &StartupInfo, &ProcessInformation);

	if(ProcessInformation.hProcess)
	{
		DWORD Ret = WaitForSingleObject(ProcessInformation.hProcess, INFINITE); 

		CloseHandle(ProcessInformation.hProcess);
		CloseHandle(ProcessInformation.hThread);
	}

	return 0;
}

typedef UINT (WINAPI* GETSYSTEMWOW64DIRECTORY)(LPTSTR, UINT);
BOOL IsOS64Bit(void)
{
#ifdef _WIN64
    return TRUE;

#else
    GETSYSTEMWOW64DIRECTORY getSystemWow64Directory;
    HMODULE hKernel32;
    TCHAR Wow64Directory[MAX_PATH];

    hKernel32 = GetModuleHandle(TEXT("kernel32.dll"));

    if (hKernel32 == NULL)
	{
        //
        // This shouldn't happen, but if we can't get 
        // kernel32's module handle then assume we are 
        // on x86. We won't ever install 32-bit drivers
        // on 64-bit machines, we just want to catch it 
        // up front to give users a better error message.
        //
        return FALSE;
    }

    getSystemWow64Directory = (GETSYSTEMWOW64DIRECTORY) GetProcAddress(hKernel32, "GetSystemWow64DirectoryW");

    if (getSystemWow64Directory == NULL)
	{
        //
        // This most likely means we are running 
        // on Windows 2000, which didn't have this API 
        // and didn't have a 64-bit counterpart.
        //
        return FALSE;
    }

    if ((getSystemWow64Directory(Wow64Directory, sizeof(Wow64Directory)/sizeof(TCHAR)) == 0) && (GetLastError() == ERROR_CALL_NOT_IMPLEMENTED))
	{
        return FALSE;
    }
    
    //
    // GetSystemWow64Directory succeeded 
    // so we are on a 64-bit OS.
    //
    return TRUE;
#endif
}
