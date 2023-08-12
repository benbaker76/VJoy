#include "stdafx.h"
#include "InterComm.h"

#define INTERCOMM_WINDOWNAME	"VJoy_InterComm"
#define INTERCOMM_SERVERNAME	"VJoy_Server"
#define INTERCOMM_CLIENTNAME	"VJoy_Client"
#define INTERCOMM_MUTEXNAME		"VJoy_Mutex"

CInterComm::CInterComm()
{
	m_szWindowName = INTERCOMM_WINDOWNAME;
	m_szClassName = INTERCOMM_SERVERNAME;
	m_interCommMode = MODE_SERVER;
	m_hMutex = OpenMutex(MUTEX_ALL_ACCESS, 0, INTERCOMM_MUTEXNAME);
	m_MessageReceived = NULL;
}

CInterComm::~CInterComm()
{
	Shutdown();
}

BOOL CInterComm::Initialize(HINSTANCE hInstance, MessageReceivedDelegate MessageReceived)
{
	m_hInstance = hInstance;
	m_MessageReceived = MessageReceived;

	if (!IsFirstInstance())
	{
		m_interCommMode = MODE_CLIENT;
		m_szClassName = INTERCOMM_CLIENTNAME;
	}

	m_hThread = CreateThread(NULL, 0, CInterComm::NewThread, this, 0, &m_tid);
	
	if(m_hThread != NULL)
		return TRUE;

	return FALSE;
}

VOID CInterComm::Shutdown()
{
	PostThreadMessage(m_tid, WM_QUIT, NULL, NULL);
	::SendMessage(m_hWnd, WM_CLOSE, 0, 0);

	if(m_hThread != NULL)
	{
		CloseHandle(m_hThread);
		m_hThread = NULL;
	}

    if (m_hMutex != NULL)
    {
        ReleaseMutex(m_hMutex);
        m_hMutex = NULL;
    }
}

DWORD WINAPI CInterComm::CreateInterCommWindow(HINSTANCE hInstance)
{
	DWORD retVal = 0;

	WNDCLASS wc = { 0 };
	wc.lpszClassName = m_szClassName;
	wc.hInstance   = hInstance;
	wc.lpfnWndProc = CInterComm::StaticWndProc;

	if(!RegisterClass(&wc))
		goto error;

	m_hWnd = CreateWindowEx(
		0,
		m_szClassName,
		m_szWindowName,
		WS_OVERLAPPEDWINDOW,
		0, 0,
		1, 1,
		NULL,
		NULL,
		hInstance,
		this);

	if(m_hWnd == NULL)
		goto error;

	MSG msg;

	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	retVal = (int) msg.wParam;

error:

	DestroyWindow(m_hWnd);
	UnregisterClass(m_szClassName, hInstance); 

	return retVal;
}

LRESULT CALLBACK CInterComm::StaticWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	CInterComm* pParent;

	// Get pointer to window
	if(uMsg == WM_CREATE)
	{
		pParent = (CInterComm*) ((LPCREATESTRUCT)lParam)->lpCreateParams;
		SetWindowLongPtr(hWnd, GWLP_USERDATA,(LONG_PTR) pParent);
	}
	else
	{
		pParent = (CInterComm*) GetWindowLongPtr(hWnd, GWLP_USERDATA);

		if(!pParent)
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	pParent->m_hWnd = hWnd;

	return pParent->WndProc(hWnd, uMsg, wParam, lParam);
}

BOOL CInterComm::IsFirstInstance()
{
	if (!m_hMutex)
	{
		m_hMutex = CreateMutex(0, 0, INTERCOMM_MUTEXNAME);

		return TRUE;
	}

	return FALSE;
}

HWND CInterComm::GetTargethWnd()
{
    switch (m_interCommMode)
    {
        case MODE_SERVER:
            return FindWindow(INTERCOMM_CLIENTNAME, m_szWindowName);
        case MODE_CLIENT:
            return FindWindow(INTERCOMM_SERVERNAME, m_szWindowName);
    }

    return NULL;
}

BOOL CInterComm::SendMessage(INT id, PCHAR str)
{
	HWND hWnd = GetTargethWnd();

	if (hWnd == NULL)
		return FALSE;

	COPYDATASTRUCT cds;

	cds.cbData = strlen(str) + 1;
	cds.lpData = str;
	cds.dwData = 0;

	::SendMessage(hWnd, WM_COPYDATA, (WPARAM) id, (LPARAM) &cds);

	return TRUE;
}

LRESULT CALLBACK CInterComm::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_COPYDATA:
			PCOPYDATASTRUCT cds = (PCOPYDATASTRUCT) lParam;

            if (m_MessageReceived != NULL)
                m_MessageReceived((DataMode) wParam, (PCHAR) cds->lpData);
            break;
    }

    return DefWindowProc(hWnd, msg, wParam, lParam);
}
