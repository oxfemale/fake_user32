/*
User regedit.exe for add user32.dll in to
HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager 
in to: ExcludeFromKnownDlls
Put user32.dll to .exe directory

Fake user32.dll duplicate
sample of MessageBoxA fake api (one of hook api method )
*/

#include <windows.h>

typedef int (cdecl *msgbox)(HWND, LPCSTR, LPCSTR, UINT);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	
		
		HMODULE hModule = LoadLibraryA("User32.dll");
		msgbox OrigMessageBoxA = 0;
		DWORD err = 0;
    if(hModule != 0)
    { 
        OrigMessageBoxA = (msgbox)GetProcAddress(hModule, "MessageBoxA");

		err = GetLastError();
		if(OrigMessageBoxA != 0){
			OrigMessageBoxA(0,"Test wrapper","Test Wrapper",0);
		
		}
	}
	return 0;
}

