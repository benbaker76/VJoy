enum InterCommMode
{
	MODE_SERVER,
	MODE_CLIENT
};

enum DataMode
{
	MODE_CMDLINE
};

typedef int (__stdcall *MessageReceivedDelegate)(DataMode id, PCHAR data);

class CInterComm
{
public:
	CInterComm();
	virtual ~CInterComm();

	static DWORD _stdcall NewThread(LPVOID lpParam)
	{
		CInterComm* pInterComm = (CInterComm*) lpParam;
		return pInterComm->CreateInterCommWindow(pInterComm->m_hInstance);
	}

	BOOL Initialize(HINSTANCE hInstance, MessageReceivedDelegate MessageReceived);
	VOID Shutdown();
	DWORD WINAPI CreateInterCommWindow(HINSTANCE hInstance);
	BOOL IsFirstInstance();
	HWND GetTargethWnd();
	BOOL SendMessage(INT id, PCHAR str);
	static LRESULT CALLBACK StaticWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	InterCommMode CommMode() const { return m_interCommMode; }

private:
	HINSTANCE m_hInstance;
	HANDLE m_hThread;
	DWORD m_tid;
	HWND m_hWnd;
	HANDLE m_hMutex;
	MessageReceivedDelegate m_MessageReceived;

	PCHAR m_szWindowName;
	PCHAR m_szClassName;

	InterCommMode m_interCommMode;
};
