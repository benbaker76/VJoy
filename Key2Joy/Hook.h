LRESULT CALLBACK KeyboardHookProc(INT, WPARAM, LPARAM);
LRESULT CALLBACK MouseHookProc(INT, WPARAM, LPARAM);
DWORD WINAPI HookThread(LPVOID lpParam);
void StartHookThread();
void KillHookThread();
