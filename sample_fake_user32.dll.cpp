
// !!!!!!!!!! Still in research, will update time from time !!!!!!!!!!!

/*
User regedit.exe for add user32.dll in to
HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager 
in to: ExcludeFromKnownDlls
Put user32.dll to .exe directory

Fake user32.dll duplicate
sample of MessageBoxA fake api (one of hook api method )


*/
// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <windows.h>
#include <stdio.h>


  typedef struct _LPK_LPEDITCONTROL_LIST
{
    PVOID EditCreate;
    PVOID EditIchToXY;
    PVOID EditMouseToIch;
    PVOID EditCchInWidth;
    PVOID EditGetLineWidth;
    PVOID EditDrawText;
    PVOID EditHScroll;
    PVOID EditMoveSelection;
    PVOID EditVerifyText;
    PVOID EditNextWord;
    PVOID EditSetMenu;
    PVOID EditProcessMenu;
    PVOID EditCreateCaret;
    PVOID EditAdjustCaret;
} LPK_LPEDITCONTROL_LIST, *PLPK_LPEDITCONTROL_LIST;

typedef struct _USER32_INTERN_INITIALIZEHOOKS
{
	PVOID fpLpkTabbedTextOut;
	PVOID fpLpkPSMTextOut;
	PVOID fpLpkDrawTextEx;
	PLPK_LPEDITCONTROL_LIST fpListLpkEditControl;
} USER32_INTERN_INITIALIZEHOOKS, *PUSER32_INTERN_INITIALIZEHOOKS;

extern "C" __declspec(dllexport) HWND cdecl WindowFromPoint( POINT Point );
__declspec(dllexport) HWND cdecl WindowFromPoint( POINT Point ){
	typedef HWND (__stdcall *WindowFromPoint_z)(POINT);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	WindowFromPoint_z OrigWindowFromPoint = 0;
    if(hModule != 0)
    {
        OrigWindowFromPoint = (WindowFromPoint_z)GetProcAddress(hModule, "WindowFromPoint");
		if (OrigWindowFromPoint != 0) {
			return OrigWindowFromPoint(Point);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) int cdecl SetWindowRgn(HWND hWnd,HRGN hRgn,BOOL bRedraw);
__declspec(dllexport) int cdecl SetWindowRgn(HWND hWnd,HRGN hRgn,BOOL bRedraw){
	typedef int (__stdcall *SetWindowRgn_z)(HWND, HRGN, BOOL);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	SetWindowRgn_z OrigSetWindowRgn = 0;
    if(hModule != 0)
    {
        OrigSetWindowRgn = (SetWindowRgn_z)GetProcAddress(hModule, "SetWindowRgn");
		if (OrigSetWindowRgn != 0) {
			return OrigSetWindowRgn(hWnd, hRgn, bRedraw);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) HCURSOR cdecl GetCursor(void);
__declspec(dllexport) HCURSOR cdecl GetCursor(void){
	typedef HCURSOR (__stdcall *GetCursor_z)(void);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetCursor_z OrigGetCursor = 0;
    if(hModule != 0)
    {
        OrigGetCursor = (GetCursor_z)GetProcAddress(hModule, "GetCursor");
		if (OrigGetCursor != 0) {
			return OrigGetCursor();
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl SetLayeredWindowAttributes(HWND hwnd,COLORREF crKey,BYTE bAlpha,DWORD dwFlags);
__declspec(dllexport) BOOL cdecl SetLayeredWindowAttributes(HWND hwnd,COLORREF crKey,BYTE bAlpha,DWORD dwFlags){
	typedef BOOL (__stdcall *SetLayeredWindowAttributes_z)( HWND, COLORREF, BYTE, DWORD );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	SetLayeredWindowAttributes_z OrigSetLayeredWindowAttributes = 0;
    if(hModule != 0)
    {
        OrigSetLayeredWindowAttributes = (SetLayeredWindowAttributes_z)GetProcAddress(hModule, "SetLayeredWindowAttributes");
		if (OrigSetLayeredWindowAttributes != 0) {
			return OrigSetLayeredWindowAttributes( hwnd, crKey, bAlpha, dwFlags );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl SetRectEmpty(LPRECT lprc);
__declspec(dllexport) BOOL cdecl SetRectEmpty(LPRECT lprc){
	typedef BOOL (__stdcall *SetRectEmpty_z)( LPRECT);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	SetRectEmpty_z OrigSetRectEmpty = 0;
    if(hModule != 0)
    {
        OrigSetRectEmpty = (SetRectEmpty_z)GetProcAddress(hModule, "SetRectEmpty");
		if (OrigSetRectEmpty != 0) {
			return OrigSetRectEmpty(lprc );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) UINT cdecl GetCaretBlinkTime(void);
__declspec(dllexport) UINT cdecl GetCaretBlinkTime(void){
	typedef BOOL (__stdcall *GetCaretBlinkTime_z)( void);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetCaretBlinkTime_z OrigGetCaretBlinkTime = 0;
    if(hModule != 0)
    {
        OrigGetCaretBlinkTime = (GetCaretBlinkTime_z)GetProcAddress(hModule, "GetCaretBlinkTime");
		if (OrigGetCaretBlinkTime != 0) {
			return OrigGetCaretBlinkTime( );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl EqualRect(const RECT *lprc1,const RECT *lprc2);
__declspec(dllexport) BOOL cdecl EqualRect(const RECT *lprc1,const RECT *lprc2){
	typedef BOOL (__stdcall *EqualRect_z)( const RECT , const RECT);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	EqualRect_z OrigEqualRect = 0;
    if(hModule != 0)
    {
        OrigEqualRect = (EqualRect_z)GetProcAddress(hModule, "EqualRect");
		if (OrigEqualRect != 0) {
			return OrigEqualRect( *lprc1, *lprc2 );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl IsRectEmpty( const RECT *lprc);
__declspec(dllexport) BOOL cdecl IsRectEmpty( const RECT *lprc){
	typedef BOOL (__stdcall *IsRectEmpty_z)( const RECT );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	IsRectEmpty_z OrigIsRectEmpty = 0;
    if(hModule != 0)
    {
        OrigIsRectEmpty = (IsRectEmpty_z)GetProcAddress(hModule, "IsRectEmpty");
		if (OrigIsRectEmpty != 0) {
			return OrigIsRectEmpty( *lprc );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl SetPropA(HWND hWnd, LPCSTR lpString, HANDLE hData);
__declspec(dllexport) BOOL cdecl SetPropA(HWND hWnd, LPCSTR lpString, HANDLE hData){
	typedef BOOL (__stdcall *SetPropA_z)( HWND, LPCSTR, HANDLE );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	SetPropA_z OrigSetPropA = 0;
    if(hModule != 0)
    {
        OrigSetPropA = (SetPropA_z)GetProcAddress(hModule, "SetPropA");
		if (OrigSetPropA != 0) {
			return OrigSetPropA( hWnd, lpString, hData );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl SetPropW(HWND hWnd, LPCWSTR lpString, HANDLE hData);
__declspec(dllexport) BOOL cdecl SetPropW(HWND hWnd, LPCWSTR lpString, HANDLE hData){
	typedef BOOL (__stdcall *SetPropW_z)( HWND, LPCWSTR, HANDLE );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	SetPropW_z OrigSetPropW = 0;
    if(hModule != 0)
    {
        OrigSetPropW = (SetPropW_z)GetProcAddress(hModule, "SetPropW");
		if (OrigSetPropW != 0) {
			return OrigSetPropW( hWnd, lpString, hData );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl MoveWindow( HWND hWnd,int X,int Y,int nWidth,int nHeight,BOOL bRepaint);
__declspec(dllexport) BOOL cdecl MoveWindow( HWND hWnd,int X,int Y,int nWidth,int nHeight,BOOL bRepaint){
	typedef BOOL (__stdcall *MoveWindow_z)( HWND, int, int, int, int, BOOL );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	MoveWindow_z OrigMoveWindow = 0;
    if(hModule != 0)
    {
        OrigMoveWindow = (MoveWindow_z)GetProcAddress(hModule, "MoveWindow");
		if (OrigMoveWindow != 0) {
			return OrigMoveWindow( hWnd, X, Y, nWidth, nHeight, bRepaint );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HANDLE cdecl RemovePropA(HWND hWnd,LPCSTR lpString);
__declspec(dllexport) HANDLE cdecl RemovePropA(HWND hWnd,LPCSTR lpString){
	typedef HANDLE (__stdcall *RemovePropA_z)( HWND, LPCSTR );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	RemovePropA_z OrigRemovePropA = 0;
    if(hModule != 0)
    {
        OrigRemovePropA = (RemovePropA_z)GetProcAddress(hModule, "RemovePropA");
		if (OrigRemovePropA != 0) {
			return OrigRemovePropA( hWnd, lpString );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HANDLE cdecl RemovePropW(HWND hWnd,LPCWSTR lpString);
__declspec(dllexport) HANDLE cdecl RemovePropW(HWND hWnd,LPCWSTR lpString){
	typedef HANDLE (__stdcall *RemovePropW_z)( HWND, LPCWSTR );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	RemovePropW_z OrigRemovePropW = 0;
    if(hModule != 0)
    {
        OrigRemovePropW = (RemovePropW_z)GetProcAddress(hModule, "RemovePropW");
		if (OrigRemovePropW != 0) {
			return OrigRemovePropW( hWnd, lpString );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl PtInRect( const RECT *lprc,POINT pt);
__declspec(dllexport) BOOL cdecl PtInRect( const RECT *lprc, POINT pt){
	typedef BOOL (__stdcall *PtInRect_z)( const RECT, POINT );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	PtInRect_z OrigPtInRect = 0;
    if(hModule != 0)
    {
        OrigPtInRect = (PtInRect_z)GetProcAddress(hModule, "PtInRect");
		if (OrigPtInRect != 0) {
			return OrigPtInRect( *lprc, pt );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl UnregisterClassA(LPCSTR lpClassName,HINSTANCE hInstance);
__declspec(dllexport) BOOL cdecl UnregisterClassA(LPCSTR lpClassName,HINSTANCE hInstance){
	typedef BOOL (__stdcall *UnregisterClassA_z)( LPCSTR, HINSTANCE );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	UnregisterClassA_z OrigUnregisterClassA = 0;
    if(hModule != 0)
    {
        OrigUnregisterClassA = (UnregisterClassA_z)GetProcAddress(hModule, "UnregisterClassA");
		if (OrigUnregisterClassA != 0) {
			return OrigUnregisterClassA( lpClassName, hInstance );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl UnregisterClassW(LPCWSTR lpClassName,HINSTANCE hInstance);
__declspec(dllexport) BOOL cdecl UnregisterClassW(LPCWSTR lpClassName,HINSTANCE hInstance){
	typedef BOOL (__stdcall *UnregisterClassW_z)( LPCWSTR, HINSTANCE );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	UnregisterClassW_z OrigUnregisterClassW = 0;
    if(hModule != 0)
    {
        OrigUnregisterClassW = (UnregisterClassW_z)GetProcAddress(hModule, "UnregisterClassW");
		if (OrigUnregisterClassW != 0) {
			return OrigUnregisterClassW( lpClassName, hInstance );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl OffsetRect(LPRECT lprc,int dx,int dy);
__declspec(dllexport) BOOL cdecl OffsetRect(LPRECT lprc,int dx,int dy){
	typedef BOOL (__stdcall *OffsetRect_z)( LPRECT, int, int );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	OffsetRect_z OrigOffsetRect = 0;
    if(hModule != 0)
    {
        OrigOffsetRect = (OffsetRect_z)GetProcAddress(hModule, "OffsetRect");
		if (OrigOffsetRect != 0) {
			return OrigOffsetRect( lprc, dx, dy);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) int cdecl FrameRect(HDC hDC,const RECT *lprc,HBRUSH hbr);
__declspec(dllexport) int cdecl FrameRect(HDC hDC,const RECT *lprc,HBRUSH hbr){
	typedef int (__stdcall *FrameRect_z)( HDC,const RECT, HBRUSH   );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	FrameRect_z OrigFrameRect = 0;
    if(hModule != 0)
    {
        OrigFrameRect = (FrameRect_z)GetProcAddress(hModule, "FrameRect");
		if (OrigFrameRect != 0) {
			return OrigFrameRect( hDC, *lprc, hbr);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl DrawIconEx(HDC hdc,int xLeft,int yTop,HICON hIcon,int cxWidth,int cyWidth,UINT istepIfAniCur,HBRUSH hbrFlickerFreeDraw,UINT diFlags);
__declspec(dllexport) BOOL cdecl DrawIconEx(HDC hdc,int xLeft,int yTop,HICON hIcon,int cxWidth,int cyWidth,UINT istepIfAniCur,HBRUSH hbrFlickerFreeDraw,UINT diFlags){
	typedef BOOL (__stdcall *DrawIconEx_z)( HDC, int, int, HICON, int, int, UINT, HBRUSH, UINT );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	DrawIconEx_z OrigDrawIconEx = 0;
    if(hModule != 0)
    {
        OrigDrawIconEx = (DrawIconEx_z)GetProcAddress(hModule, "DrawIconEx");
		if (OrigDrawIconEx != 0) {
			return OrigDrawIconEx( hdc, xLeft, yTop, hIcon, cxWidth, cyWidth, istepIfAniCur, hbrFlickerFreeDraw, diFlags );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl DrawStateA( HDC hdc, HBRUSH hbrFore, DRAWSTATEPROC qfnCallBack, LPARAM lData, WPARAM wData, int x, int y, int cx, int cy, UINT uFlags);
__declspec(dllexport) BOOL cdecl DrawStateA( HDC hdc, HBRUSH hbrFore, DRAWSTATEPROC qfnCallBack, LPARAM lData, WPARAM wData, int x, int y, int cx, int cy, UINT uFlags){
	typedef BOOL (__stdcall *DrawStateA_z)( HDC, HBRUSH, DRAWSTATEPROC, LPARAM, WPARAM, int, int, int, int, UINT );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	DrawStateA_z OrigDrawStateA = 0;
    if(hModule != 0)
    {
        OrigDrawStateA = (DrawStateA_z)GetProcAddress(hModule, "DrawStateA");
		if (OrigDrawStateA != 0) {
			return OrigDrawStateA( hdc, hbrFore, qfnCallBack, lData, wData, x, y, cx, cy, uFlags );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl DrawStateW( HDC hdc, HBRUSH hbrFore, DRAWSTATEPROC qfnCallBack, LPARAM lData, WPARAM wData, int x, int y, int cx, int cy, UINT uFlags);
__declspec(dllexport) BOOL cdecl DrawStateW( HDC hdc, HBRUSH hbrFore, DRAWSTATEPROC qfnCallBack, LPARAM lData, WPARAM wData, int x, int y, int cx, int cy, UINT uFlags){
	typedef BOOL (__stdcall *DrawStateW_z)( HDC, HBRUSH, DRAWSTATEPROC, LPARAM, WPARAM, int, int, int, int, UINT );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	DrawStateW_z OrigDrawStateW = 0;
    if(hModule != 0)
    {
        OrigDrawStateW = (DrawStateW_z)GetProcAddress(hModule, "DrawStateW");
		if (OrigDrawStateW != 0) {
			return OrigDrawStateW( hdc, hbrFore, qfnCallBack, lData, wData, x, y, cx, cy, uFlags );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) int cdecl FillRect(HDC hDC,const RECT *lprc,HBRUSH hbr);
__declspec(dllexport) int cdecl FillRect(HDC hDC,const RECT *lprc,HBRUSH hbr){
	typedef int (__stdcall *FillRect_z)( HDC, const RECT, HBRUSH );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	FillRect_z OrigFillRect = 0;
    if(hModule != 0)
    {
        OrigFillRect = (FillRect_z)GetProcAddress(hModule, "FillRect");
		if (OrigFillRect != 0) {
			return OrigFillRect( hDC, *lprc, hbr );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl AnimateWindow(HWND hwnd,DWORD dwTime,DWORD dwFlags);
__declspec(dllexport) BOOL cdecl AnimateWindow(HWND hwnd,DWORD dwTime,DWORD dwFlags){
	typedef BOOL (__stdcall *AnimateWindow_z)( HWND, DWORD, DWORD );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	AnimateWindow_z OrigAnimateWindow = 0;
    if(hModule != 0)
    {
        OrigAnimateWindow = (AnimateWindow_z)GetProcAddress(hModule, "AnimateWindow");
		if (OrigAnimateWindow != 0) {
			return OrigAnimateWindow( hwnd, dwTime, dwFlags );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HMONITOR cdecl MonitorFromPoint(POINT pt,DWORD dwFlags);
__declspec(dllexport) HMONITOR cdecl MonitorFromPoint(POINT pt,DWORD dwFlags){
	typedef HMONITOR (__stdcall *MonitorFromPoint_z)( POINT, DWORD );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	MonitorFromPoint_z OrigMonitorFromPoint = 0;
    if(hModule != 0)
    {
        OrigMonitorFromPoint = (MonitorFromPoint_z)GetProcAddress(hModule, "MonitorFromPoint");
		if (OrigMonitorFromPoint != 0) {
			return OrigMonitorFromPoint( pt, dwFlags);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HMONITOR cdecl MonitorFromRect(LPCRECT lprc,DWORD   dwFlags);
__declspec(dllexport) HMONITOR cdecl MonitorFromRect(LPCRECT lprc,DWORD   dwFlags){
	typedef HMONITOR (__stdcall *MonitorFromRect_z)( LPCRECT, DWORD );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	MonitorFromRect_z OrigMonitorFromRect = 0;
    if(hModule != 0)
    {
        OrigMonitorFromRect = (MonitorFromRect_z)GetProcAddress(hModule, "MonitorFromRect");
		if (OrigMonitorFromRect != 0) {
			return OrigMonitorFromRect( lprc, dwFlags);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl UpdateLayeredWindow(HWND hwnd,HDC hdcDst,POINT *pptDst,SIZE *psize,HDC hdcSrc,POINT *pptSrc,COLORREF crKey,BLENDFUNCTION *pblend,DWORD dwFlags);
__declspec(dllexport) BOOL cdecl UpdateLayeredWindow(HWND hwnd,HDC hdcDst,POINT *pptDst,SIZE *psize,HDC hdcSrc,POINT *pptSrc,COLORREF crKey,BLENDFUNCTION *pblend,DWORD dwFlags){
	typedef BOOL (__stdcall *UpdateLayeredWindow_z)( HWND,HDC, POINT, SIZE, HDC, POINT, COLORREF, BLENDFUNCTION, DWORD );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	UpdateLayeredWindow_z OrigUpdateLayeredWindow = 0;
    if(hModule != 0)
    {
        OrigUpdateLayeredWindow = (UpdateLayeredWindow_z)GetProcAddress(hModule, "UpdateLayeredWindow");
		if (OrigUpdateLayeredWindow != 0) {
			return OrigUpdateLayeredWindow( hwnd, hdcDst, *pptDst, *psize, hdcSrc, *pptSrc, crKey, *pblend, dwFlags);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) UINT cdecl GetDoubleClickTime(void);
__declspec(dllexport) UINT cdecl GetDoubleClickTime(void){
	typedef BOOL (__stdcall *GetDoubleClickTime_z)( void );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetDoubleClickTime_z OrigGetDoubleClickTime = 0;
    if(hModule != 0)
    {
        OrigGetDoubleClickTime = (GetDoubleClickTime_z)GetProcAddress(hModule, "GetUserObjectInformationA");
		if (OrigGetDoubleClickTime != 0) {
			return OrigGetDoubleClickTime(  );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl GetUserObjectInformationA(HANDLE hObj,int nIndex,PVOID pvInfo,DWORD nLength,LPDWORD lpnLengthNeeded);
__declspec(dllexport) BOOL cdecl GetUserObjectInformationA(HANDLE hObj,int nIndex,PVOID pvInfo,DWORD nLength,LPDWORD lpnLengthNeeded){
	typedef BOOL (__stdcall *GetUserObjectInformationA_z)( HANDLE, int, PVOID, DWORD, LPDWORD );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetUserObjectInformationA_z OrigGetUserObjectInformationA = 0;
    if(hModule != 0)
    {
        OrigGetUserObjectInformationA = (GetUserObjectInformationA_z)GetProcAddress(hModule, "GetUserObjectInformationA");
		if (OrigGetUserObjectInformationA != 0) {
			return OrigGetUserObjectInformationA( hObj, nIndex, pvInfo, nLength,lpnLengthNeeded );
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) BOOL cdecl GetUserObjectInformationW(HANDLE hObj,int nIndex,PVOID pvInfo,DWORD nLength,LPDWORD lpnLengthNeeded);
__declspec(dllexport) BOOL cdecl GetUserObjectInformationW(HANDLE hObj,int nIndex,PVOID pvInfo,DWORD nLength,LPDWORD lpnLengthNeeded){
	typedef BOOL (__stdcall *GetUserObjectInformationW_z)( HANDLE, int, PVOID, DWORD, LPDWORD );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetUserObjectInformationW_z OrigGetUserObjectInformationW = 0;
    if(hModule != 0)
    {
        OrigGetUserObjectInformationW = (GetUserObjectInformationW_z)GetProcAddress(hModule, "GetUserObjectInformationW");
		if (OrigGetUserObjectInformationW != 0) {
			return OrigGetUserObjectInformationW( hObj, nIndex, pvInfo, nLength,lpnLengthNeeded );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) DWORD cdecl GetMessagePos(void);
__declspec(dllexport) DWORD cdecl GetMessagePos(void){
	typedef DWORD (__stdcall *GetMessagePos_z)( void );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetMessagePos_z OrigGetMessagePos = 0;
    if(hModule != 0)
    {
        OrigGetMessagePos = (GetMessagePos_z)GetProcAddress(hModule, "GetMessagePos");
		if (OrigGetMessagePos != 0) {
			return OrigGetMessagePos(  );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) int cdecl LoadStringA( HINSTANCE hInstance, UINT uID, LPSTR lpBuffer, int cchBufferMax);
__declspec(dllexport) int cdecl LoadStringA( HINSTANCE hInstance, UINT uID, LPSTR lpBuffer, int cchBufferMax){
	typedef int (__stdcall *LoadStringA_z)( HINSTANCE, UINT, LPSTR, int );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	LoadStringA_z OrigLoadStringA = 0;
    if(hModule != 0)
    {
        OrigLoadStringA = (LoadStringA_z)GetProcAddress(hModule, "LoadStringA");
		if (OrigLoadStringA != 0) {
			return OrigLoadStringA( hInstance, uID, lpBuffer, cchBufferMax );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) int cdecl LoadStringW( HINSTANCE hInstance, UINT uID, LPWSTR lpBuffer, int cchBufferMax);
__declspec(dllexport) int cdecl LoadStringW( HINSTANCE hInstance, UINT uID, LPWSTR lpBuffer, int cchBufferMax){
	typedef int (__stdcall *LoadStringW_z)( HINSTANCE, UINT, LPWSTR, int );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	LoadStringW_z OrigLoadStringW = 0;
    if(hModule != 0)
    {
        OrigLoadStringW = (LoadStringW_z)GetProcAddress(hModule, "LoadStringW");
		if (OrigLoadStringW != 0) {
			return OrigLoadStringW( hInstance, uID, lpBuffer, cchBufferMax );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) UINT_PTR cdecl SetTimer(HWND hWnd,UINT_PTR nIDEvent,UINT uElapse,TIMERPROC lpTimerFunc);
__declspec(dllexport) UINT_PTR cdecl SetTimer(HWND hWnd,UINT_PTR nIDEvent,UINT uElapse,TIMERPROC lpTimerFunc){
	typedef UINT_PTR (__stdcall *SetTimer_z)( HWND, UINT_PTR, UINT, TIMERPROC );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	SetTimer_z OrigSetTimer = 0;
    if(hModule != 0)
    {
        OrigSetTimer = (SetTimer_z)GetProcAddress(hModule, "SetTimer");
		if (OrigSetTimer != 0) {
			return OrigSetTimer( hWnd, nIDEvent, uElapse, lpTimerFunc );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl ChangeWindowMessageFilter(UINT message,DWORD dwFlag);
__declspec(dllexport) BOOL cdecl ChangeWindowMessageFilter(UINT message,DWORD dwFlag){
	typedef BOOL (__stdcall *ChangeWindowMessageFilter_z)( UINT, DWORD );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	ChangeWindowMessageFilter_z OrigChangeWindowMessageFilter = 0;
    if(hModule != 0)
    {
        OrigChangeWindowMessageFilter = (ChangeWindowMessageFilter_z)GetProcAddress(hModule, "ChangeWindowMessageFilter");
		if (OrigChangeWindowMessageFilter != 0) {
			return OrigChangeWindowMessageFilter( message, dwFlag );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) UINT cdecl RegisterWindowMessageA(LPCSTR lpString);
__declspec(dllexport) UINT cdecl RegisterWindowMessageA(LPCSTR lpString){
	typedef UINT (__stdcall *RegisterWindowMessageA_z)( LPCSTR );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	RegisterWindowMessageA_z OrigRegisterWindowMessageA = 0;
    if(hModule != 0)
    {
        OrigRegisterWindowMessageA = (RegisterWindowMessageA_z)GetProcAddress(hModule, "RegisterWindowMessageA");
		if (OrigRegisterWindowMessageA != 0) {
			return OrigRegisterWindowMessageA( lpString );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) UINT cdecl RegisterWindowMessageW(LPCWSTR lpString);
__declspec(dllexport) UINT cdecl RegisterWindowMessageW(LPCWSTR lpString){
	typedef UINT (__stdcall *RegisterWindowMessageW_z)( LPCWSTR );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	RegisterWindowMessageW_z OrigRegisterWindowMessageW = 0;
    if(hModule != 0)
    {
        OrigRegisterWindowMessageW = (RegisterWindowMessageW_z)GetProcAddress(hModule, "RegisterWindowMessageW");
		if (OrigRegisterWindowMessageW != 0) {
			return OrigRegisterWindowMessageW( lpString );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl PostThreadMessageA(DWORD idThread,UINT Msg,WPARAM wParam,LPARAM lParam);
__declspec(dllexport) BOOL cdecl PostThreadMessageA(DWORD idThread,UINT Msg,WPARAM wParam,LPARAM lParam){
	typedef BOOL (__stdcall *PostThreadMessageA_z)( DWORD, UINT, WPARAM, LPARAM );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	PostThreadMessageA_z OrigPostThreadMessageA = 0;
    if(hModule != 0)
    {
        OrigPostThreadMessageA = (PostThreadMessageA_z)GetProcAddress(hModule, "PostThreadMessageA");
		if (OrigPostThreadMessageA != 0) {
			return OrigPostThreadMessageA( idThread, Msg, wParam, lParam );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl PostThreadMessageW(DWORD idThread,UINT Msg,WPARAM wParam,LPARAM lParam);
__declspec(dllexport) BOOL cdecl PostThreadMessageW(DWORD idThread,UINT Msg,WPARAM wParam,LPARAM lParam){
	typedef BOOL (__stdcall *PostThreadMessageW_z)( DWORD, UINT, WPARAM, LPARAM );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	PostThreadMessageW_z OrigPostThreadMessageW = 0;
    if(hModule != 0)
    {
        OrigPostThreadMessageW = (PostThreadMessageW_z)GetProcAddress(hModule, "PostThreadMessageW");
		if (OrigPostThreadMessageW != 0) {
			return OrigPostThreadMessageW( idThread, Msg, wParam, lParam );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HWND cdecl FindWindowA(LPCSTR lpClassName,LPCSTR lpWindowName);
__declspec(dllexport) HWND cdecl FindWindowA(LPCSTR lpClassName,LPCSTR lpWindowName){
	typedef HWND (__stdcall *FindWindowA_z)( LPCSTR, LPCSTR );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	FindWindowA_z OrigFindWindowA = 0;
    if(hModule != 0)
    {
        OrigFindWindowA = (FindWindowA_z)GetProcAddress(hModule, "FindWindowA");
		if (OrigFindWindowA != 0) {
			return OrigFindWindowA( lpClassName, lpWindowName );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HWND cdecl FindWindowW(LPCWSTR lpClassName,LPCWSTR lpWindowName);
__declspec(dllexport) HWND cdecl FindWindowW(LPCWSTR lpClassName,LPCWSTR lpWindowName){
	typedef HWND (__stdcall *FindWindowW_z)( LPCWSTR, LPCWSTR );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	FindWindowW_z OrigFindWindowW = 0;
    if(hModule != 0)
    {
        OrigFindWindowW = (FindWindowW_z)GetProcAddress(hModule, "FindWindowW");
		if (OrigFindWindowW != 0) {
			return OrigFindWindowW( lpClassName, lpWindowName );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) DWORD cdecl GetQueueStatus(UINT flags);
__declspec(dllexport) DWORD cdecl GetQueueStatus(UINT flags){
	typedef DWORD (__stdcall *GetQueueStatus_z)( UINT );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetQueueStatus_z OrigGetQueueStatus = 0;
    if(hModule != 0)
    {
        OrigGetQueueStatus = (GetQueueStatus_z)GetProcAddress(hModule, "GetQueueStatus");
		if (OrigGetQueueStatus != 0) {
			return OrigGetQueueStatus( flags );
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) VOID cdecl PostQuitMessage(int nExitCode);
__declspec(dllexport) VOID cdecl PostQuitMessage(int nExitCode){
	typedef VOID (__stdcall *PostQuitMessage_z)( int );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	PostQuitMessage_z OrigPostQuitMessage = 0;
    if(hModule != 0)
    {
        OrigPostQuitMessage = (PostQuitMessage_z)GetProcAddress(hModule, "PostQuitMessage");
		if (OrigPostQuitMessage != 0) {
			return OrigPostQuitMessage( nExitCode );
		}
    }
	return;
}

extern "C" __declspec(dllexport) BOOL cdecl PeekMessageW(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax,UINT wRemoveMsg);
__declspec(dllexport) BOOL cdecl PeekMessageW(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax,UINT wRemoveMsg){
	typedef BOOL (__stdcall *PeekMessageW_z)( LPMSG, HWND, UINT, UINT, UINT );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	PeekMessageW_z OrigPeekMessageW = 0;
    if(hModule != 0)
    {
        OrigPeekMessageW = (PeekMessageW_z)GetProcAddress(hModule, "PeekMessageW");
		if (OrigPeekMessageW != 0) {
			return OrigPeekMessageW( lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg );
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) SHORT cdecl GetKeyState(int nVirtKey);
__declspec(dllexport) SHORT cdecl GetKeyState(int nVirtKey){
	typedef SHORT (__stdcall *GetKeyState_z)( int );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetKeyState_z OrigGetKeyState = 0;
    if(hModule != 0)
    {
        OrigGetKeyState = (GetKeyState_z)GetProcAddress(hModule, "GetKeyState");
		if (OrigGetKeyState != 0) {
			return OrigGetKeyState( nVirtKey );
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) BOOL cdecl IsWindowVisible(HWND hWnd);
__declspec(dllexport) BOOL cdecl IsWindowVisible(HWND hWnd){
	typedef BOOL (__stdcall *IsWindowVisible_z)( HWND );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	IsWindowVisible_z OrigIsWindowVisible = 0;
    if(hModule != 0)
    {
        OrigIsWindowVisible = (IsWindowVisible_z)GetProcAddress(hModule, "IsWindowVisible");
		if (OrigIsWindowVisible != 0) {
			return OrigIsWindowVisible( hWnd );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) DWORD cdecl GetClassLongW(HWND hWnd,int nIndex);
__declspec(dllexport) DWORD cdecl GetClassLongW(HWND hWnd,int nIndex){
	typedef DWORD (__stdcall *GetClassLongW_z)( HWND, int );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetClassLongW_z OrigGetClassLongW = 0;
    if(hModule != 0)
    {
        OrigGetClassLongW = (GetClassLongW_z)GetProcAddress(hModule, "GetClassLongW");
		if (OrigGetClassLongW != 0) {
			return OrigGetClassLongW( hWnd, nIndex );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl EnumThreadWindows(DWORD dwThreadId,WNDENUMPROC lpfn,LPARAM lParam);
__declspec(dllexport) BOOL cdecl EnumThreadWindows(DWORD dwThreadId,WNDENUMPROC lpfn,LPARAM lParam){
	typedef BOOL (__stdcall *EnumThreadWindows_z)( DWORD,WNDENUMPROC, LPARAM );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	EnumThreadWindows_z OrigEnumThreadWindows = 0;
    if(hModule != 0)
    {
        OrigEnumThreadWindows = (EnumThreadWindows_z)GetProcAddress(hModule, "EnumThreadWindows");
		if (OrigEnumThreadWindows != 0) {
			return OrigEnumThreadWindows( dwThreadId, lpfn, lParam );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) DWORD cdecl InSendMessageEx( LPVOID lpReserved );
__declspec(dllexport) DWORD cdecl InSendMessageEx( LPVOID lpReserved ){
	typedef DWORD (__stdcall *InSendMessageEx_z)( LPVOID );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	InSendMessageEx_z OrigInSendMessageEx = 0;
    if(hModule != 0)
    {
        OrigInSendMessageEx = (InSendMessageEx_z)GetProcAddress(hModule, "InSendMessageEx");
		if (OrigInSendMessageEx != 0) {
			return OrigInSendMessageEx( lpReserved );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HKL cdecl ActivateKeyboardLayout(HKL hkl,UINT Flags);
__declspec(dllexport) HKL cdecl ActivateKeyboardLayout(HKL hkl,UINT Flags){
	typedef HKL (__stdcall *ActivateKeyboardLayout_z)( HKL, UINT );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	ActivateKeyboardLayout_z OrigActivateKeyboardLayout = 0;
    if(hModule != 0)
    {
        OrigActivateKeyboardLayout = (ActivateKeyboardLayout_z)GetProcAddress(hModule, "ActivateKeyboardLayout");
		if (OrigActivateKeyboardLayout != 0) {
			return OrigActivateKeyboardLayout( hkl, Flags );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl UnhookWinEvent(HWINEVENTHOOK hWinEventHook);
__declspec(dllexport) BOOL cdecl UnhookWinEvent(HWINEVENTHOOK hWinEventHook){
	typedef BOOL (__stdcall *UnhookWinEvent_z)( HWINEVENTHOOK );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	UnhookWinEvent_z OrigUnhookWinEvent = 0;
    if(hModule != 0)
    {
        OrigUnhookWinEvent = (UnhookWinEvent_z)GetProcAddress(hModule, "UnhookWinEvent");
		if (OrigUnhookWinEvent != 0) {
			return OrigUnhookWinEvent( hWinEventHook );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HDESK cdecl GetThreadDesktop(DWORD dwThreadId);
__declspec(dllexport) HDESK cdecl GetThreadDesktop(DWORD dwThreadId){
	typedef HDESK (__stdcall *GetThreadDesktop_z)( DWORD );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetThreadDesktop_z OrigGetThreadDesktop = 0;
    if(hModule != 0)
    {
        OrigGetThreadDesktop = (GetThreadDesktop_z)GetProcAddress(hModule, "GetThreadDesktop");
		if (OrigGetThreadDesktop != 0) {
			return OrigGetThreadDesktop( dwThreadId );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HWINSTA cdecl GetProcessWindowStation(void);
__declspec(dllexport) HWINSTA cdecl GetProcessWindowStation(void){
	typedef HWINSTA (__stdcall *GetProcessWindowStation_z)( void );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetProcessWindowStation_z OrigGetProcessWindowStation = 0;
    if(hModule != 0)
    {
        OrigGetProcessWindowStation = (GetProcessWindowStation_z)GetProcAddress(hModule, "GetProcessWindowStation");
		if (OrigGetProcessWindowStation != 0) {
			return OrigGetProcessWindowStation(  );
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) BOOL cdecl IsWindowInDestroy ( HWND hwnd );
__declspec(dllexport) BOOL cdecl IsWindowInDestroy ( HWND hwnd ){
	typedef BOOL (__stdcall *IsWindowInDestroy_z)( HWND );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	IsWindowInDestroy_z OrigIsWindowInDestroy = 0;
    if(hModule != 0)
    {
        OrigIsWindowInDestroy = (IsWindowInDestroy_z)GetProcAddress(hModule, "IsWindowInDestroy");
		if (OrigIsWindowInDestroy != 0) {
			return OrigIsWindowInDestroy( hwnd );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl AdjustWindowRectEx(LPRECT lpRect,DWORD dwStyle,BOOL bMenu,DWORD dwExStyle);
__declspec(dllexport) BOOL cdecl AdjustWindowRectEx(LPRECT lpRect,DWORD dwStyle,BOOL bMenu,DWORD dwExStyle){
	typedef BOOL (__stdcall *AdjustWindowRectEx_z)( LPRECT, DWORD, BOOL, DWORD );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	AdjustWindowRectEx_z OrigAdjustWindowRectEx = 0;
    if(hModule != 0)
    {
        OrigAdjustWindowRectEx = (AdjustWindowRectEx_z)GetProcAddress(hModule, "AdjustWindowRectEx");
		if (OrigAdjustWindowRectEx != 0) {
			return OrigAdjustWindowRectEx( lpRect, dwStyle, bMenu, dwExStyle);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl KillTimer(HWND hWnd,UINT_PTR uIDEvent);
__declspec(dllexport) BOOL cdecl KillTimer(HWND hWnd,UINT_PTR uIDEvent){
	typedef BOOL (__stdcall *KillTimer_z)( HWND, UINT_PTR );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	KillTimer_z OrigKillTimer = 0;
    if(hModule != 0)
    {
        OrigKillTimer = (KillTimer_z)GetProcAddress(hModule, "KillTimer");
		if (OrigKillTimer != 0) {
			return OrigKillTimer( hWnd, uIDEvent);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl GetGUIThreadInfo(DWORD idThread,LPGUITHREADINFO lpgui);
__declspec(dllexport) BOOL cdecl GetGUIThreadInfo(DWORD idThread,LPGUITHREADINFO lpgui){
	typedef BOOL (__stdcall *GetGUIThreadInfo_z)( DWORD, LPGUITHREADINFO );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetGUIThreadInfo_z OrigGetGUIThreadInfo = 0;
    if(hModule != 0)
    {
        OrigGetGUIThreadInfo = (GetGUIThreadInfo_z)GetProcAddress(hModule, "GetGUIThreadInfo");
		if (OrigGetGUIThreadInfo != 0) {
			return OrigGetGUIThreadInfo( idThread, lpgui);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HWINEVENTHOOK cdecl SetWinEventHook(UINT eventMin,UINT eventMax,HMODULE hmodWinEventProc,WINEVENTPROC lpfnWinEventProc,DWORD idProcess,DWORD idThread,UINT dwflags);
__declspec(dllexport) HWINEVENTHOOK cdecl SetWinEventHook(UINT eventMin,UINT eventMax,HMODULE hmodWinEventProc,WINEVENTPROC lpfnWinEventProc,DWORD idProcess,DWORD idThread,UINT dwflags){
	typedef HWINEVENTHOOK (__stdcall *SetWinEventHook_z)( UINT, UINT, HMODULE, WINEVENTPROC, DWORD, DWORD, UINT );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	SetWinEventHook_z OrigSetWinEventHook = 0;
    if(hModule != 0)
    {
        OrigSetWinEventHook = (SetWinEventHook_z)GetProcAddress(hModule, "SetWinEventHook");
		if (OrigSetWinEventHook != 0) {
			return OrigSetWinEventHook( eventMin, eventMax, hmodWinEventProc, lpfnWinEventProc, idProcess, idThread, dwflags);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) DWORD cdecl WaitForInputIdle(HANDLE hProcess,DWORD  dwMilliseconds);
__declspec(dllexport) DWORD cdecl WaitForInputIdle(HANDLE hProcess,DWORD  dwMilliseconds){
	typedef DWORD (__stdcall *WaitForInputIdle_z)( HANDLE, DWORD );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	WaitForInputIdle_z OrigWaitForInputIdle = 0;
    if(hModule != 0)
    {
        OrigWaitForInputIdle = (WaitForInputIdle_z)GetProcAddress(hModule, "WaitForInputIdle");
		if (OrigWaitForInputIdle != 0) {
			return OrigWaitForInputIdle( hProcess, dwMilliseconds );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) UINT cdecl RealGetWindowClassW(HWND hwnd,LPWSTR ptszClassName,UINT cchClassNameMax);
__declspec(dllexport) UINT cdecl RealGetWindowClassW(HWND hwnd,LPWSTR ptszClassName,UINT cchClassNameMax){
	typedef UINT (__stdcall *RealGetWindowClassW_z)( HWND, LPWSTR, UINT );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	RealGetWindowClassW_z OrigRealGetWindowClassW = 0;
    if(hModule != 0)
    {
        OrigRealGetWindowClassW = (RealGetWindowClassW_z)GetProcAddress(hModule, "RealGetWindowClassW");
		if (OrigRealGetWindowClassW != 0) {
			return OrigRealGetWindowClassW( hwnd, ptszClassName, cchClassNameMax );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) int cdecl GetClassNameW(HWND hWnd,LPWSTR lpClassName,int nMaxCount);
__declspec(dllexport) int cdecl GetClassNameW(HWND hWnd,LPWSTR lpClassName,int nMaxCount){
	typedef int (__stdcall *GetClassNameW_z)( HWND, LPWSTR, int );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetClassNameW_z OrigGetClassNameW = 0;
    if(hModule != 0)
    {
        OrigGetClassNameW = (GetClassNameW_z)GetProcAddress(hModule, "GetClassNameW");
		if (OrigGetClassNameW != 0) {
			return OrigGetClassNameW( hWnd, lpClassName, nMaxCount );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HWND cdecl FindWindowExW(HWND hWndParent,HWND hWndChildAfter,LPCWSTR lpszClass,LPCWSTR lpszWindow);
__declspec(dllexport) HWND cdecl FindWindowExW(HWND hWndParent,HWND hWndChildAfter,LPCWSTR lpszClass,LPCWSTR lpszWindow){
	typedef HWND (__stdcall *FindWindowExW_z)( HWND, HWND, LPCWSTR, LPCWSTR );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	FindWindowExW_z OrigFindWindowExW = 0;
    if(hModule != 0)
    {
        OrigFindWindowExW = (FindWindowExW_z)GetProcAddress(hModule, "FindWindowExW");
		if (OrigFindWindowExW != 0) {
			return OrigFindWindowExW( hWndParent, hWndChildAfter, lpszClass, lpszWindow );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) LRESULT cdecl DispatchMessageW(CONST MSG *lpMsg);
__declspec(dllexport) LRESULT cdecl DispatchMessageW(CONST MSG *lpMsg){
	typedef LRESULT (__stdcall *DispatchMessageW_z)( CONST MSG );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	DispatchMessageW_z OrigDispatchMessageW = 0;
    if(hModule != 0)
    {
        OrigDispatchMessageW = (DispatchMessageW_z)GetProcAddress(hModule, "DispatchMessageW");
		if (OrigDispatchMessageW != 0) {
			return OrigDispatchMessageW( *lpMsg );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) DWORD cdecl MsgWaitForMultipleObjects(DWORD  nCount,const HANDLE *pHandles,BOOL   bWaitAll,DWORD  dwMilliseconds,DWORD  dwWakeMask);
__declspec(dllexport) DWORD cdecl MsgWaitForMultipleObjects(DWORD  nCount,const HANDLE *pHandles,BOOL   bWaitAll,DWORD  dwMilliseconds,DWORD  dwWakeMask){
	typedef DWORD (__stdcall *MsgWaitForMultipleObjects_z)( DWORD, const HANDLE, BOOL, DWORD, DWORD );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	MsgWaitForMultipleObjects_z OrigMsgWaitForMultipleObjects = 0;
    if(hModule != 0)
    {
        OrigMsgWaitForMultipleObjects = (MsgWaitForMultipleObjects_z)GetProcAddress(hModule, "MsgWaitForMultipleObjects");
		if (OrigMsgWaitForMultipleObjects != 0) {
			return OrigMsgWaitForMultipleObjects( nCount, *pHandles, bWaitAll, dwMilliseconds, dwWakeMask );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl ChangeWindowMessageFilterEx(HWND hWnd,UINT message,DWORD action,PCHANGEFILTERSTRUCT pChangeFilterStruct);
__declspec(dllexport) BOOL cdecl ChangeWindowMessageFilterEx(HWND hWnd,UINT message,DWORD action,PCHANGEFILTERSTRUCT pChangeFilterStruct){
	typedef BOOL (__stdcall *ChangeWindowMessageFilterEx_z)( HWND, UINT, DWORD, PCHANGEFILTERSTRUCT );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	ChangeWindowMessageFilterEx_z OrigChangeWindowMessageFilterEx = 0;
    if(hModule != 0)
    {
        OrigChangeWindowMessageFilterEx = (ChangeWindowMessageFilterEx_z)GetProcAddress(hModule, "ChangeWindowMessageFilterEx");
		if (OrigChangeWindowMessageFilterEx != 0) {
			return OrigChangeWindowMessageFilterEx( hWnd, message, action, pChangeFilterStruct );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl DestroyIcon(HICON hIcon);
__declspec(dllexport) BOOL cdecl DestroyIcon(HICON hIcon){
	typedef BOOL (__stdcall *DestroyIcon_z)( HICON );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	DestroyIcon_z OrigDestroyIcon = 0;
    if(hModule != 0)
    {
        OrigDestroyIcon = (DestroyIcon_z)GetProcAddress(hModule, "DestroyIcon");
		if (OrigDestroyIcon != 0) {
			return OrigDestroyIcon( hIcon );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl GetIconInfo(HICON hIcon,PICONINFO piconinfo);
__declspec(dllexport) BOOL cdecl GetIconInfo(HICON hIcon,PICONINFO piconinfo){
	typedef BOOL (__stdcall *GetIconInfo_z)( HICON, PICONINFO );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetIconInfo_z OrigGetIconInfo = 0;
    if(hModule != 0)
    {
        OrigGetIconInfo = (GetIconInfo_z)GetProcAddress(hModule, "GetIconInfo");
		if (OrigGetIconInfo != 0) {
			return OrigGetIconInfo( hIcon, piconinfo );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HICON cdecl CreateIconIndirect( PICONINFO piconinfo );
__declspec(dllexport) HICON cdecl CreateIconIndirect( PICONINFO piconinfo ){
	typedef HICON (__stdcall *CreateIconIndirect_z)( PICONINFO );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	CreateIconIndirect_z OrigCreateIconIndirect = 0;
    if(hModule != 0)
    {
        OrigCreateIconIndirect = (CreateIconIndirect_z)GetProcAddress(hModule, "CreateIconIndirect");
		if (OrigCreateIconIndirect != 0) {
			return OrigCreateIconIndirect( piconinfo );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl SetThreadDesktop(HDESK hDesktop);
__declspec(dllexport) BOOL cdecl SetThreadDesktop(HDESK hDesktop){
	typedef BOOL (__stdcall *SetThreadDesktop_z)( HDESK );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	SetThreadDesktop_z OrigSetThreadDesktop = 0;
    if(hModule != 0)
    {
        OrigSetThreadDesktop = (SetThreadDesktop_z)GetProcAddress(hModule, "SetThreadDesktop");
		if (OrigSetThreadDesktop != 0) {
			return OrigSetThreadDesktop( hDesktop );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl GetMessageW(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax);
__declspec(dllexport) BOOL cdecl GetMessageW(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax){
	typedef BOOL (__stdcall *GetMessageW_z)( LPMSG, HWND, UINT, UINT );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetMessageW_z OrigGetMessageW = 0;
    if(hModule != 0)
    {
        OrigGetMessageW = (GetMessageW_z)GetProcAddress(hModule, "GetMessageW");
		if (OrigGetMessageW != 0) {
			return OrigGetMessageW( lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl GetMessageA(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax);
__declspec(dllexport) BOOL cdecl GetMessageA(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax){
	typedef BOOL (__stdcall *GetMessageA_z)( LPMSG, HWND, UINT, UINT );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetMessageA_z OrigGetMessageA = 0;
    if(hModule != 0)
    {
        OrigGetMessageA = (GetMessageA_z)GetProcAddress(hModule, "GetMessageA");
		if (OrigGetMessageA != 0) {
			return OrigGetMessageA( lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl PeekMessageA(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax,UINT wRemoveMsg);
__declspec(dllexport) BOOL cdecl PeekMessageA(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax,UINT wRemoveMsg){
	typedef BOOL (__stdcall *PeekMessageA_z)( LPMSG, HWND, UINT, UINT, UINT );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	PeekMessageA_z OrigPeekMessageA = 0;
    if(hModule != 0)
    {
        OrigPeekMessageA = (PeekMessageA_z)GetProcAddress(hModule, "PeekMessageA");
		if (OrigPeekMessageA != 0) {
			return OrigPeekMessageA( lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl InsertMenuItemW(__in HMENU hmenu,__in UINT item,__in BOOL fByPosition,__in LPCMENUITEMINFOW lpmi);
__declspec(dllexport) BOOL cdecl InsertMenuItemW(__in HMENU hmenu,__in UINT item,__in BOOL fByPosition,__in LPCMENUITEMINFOW lpmi){
	typedef BOOL (__stdcall *InsertMenuItemW_z)( HMENU, UINT, BOOL, LPCMENUITEMINFOW );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	InsertMenuItemW_z OrigInsertMenuItemW = 0;
    if(hModule != 0)
    {
        OrigInsertMenuItemW = (InsertMenuItemW_z)GetProcAddress(hModule, "InsertMenuItemW");
		if (OrigInsertMenuItemW != 0) {
			return OrigInsertMenuItemW( hmenu, item, fByPosition, lpmi );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HICON cdecl CopyIcon( _In_ HICON hIcon );
__declspec(dllexport) HICON cdecl CopyIcon( _In_ HICON hIcon ){
	typedef HICON (__stdcall *CopyIcon_z)( HICON );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	CopyIcon_z OrigCopyIcon = 0;
    if(hModule != 0)
    {
        OrigCopyIcon = (CopyIcon_z)GetProcAddress(hModule, "CopyIcon");
		if (OrigCopyIcon != 0) {
			return OrigCopyIcon( hIcon );
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) UINT cdecl PrivateExtractIconsW(
__in LPCWSTR szFileName,
__in int nIconIndex,
__in int cxIcon,
__in int cyIcon,
__out_ecount_part_opt(nIcons, return) HICON *phicon,
__out_ecount_part_opt(nIcons, return) UINT *piconid,
__in UINT nIcons,
__in UINT flags);
__declspec(dllexport) UINT cdecl PrivateExtractIconsW(
__in LPCWSTR szFileName,
__in int nIconIndex,
__in int cxIcon,
__in int cyIcon,
__out_ecount_part_opt(nIcons, return) HICON *phicon,
__out_ecount_part_opt(nIcons, return) UINT *piconid,
__in UINT nIcons,
__in UINT flags){
	typedef UINT (__stdcall *PrivateExtractIconsW_z)(LPCWSTR, int, int, int, HICON, UINT );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	PrivateExtractIconsW_z OrigPrivateExtractIconsW = 0;
    if(hModule != 0)
    {
        OrigPrivateExtractIconsW = (PrivateExtractIconsW_z)GetProcAddress(hModule, "PrivateExtractIconsW");
		if (OrigPrivateExtractIconsW != 0) {
			return OrigPrivateExtractIconsW(szFileName, nIconIndex, cxIcon, cyIcon, *phicon, *piconid);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HANDLE cdecl LoadImageW(HINSTANCE hinst, LPCWSTR name, UINT type, INT desiredx, INT desiredy, UINT loadflags);
__declspec(dllexport) HANDLE cdecl LoadImageW(HINSTANCE hinst, LPCWSTR name, UINT type, INT desiredx, INT desiredy, UINT loadflags){
	typedef HANDLE (__stdcall *LoadImageW_z)(HINSTANCE, LPCWSTR,UINT, INT, INT,UINT );
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	LoadImageW_z OrigLoadImageW = 0;
    if(hModule != 0)
    {
        OrigLoadImageW = (LoadImageW_z)GetProcAddress(hModule, "LoadImageW");
		if (OrigLoadImageW != 0) {
			return OrigLoadImageW(hinst, name, type, desiredx, desiredy, loadflags);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HMENU cdecl CreatePopupMenu(void);
__declspec(dllexport) HMENU cdecl CreatePopupMenu(void){
	typedef HMENU (__stdcall *CreatePopupMenu_z)(void);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	CreatePopupMenu_z OrigCreatePopupMenu = 0;
    if(hModule != 0)
    {
        OrigCreatePopupMenu = (CreatePopupMenu_z)GetProcAddress(hModule, "CreatePopupMenu");
		if (OrigCreatePopupMenu != 0) {
			return OrigCreatePopupMenu();
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl TrackPopupMenuEx(
  _In_     HMENU       hmenu,
  _In_     UINT        fuFlags,
  _In_     int         x,
  _In_     int         y,
  _In_     HWND        hwnd,
  _In_opt_ LPTPMPARAMS lptpm
);
__declspec(dllexport) BOOL cdecl TrackPopupMenuEx(
  _In_     HMENU       hmenu,
  _In_     UINT        fuFlags,
  _In_     int         x,
  _In_     int         y,
  _In_     HWND        hwnd,
  _In_opt_ LPTPMPARAMS lptpm
){
	typedef BOOL (__stdcall *TrackPopupMenuEx_z)(HMENU, UINT, int, int, HWND, LPTPMPARAMS);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	TrackPopupMenuEx_z OrigTrackPopupMenuEx = 0;
    if(hModule != 0)
    {
        OrigTrackPopupMenuEx = (TrackPopupMenuEx_z)GetProcAddress(hModule, "TrackPopupMenuEx");
		if (OrigTrackPopupMenuEx != 0) {
			return OrigTrackPopupMenuEx( hmenu, fuFlags, x, y, hwnd, lptpm );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl DestroyMenu(_In_ HMENU hMenu);
__declspec(dllexport) BOOL cdecl DestroyMenu(_In_ HMENU hMenu){
	typedef BOOL (__stdcall *DestroyMenu_z)(HMENU);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	DestroyMenu_z OrigDestroyMenu = 0;
    if(hModule != 0)
    {
        OrigDestroyMenu = (DestroyMenu_z)GetProcAddress(hModule, "DestroyMenu");
		if (OrigDestroyMenu != 0) {
			return OrigDestroyMenu( hMenu );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HANDLE cdecl CopyImage(_In_ HANDLE hImage,_In_ UINT   uType,_In_ int    cxDesired,_In_ int    cyDesired,_In_ UINT   fuFlags);
__declspec(dllexport) HANDLE cdecl CopyImage(_In_ HANDLE hImage,_In_ UINT   uType,_In_ int    cxDesired,_In_ int    cyDesired,_In_ UINT   fuFlags){
	typedef HANDLE (__stdcall *CopyImage_z)(HANDLE, UINT, int, int, UINT);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	CopyImage_z OrigCopyImage = 0;
    if(hModule != 0)
    {
        OrigCopyImage = (CopyImage_z)GetProcAddress(hModule, "CopyImage");
		if (OrigCopyImage != 0) {
			return OrigCopyImage( hImage, uType, cxDesired, cyDesired, fuFlags );
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) BOOL cdecl UnloadKeyboardLayout(_In_ HKL hkl );
__declspec(dllexport) BOOL cdecl UnloadKeyboardLayout(_In_ HKL hkl ){
	typedef BOOL (__stdcall *UnloadKeyboardLayout_z)(HKL);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	UnloadKeyboardLayout_z OrigUnloadKeyboardLayout = 0;
    if(hModule != 0)
    {
        OrigUnloadKeyboardLayout = (UnloadKeyboardLayout_z)GetProcAddress(hModule, "UnloadKeyboardLayout");
		if (OrigUnloadKeyboardLayout != 0) {
			return OrigUnloadKeyboardLayout(hkl);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) LRESULT cdecl SendMessageTimeoutW(
    __in HWND hWnd,
    __in UINT Msg,
    __in WPARAM wParam,
    __in LPARAM lParam,
    __in UINT fuFlags,
    __in UINT uTimeout,
    __out_opt PDWORD_PTR lpdwResult);
__declspec(dllexport) LRESULT cdecl SendMessageTimeoutW(
    __in HWND hWnd,
    __in UINT Msg,
    __in WPARAM wParam,
    __in LPARAM lParam,
    __in UINT fuFlags,
    __in UINT uTimeout,
    __out_opt PDWORD_PTR lpdwResult){
	typedef LRESULT (__stdcall *SendMessageTimeoutW_z)(HWND, UINT, WPARAM, LPARAM, UINT, UINT, PDWORD_PTR);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	SendMessageTimeoutW_z OrigSendMessageTimeoutW = 0;
    if(hModule != 0)
    {
        OrigSendMessageTimeoutW = (SendMessageTimeoutW_z)GetProcAddress(hModule, "SendMessageTimeoutW");
		if (OrigSendMessageTimeoutW != 0) {
			return OrigSendMessageTimeoutW(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult );
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) HWND cdecl GetDesktopWindow(void);
__declspec(dllexport) HWND cdecl GetDesktopWindow(void){
	typedef HWND (__stdcall *GetDesktopWindow_z)(void);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetDesktopWindow_z OrigGetDesktopWindow = 0;
    if(hModule != 0)
    {
        OrigGetDesktopWindow = (GetDesktopWindow_z)GetProcAddress(hModule, "GetDesktopWindow");
		if (OrigGetDesktopWindow != 0) {
			return OrigGetDesktopWindow();
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl IsWindowUnicode(_In_ HWND hWnd);
__declspec(dllexport) BOOL cdecl IsWindowUnicode(_In_ HWND hWnd){
	typedef BOOL (__stdcall *IsWindowUnicode_z)(HWND);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	IsWindowUnicode_z OrigIsWindowUnicode = 0;
    if(hModule != 0)
    {
        OrigIsWindowUnicode = (IsWindowUnicode_z)GetProcAddress(hModule, "IsWindowUnicode");
		if (OrigIsWindowUnicode != 0) {
			return OrigIsWindowUnicode(hWnd);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) LPWSTR cdecl CharNextW(__in LPCWSTR lpsz);
__declspec(dllexport) LPWSTR cdecl CharNextW(__in LPCWSTR lpsz){
	typedef LPWSTR (__stdcall *CharNextW_z)(LPCWSTR);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	CharNextW_z OrigCharNextW = 0;
    if(hModule != 0)
    {
        OrigCharNextW = (CharNextW_z)GetProcAddress(hModule, "CharNextW");
		if (OrigCharNextW != 0) {
			return OrigCharNextW(lpsz);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) LPSTR cdecl CharNextA(__in LPCSTR lpsz);
__declspec(dllexport) LPSTR cdecl CharNextA(__in LPCSTR lpsz){
	typedef LPSTR (__stdcall *CharNextA_z)(LPCSTR);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	CharNextA_z OrigCharNextA = 0;
    if(hModule != 0)
    {
        OrigCharNextA = (CharNextA_z)GetProcAddress(hModule, "CharNextA");
		if (OrigCharNextA != 0) {
			return OrigCharNextA(lpsz);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) int cdecl MapWindowPoints(_In_    HWND    hWndFrom,_In_    HWND    hWndTo,_Inout_ LPPOINT lpPoints,_In_    UINT    cPoints);
__declspec(dllexport) int cdecl MapWindowPoints(_In_    HWND    hWndFrom,_In_    HWND    hWndTo,_Inout_ LPPOINT lpPoints,_In_    UINT    cPoints){
	typedef int (__stdcall *MapWindowPoints_z)(HWND, HWND, LPPOINT,UINT);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	MapWindowPoints_z OrigMapWindowPoints = 0;
    if(hModule != 0)
    {
        OrigMapWindowPoints = (MapWindowPoints_z)GetProcAddress(hModule, "MapWindowPoints");
		if (OrigMapWindowPoints != 0) {
			return OrigMapWindowPoints(hWndFrom, hWndTo, lpPoints,cPoints);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) HWND cdecl GetForegroundWindow(void);
__declspec(dllexport) HWND cdecl GetForegroundWindow(void){
	typedef HWND (__stdcall *GetForegroundWindow_z)(void);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetForegroundWindow_z OrigGetForegroundWindow = 0;
    if(hModule != 0)
    {
        OrigGetForegroundWindow = (GetForegroundWindow_z)GetProcAddress(hModule, "GetForegroundWindow");
		if (OrigGetForegroundWindow != 0) {
			return OrigGetForegroundWindow();
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl ClientToScreen(_In_    HWND    hWnd,_Inout_ LPPOINT lpPoint);
__declspec(dllexport) BOOL cdecl ClientToScreen(_In_    HWND    hWnd,_Inout_ LPPOINT lpPoint){
	typedef BOOL (__stdcall *ClientToScreen_z)(HWND, LPPOINT);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	ClientToScreen_z OrigClientToScreen = 0;
    if(hModule != 0)
    {
        OrigClientToScreen = (ClientToScreen_z)GetProcAddress(hModule, "ClientToScreen");
		if (OrigClientToScreen != 0) {
			return OrigClientToScreen(hWnd, lpPoint);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) BOOL cdecl GetKeyboardState(_Out_ PBYTE lpKeyState);
__declspec(dllexport) BOOL cdecl GetKeyboardState(_Out_ PBYTE lpKeyState){
	typedef BOOL (__stdcall *GetKeyboardState_z)(PBYTE);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetKeyboardState_z OrigGetKeyboardState = 0;
    if(hModule != 0)
    {
        OrigGetKeyboardState = (GetKeyboardState_z)GetProcAddress(hModule, "GetKeyboardState");
		if (OrigGetKeyboardState != 0) {
			return OrigGetKeyboardState(lpKeyState);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) int cdecl ToUnicode(_In_ UINT   wVirtKey,_In_ UINT   wScanCode,_In_opt_ const BYTE   *lpKeyState,_Out_ LPWSTR pwszBuff,_In_ int    cchBuff,_In_ UINT   wFlags);
__declspec(dllexport) int cdecl ToUnicode(_In_ UINT   wVirtKey,_In_ UINT   wScanCode,_In_opt_ const BYTE   *lpKeyState,_Out_ LPWSTR pwszBuff,_In_ int    cchBuff,_In_ UINT   wFlags){
	typedef int (__stdcall *ToUnicode_z)(UINT, UINT, const BYTE, LPWSTR, int, UINT);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	ToUnicode_z OrigToUnicode = 0;
    if(hModule != 0)
    {
        OrigToUnicode = (ToUnicode_z)GetProcAddress(hModule, "ToUnicode");
		if (OrigToUnicode != 0) {
			return OrigToUnicode(wVirtKey, wScanCode, *lpKeyState, pwszBuff, cchBuff, wFlags);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) int cdecl ToAsciiEx(_In_ UINT   uVirtKey,_In_ UINT   uScanCode,_In_opt_ const BYTE   *lpKeyState,_Out_    LPWORD lpChar,_In_   UINT   uFlags,_In_opt_    HKL    dwhkl);
__declspec(dllexport) int cdecl ToAsciiEx(_In_ UINT   uVirtKey,_In_ UINT   uScanCode,_In_opt_ const BYTE   *lpKeyState,_Out_    LPWORD lpChar,_In_   UINT   uFlags,_In_opt_    HKL    dwhkl){
	typedef int (__stdcall *ToAsciiEx_z)(UINT, UINT, const BYTE, LPWORD, UINT, HKL);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	ToAsciiEx_z OrigToAsciiEx = 0;
    if(hModule != 0)
    {
        OrigToAsciiEx = (ToAsciiEx_z)GetProcAddress(hModule, "ToAsciiEx");
		if (OrigToAsciiEx != 0) {
			return OrigToAsciiEx(uVirtKey, uScanCode, *lpKeyState, lpChar, uFlags, dwhkl);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) BOOL cdecl DestroyWindow(_In_ HWND hWnd);
__declspec(dllexport) BOOL cdecl DestroyWindow(_In_ HWND hWnd){
	typedef BOOL (__stdcall *DestroyWindow_z)(HWND);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	DestroyWindow_z OrigDestroyWindow = 0;
    if(hModule != 0)
    {
        OrigDestroyWindow = (DestroyWindow_z)GetProcAddress(hModule, "DestroyWindow");
		if (OrigDestroyWindow != 0) {
			return OrigDestroyWindow(hWnd);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) UINT cdecl MapVirtualKeyW(__in UINT uCode,__in UINT uMapType);
__declspec(dllexport) UINT cdecl MapVirtualKeyW(__in UINT uCode,__in UINT uMapType){
	typedef UINT (__stdcall *MapVirtualKeyW_z)(UINT, UINT);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	MapVirtualKeyW_z OrigMapVirtualKeyW = 0;
    if(hModule != 0)
    {
        OrigMapVirtualKeyW = (MapVirtualKeyW_z)GetProcAddress(hModule, "MapVirtualKeyW");
		if (OrigMapVirtualKeyW != 0) {
			return OrigMapVirtualKeyW(uCode, uMapType);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) HWND cdecl CreateWindowExW(__in DWORD dwExStyle,__in_opt LPCWSTR lpClassName,__in_opt LPCWSTR lpWindowName,__in DWORD dwStyle,__in int X,__in int Y,__in int nWidth,__in int nHeight,__in_opt HWND hWndParent,__in_opt HMENU hMenu,__in_opt HINSTANCE hInstance,__in_opt LPVOID lpParam);
__declspec(dllexport) HWND cdecl CreateWindowExW(__in DWORD dwExStyle,__in_opt LPCWSTR lpClassName,__in_opt LPCWSTR lpWindowName,__in DWORD dwStyle,__in int X,__in int Y,__in int nWidth,__in int nHeight,__in_opt HWND hWndParent,__in_opt HMENU hMenu,__in_opt HINSTANCE hInstance,__in_opt LPVOID lpParam){
	typedef HWND (__stdcall *CreateWindowExW_z)(DWORD, LPCWSTR, LPCWSTR,DWORD, int, int, int, int,  HWND, HMENU, HINSTANCE, LPVOID);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	CreateWindowExW_z OrigCreateWindowExW = 0;
    if(hModule != 0)
    {
        OrigCreateWindowExW = (CreateWindowExW_z)GetProcAddress(hModule, "CreateWindowExW");
		if (OrigCreateWindowExW != 0) {
			return OrigCreateWindowExW(dwExStyle,lpClassName, lpWindowName, dwStyle,X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) BOOL cdecl ShowWindow( _In_ HWND hWnd,_In_ int  nCmdShow);
__declspec(dllexport) BOOL cdecl ShowWindow( _In_ HWND hWnd,_In_ int  nCmdShow){
	typedef BOOL (__stdcall *ShowWindow_z)(HWND, int);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	ShowWindow_z OrigShowWindow = 0;
    if(hModule != 0)
    {
        OrigShowWindow = (ShowWindow_z)GetProcAddress(hModule, "ShowWindow");
		if (OrigShowWindow != 0) {
			return OrigShowWindow(hWnd,nCmdShow);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl UpdateWindow( _In_ HWND hWnd);
 __declspec(dllexport)  BOOL cdecl UpdateWindow( _In_ HWND hWnd){
	typedef BOOL (__stdcall *UpdateWindow_z)(HWND);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	UpdateWindow_z OrigUpdateWindow = 0;
    if(hModule != 0)
    {
        OrigUpdateWindow = (UpdateWindow_z)GetProcAddress(hModule, "UpdateWindow");
		if (OrigUpdateWindow != 0) {
			return OrigUpdateWindow(hWnd);
		}
    }
	return 0;
 }

extern "C" __declspec(dllexport) HMONITOR cdecl MonitorFromWindow(_In_ HWND  hwnd,_In_ DWORD dwFlags);
__declspec(dllexport) HMONITOR cdecl MonitorFromWindow(_In_ HWND  hwnd,_In_ DWORD dwFlags){
	typedef HMONITOR (__stdcall *MonitorFromWindow_z)(HWND, DWORD);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	MonitorFromWindow_z OrigMonitorFromWindow = 0;
    if(hModule != 0)
    {
        OrigMonitorFromWindow = (MonitorFromWindow_z)GetProcAddress(hModule, "MonitorFromWindow");
		if (OrigMonitorFromWindow != 0) {
			return OrigMonitorFromWindow(hwnd,dwFlags);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl GetMonitorInfoW(__in HMONITOR hMonitor,__inout LPMONITORINFO lpmi);
__declspec(dllexport) BOOL cdecl GetMonitorInfoW(__in HMONITOR hMonitor,__inout LPMONITORINFO lpmi){
	typedef BOOL (__stdcall *GetMonitorInfoW_z)(HMONITOR, LPMONITORINFO);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetMonitorInfoW_z OrigGetMonitorInfoW = 0;
    if(hModule != 0)
    {
        OrigGetMonitorInfoW = (GetMonitorInfoW_z)GetProcAddress(hModule, "GetMonitorInfoW");
		if (OrigGetMonitorInfoW != 0) {
			return OrigGetMonitorInfoW(hMonitor,lpmi);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) 
BOOL
cdecl
SystemParametersInfoW(
    __in UINT uiAction,
    __in UINT uiParam,
    __inout_opt PVOID pvParam,
    __in UINT fWinIni);
 __declspec(dllexport) 
BOOL
cdecl
SystemParametersInfoW(
    __in UINT uiAction,
    __in UINT uiParam,
    __inout_opt PVOID pvParam,
    __in UINT fWinIni){
	typedef BOOL (__stdcall *SystemParametersInfoW_z)(UINT, UINT, PVOID, UINT);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	SystemParametersInfoW_z OrigSystemParametersInfoW = 0;
    if(hModule != 0)
    {
        OrigSystemParametersInfoW = (SystemParametersInfoW_z)GetProcAddress(hModule, "SystemParametersInfoW");
		if (OrigSystemParametersInfoW != 0) {
			return OrigSystemParametersInfoW(uiAction,uiParam,pvParam,fWinIni );
		}
    }
	return 0;
 }

extern "C" __declspec(dllexport) BOOL cdecl GetClassInfoExW(__in_opt HINSTANCE hInstance,__in LPCWSTR lpszClass,__out LPWNDCLASSEXW lpwcx);
__declspec(dllexport) BOOL cdecl GetClassInfoExW(__in_opt HINSTANCE hInstance,__in LPCWSTR lpszClass,__out LPWNDCLASSEXW lpwcx){
	typedef BOOL (__stdcall *GetClassInfoExW_z)(HINSTANCE, LPCWSTR, LPWNDCLASSEXW);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetClassInfoExW_z OrigGetClassInfoExW = 0;
    if(hModule != 0)
    {
        OrigGetClassInfoExW = (GetClassInfoExW_z)GetProcAddress(hModule, "GetClassInfoExW");
		if (OrigGetClassInfoExW != 0) {
			return OrigGetClassInfoExW(hInstance,lpszClass,lpwcx );
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) HICON cdecl LoadIconW(__in_opt HINSTANCE hInstance,__in LPCWSTR lpIconName);
__declspec(dllexport) HICON cdecl LoadIconW(__in_opt HINSTANCE hInstance,__in LPCWSTR lpIconName){
	typedef HICON (__stdcall *LoadIconW_z)(HINSTANCE, LPCWSTR);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	LoadIconW_z OrigLoadIconW = 0;
    if(hModule != 0)
    {
        OrigLoadIconW = (LoadIconW_z)GetProcAddress(hModule, "LoadIconW");
		if (OrigLoadIconW != 0) {
			return OrigLoadIconW(hInstance,lpIconName );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) ATOM cdecl RegisterClassExW( _In_ const WNDCLASSEX *lpwcx);
__declspec(dllexport) ATOM cdecl RegisterClassExW( _In_ const WNDCLASSEX *lpwcx){
	typedef ATOM (__stdcall *RegisterClassExW_z)(const WNDCLASSEX);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	RegisterClassExW_z OrigRegisterClassExW = 0;
    if(hModule != 0)
    {
        OrigRegisterClassExW = (RegisterClassExW_z)GetProcAddress(hModule, "RegisterClassExW");
		if (OrigRegisterClassExW != 0) {
			return OrigRegisterClassExW(*lpwcx );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HWND cdecl GetParent(_In_ HWND hWnd);
__declspec(dllexport) HWND cdecl GetParent(_In_ HWND hWnd){
	typedef HWND (__stdcall *GetParent_z)(HWND);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetParent_z OrigGetParent = 0;
    if(hModule != 0)
    {
        OrigGetParent = (GetParent_z)GetProcAddress(hModule, "GetParent");
		if (OrigGetParent != 0) {
			return OrigGetParent(hWnd );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HWND cdecl GetCapture(void);
__declspec(dllexport) HWND cdecl GetCapture(void){
	typedef HWND (__stdcall *GetCapture_z)(void);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetCapture_z OrigGetCapture = 0;
    if(hModule != 0)
    {
        OrigGetCapture = (GetCapture_z)GetProcAddress(hModule, "GetCapture");
		if (OrigGetCapture != 0) {
			return OrigGetCapture( );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl DrawEdge(_In_    HDC    hdc,_Inout_ LPRECT qrc,_In_    UINT   edge,_In_    UINT   grfFlags);
__declspec(dllexport) BOOL cdecl DrawEdge(_In_    HDC    hdc,_Inout_ LPRECT qrc,_In_    UINT   edge,_In_    UINT   grfFlags){
	typedef BOOL (__stdcall *DrawEdge_z)(HDC, LPRECT, UINT, UINT);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	DrawEdge_z OrigDrawEdge = 0;
    if(hModule != 0)
    {
        OrigDrawEdge = (DrawEdge_z)GetProcAddress(hModule, "DrawEdge");
		if (OrigDrawEdge != 0) {
			return OrigDrawEdge(hdc, qrc, edge,grfFlags );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HDC cdecl BeginPaint(__in HWND hWnd,__out LPPAINTSTRUCT lpPaint);
__declspec(dllexport) HDC cdecl BeginPaint(__in HWND hWnd,__out LPPAINTSTRUCT lpPaint){
	typedef HDC (__stdcall *BeginPaint_z)(HWND, LPPAINTSTRUCT);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	BeginPaint_z OrigBeginPaint = 0;
    if(hModule != 0)
    {
        OrigBeginPaint = (BeginPaint_z)GetProcAddress(hModule, "BeginPaint");
		if (OrigBeginPaint != 0) {
			return OrigBeginPaint(hWnd, lpPaint );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl EndPaint(_In_       HWND        hWnd,_In_ const PAINTSTRUCT *lpPaint);
__declspec(dllexport) BOOL cdecl EndPaint(_In_       HWND        hWnd,_In_ const PAINTSTRUCT *lpPaint){
	typedef BOOL (__stdcall *EndPaint_z)(HWND, const PAINTSTRUCT);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	EndPaint_z OrigEndPaint = 0;
    if(hModule != 0)
    {
        OrigEndPaint = (EndPaint_z)GetProcAddress(hModule, "EndPaint");
		if (OrigEndPaint != 0) {
			return OrigEndPaint(hWnd, *lpPaint );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) LRESULT cdecl DefWindowProcW(_In_ HWND   hWnd,_In_ UINT   Msg,_In_ WPARAM wParam,_In_ LPARAM lParam);
__declspec(dllexport) LRESULT cdecl DefWindowProcW(_In_ HWND   hWnd,_In_ UINT   Msg,_In_ WPARAM wParam,_In_ LPARAM lParam){
	typedef LRESULT (__stdcall *DefWindowProcW_z)(HWND, UINT, WPARAM, LPARAM);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	DefWindowProcW_z OrigDefWindowProcW = 0;
    if(hModule != 0)
    {
        OrigDefWindowProcW = (DefWindowProcW_z)GetProcAddress(hModule, "DefWindowProcW");
		if (OrigDefWindowProcW != 0) {
			return OrigDefWindowProcW(hWnd, Msg,wParam, lParam );
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl ReleaseCapture(void);
__declspec(dllexport)BOOL cdecl ReleaseCapture(void){
	typedef BOOL (__stdcall *ReleaseCapture_z)(void);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	ReleaseCapture_z OrigReleaseCapture = 0;
    if(hModule != 0)
    {
        OrigReleaseCapture = (ReleaseCapture_z)GetProcAddress(hModule, "ReleaseCapture");
		if (OrigReleaseCapture != 0) {
			return OrigReleaseCapture();
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl SetWindowPos(
  _In_     HWND hWnd,
  _In_opt_ HWND hWndInsertAfter,
  _In_     int  X,
  _In_     int  Y,
  _In_     int  cx,
  _In_     int  cy,
  _In_     UINT uFlags
);
__declspec(dllexport) BOOL cdecl SetWindowPos(
  _In_     HWND hWnd,
  _In_opt_ HWND hWndInsertAfter,
  _In_     int  X,
  _In_     int  Y,
  _In_     int  cx,
  _In_     int  cy,
  _In_     UINT uFlags
){
	typedef BOOL (__stdcall *SetWindowPos_z)(HWND, HWND, int, int, int, int, UINT);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	SetWindowPos_z OrigSetWindowPos = 0;
    if(hModule != 0)
    {
        OrigSetWindowPos = (SetWindowPos_z)GetProcAddress(hModule, "SetWindowPos");
		if (OrigSetWindowPos != 0) {
			return OrigSetWindowPos(hWnd, hWndInsertAfter, X, Y, cx, cy, uFlags);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) HWND cdecl GetWindow(_In_ HWND hWnd,_In_ UINT uCmd);
__declspec(dllexport) HWND cdecl GetWindow(_In_ HWND hWnd,_In_ UINT uCmd){
	typedef HWND (__stdcall *GetWindow_z)(HWND, UINT);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetWindow_z OrigGetWindow = 0;
    if(hModule != 0)
    {
        OrigGetWindow = (GetWindow_z)GetProcAddress(hModule, "GetWindow");
		if (OrigGetWindow != 0) {
			return OrigGetWindow(hWnd, uCmd);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) VOID cdecl keybd_event(_In_ BYTE      bVk,_In_ BYTE      bScan,_In_ DWORD     dwFlags,_In_ ULONG_PTR dwExtraInfo);
__declspec(dllexport) VOID cdecl keybd_event(_In_ BYTE      bVk,_In_ BYTE      bScan,_In_ DWORD     dwFlags,_In_ ULONG_PTR dwExtraInfo){
	typedef VOID (__stdcall *keybd_event_z)(BYTE, BYTE, DWORD, ULONG_PTR);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	keybd_event_z Origkeybd_event = 0;
    if(hModule != 0)
    {
        Origkeybd_event = (keybd_event_z)GetProcAddress(hModule, "keybd_event");
		if (Origkeybd_event != 0) {
			return Origkeybd_event(bVk, bScan, dwFlags, dwExtraInfo);
		}
    }
	return;
}


extern "C" __declspec(dllexport) HCURSOR cdecl LoadCursorW(__in_opt HINSTANCE hInstance,__in LPCWSTR lpCursorName);
__declspec(dllexport) HCURSOR cdecl LoadCursorW(__in_opt HINSTANCE hInstance,__in LPCWSTR lpCursorName){
	typedef HCURSOR (__stdcall *LoadCursorW_z)(HINSTANCE, LPCWSTR);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	LoadCursorW_z OrigLoadCursorW = 0;
    if(hModule != 0)
    {
        OrigLoadCursorW = (LoadCursorW_z)GetProcAddress(hModule, "LoadCursorW");
		if (OrigLoadCursorW != 0) {
			return OrigLoadCursorW(hInstance, lpCursorName);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl IsWindow(  _In_opt_ HWND hWnd);
__declspec(dllexport) BOOL cdecl IsWindow(  _In_opt_ HWND hWnd){
	typedef BOOL (__stdcall *IsWindow_z)(HWND);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	IsWindow_z OrigIsWindow = 0;
    if(hModule != 0)
    {
        OrigIsWindow = (IsWindow_z)GetProcAddress(hModule, "IsWindow");
		if (OrigIsWindow != 0) {
			return OrigIsWindow(hWnd);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) DWORD cdecl WCSToMBEx (WORD CodePage, LPWSTR UnicodeString, LONG UnicodeSize, LPSTR *MBString, LONG MBSize, BOOL Allocate);
__declspec(dllexport) DWORD cdecl WCSToMBEx (WORD CodePage, LPWSTR UnicodeString, LONG UnicodeSize, LPSTR *MBString, LONG MBSize, BOOL Allocate){
	typedef DWORD (__stdcall *WCSToMBEx_z)(WORD, LPWSTR, LONG, LPSTR, LONG, BOOL);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	WCSToMBEx_z OrigWCSToMBEx = 0;
    if(hModule != 0)
    {
        OrigWCSToMBEx = (WCSToMBEx_z)GetProcAddress(hModule, "WCSToMBEx");
		if (OrigWCSToMBEx != 0) {
			return OrigWCSToMBEx(CodePage, UnicodeString, UnicodeSize, *MBString, MBSize, Allocate);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) DWORD cdecl MBToWCSEx (WORD CodePage, LPSTR MBString, LONG MBSize, LPWSTR *UnicodeString, LONG UnicodeSize, BOOL Allocate);
__declspec(dllexport) DWORD cdecl MBToWCSEx (WORD CodePage, LPSTR MBString, LONG MBSize, LPWSTR *UnicodeString, LONG UnicodeSize, BOOL Allocate){
	typedef DWORD (__stdcall *MBToWCSEx_z)(WORD, LPSTR, LONG, LPWSTR, LONG, BOOL);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	MBToWCSEx_z OrigMBToWCSEx = 0;
    if(hModule != 0)
    {
        OrigMBToWCSEx = (MBToWCSEx_z)GetProcAddress(hModule, "MBToWCSEx");
		if (OrigMBToWCSEx != 0) {
			return OrigMBToWCSEx(CodePage, MBString, MBSize, *UnicodeString, UnicodeSize, Allocate);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl PostMessageA(__in_opt HWND hWnd,__in UINT Msg,__in WPARAM wParam,__in LPARAM lParam);
__declspec(dllexport) BOOL cdecl PostMessageA(__in_opt HWND hWnd,__in UINT Msg,__in WPARAM wParam,__in LPARAM lParam){
	typedef BOOL (__stdcall *PostMessageA_z)(HWND, UINT, WPARAM, LPARAM);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	PostMessageA_z OrigPostMessageA = 0;
    if(hModule != 0)
    {
        OrigPostMessageA = (PostMessageA_z)GetProcAddress(hModule, "PostMessageA");
		if (OrigPostMessageA != 0) {
			return OrigPostMessageA(hWnd, Msg, wParam, lParam);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) BOOL cdecl PostMessageW(__in_opt HWND hWnd,__in UINT Msg,__in WPARAM wParam,__in LPARAM lParam);
__declspec(dllexport) BOOL cdecl PostMessageW(__in_opt HWND hWnd,__in UINT Msg,__in WPARAM wParam,__in LPARAM lParam){
	typedef BOOL (__stdcall *PostMessageW_z)(HWND, UINT, WPARAM, LPARAM);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	PostMessageW_z OrigPostMessageW = 0;
    if(hModule != 0)
    {
        OrigPostMessageW = (PostMessageW_z)GetProcAddress(hModule, "PostMessageW");
		if (OrigPostMessageW != 0) {
			return OrigPostMessageW(hWnd, Msg, wParam, lParam);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) DWORD cdecl GetWindowThreadProcessId(_In_      HWND    hWnd,_Out_opt_ LPDWORD lpdwProcessId);
__declspec(dllexport) DWORD cdecl GetWindowThreadProcessId(_In_      HWND    hWnd,_Out_opt_ LPDWORD lpdwProcessId){
	typedef DWORD (__stdcall *GetWindowThreadProcessId_z)(HWND, LPDWORD);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetWindowThreadProcessId_z OrigGetWindowThreadProcessId = 0;
    if(hModule != 0)
    {
        OrigGetWindowThreadProcessId = (GetWindowThreadProcessId_z)GetProcAddress(hModule, "GetWindowThreadProcessId");
		if (OrigGetWindowThreadProcessId != 0) {
			return OrigGetWindowThreadProcessId(hWnd, lpdwProcessId);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl GetClassInfoW(__in_opt HINSTANCE hInstance,__in LPCWSTR lpClassName,__out LPWNDCLASSW lpWndClass);
__declspec(dllexport) BOOL cdecl GetClassInfoW(__in_opt HINSTANCE hInstance,__in LPCWSTR lpClassName,__out LPWNDCLASSW lpWndClass){
	typedef BOOL (__stdcall *GetClassInfoW_z)(HINSTANCE, LPCWSTR, LPWNDCLASSW);	
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetClassInfoW_z OrigGetClassInfoW = 0;
    if(hModule != 0)
    {
        OrigGetClassInfoW = (GetClassInfoW_z)GetProcAddress(hModule, "GetClassInfoW");
		if (OrigGetClassInfoW != 0) {
			return OrigGetClassInfoW(hInstance, lpClassName, lpWndClass);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HWND cdecl GetActiveWindow(void);
__declspec(dllexport) HWND cdecl GetActiveWindow(void){
	typedef HWND (__stdcall *GetActiveWindow_z)(void);	
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetActiveWindow_z OrigGetActiveWindow = 0;
    if(hModule != 0)
    {
        OrigGetActiveWindow = (GetActiveWindow_z)GetProcAddress(hModule, "GetActiveWindow");
		if (OrigGetActiveWindow != 0) {
			return OrigGetActiveWindow();
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HWND cdecl GetFocus(void);
__declspec(dllexport) HWND cdecl GetFocus(void){
	typedef HWND (__stdcall *GetFocus_z)(void);	
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetFocus_z OrigGetFocus = 0;
    if(hModule != 0)
    {
        OrigGetFocus = (GetFocus_z)GetProcAddress(hModule, "GetFocus");
		if (OrigGetFocus != 0) {
			return OrigGetFocus();
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HKL cdecl LoadKeyboardLayoutW(__in LPCWSTR pwszKLID,__in UINT Flags);
__declspec(dllexport) HKL cdecl LoadKeyboardLayoutW(__in LPCWSTR pwszKLID,__in UINT Flags){
	typedef HKL (__stdcall *LoadKeyboardLayoutW_z)(LPCWSTR, UINT);	
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	LoadKeyboardLayoutW_z OrigLoadKeyboardLayoutW = 0;
    if(hModule != 0)
    {
        OrigLoadKeyboardLayoutW = (LoadKeyboardLayoutW_z)GetProcAddress(hModule, "LoadKeyboardLayoutW");
		if (OrigLoadKeyboardLayoutW != 0) {
			return OrigLoadKeyboardLayoutW(pwszKLID, Flags);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) void* cdecl User32InitializeImmEntryTable();
__declspec(dllexport) void* cdecl User32InitializeImmEntryTable(){
	typedef void* (cdecl *User32InitializeImmEntryTable_z)();	
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	User32InitializeImmEntryTable_z OrigUser32InitializeImmEntryTable = 0;
	void* result;
    if(hModule != 0)
    {
        OrigUser32InitializeImmEntryTable = (User32InitializeImmEntryTable_z)GetProcAddress(hModule, "User32InitializeImmEntryTable");
		if (OrigUser32InitializeImmEntryTable != 0) {
			result =  OrigUser32InitializeImmEntryTable();
			return result;
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HCURSOR cdecl SetCursor(_In_opt_ HCURSOR hCursor);
__declspec(dllexport) HCURSOR cdecl SetCursor(_In_opt_ HCURSOR hCursor){
	typedef HCURSOR (__stdcall *SetCursor_z)(HCURSOR);	
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	SetCursor_z OrigSetCursor = 0;
    if(hModule != 0)
    {
        OrigSetCursor = (SetCursor_z)GetProcAddress(hModule, "SetCursor");
		if (OrigSetCursor != 0) {
			return OrigSetCursor(hCursor);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) HBITMAP cdecl LoadBitmapW(__in_opt HINSTANCE hInstance,__in LPCWSTR lpBitmapName);
__declspec(dllexport) HBITMAP cdecl LoadBitmapW(__in_opt HINSTANCE hInstance,__in LPCWSTR lpBitmapName){
	typedef HBITMAP (__stdcall *LoadBitmapW_z)(HINSTANCE, LPCWSTR);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	LoadBitmapW_z OrigLoadBitmapW = 0;
    if(hModule != 0)
    {
        OrigLoadBitmapW = (LoadBitmapW_z)GetProcAddress(hModule, "LoadBitmapW");
		if (OrigLoadBitmapW != 0) {
			return OrigLoadBitmapW(hInstance, lpBitmapName);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) int cdecl DrawTextExW(__in HDC hdc,__inout_ecount_opt(cchText) LPWSTR lpchText,__in int cchText,__inout LPRECT lprc,__in UINT format,__in_opt LPDRAWTEXTPARAMS lpdtp);
__declspec(dllexport) int cdecl DrawTextExW(__in HDC hdc,__inout_ecount_opt(cchText) LPWSTR lpchText,__in int cchText,__inout LPRECT lprc,__in UINT format,__in_opt LPDRAWTEXTPARAMS lpdtp){
	typedef int (__stdcall *DrawTextExW_z)(HDC, LPWSTR, int, LPRECT, UINT, LPDRAWTEXTPARAMS);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	DrawTextExW_z OrigDrawTextExW = 0;
    if(hModule != 0)
    {
        OrigDrawTextExW = (DrawTextExW_z)GetProcAddress(hModule, "DrawTextExW");
		if (OrigDrawTextExW != 0) {
			return OrigDrawTextExW(hdc, lpchText, cchText, lprc, format, lpdtp);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) HWND cdecl SetCapture(  _In_ HWND hWnd );
__declspec(dllexport) HWND cdecl SetCapture(  _In_ HWND hWnd ){
	typedef HWND (__stdcall *SetCapture_z)(HWND);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	SetCapture_z OrigSetCapture = 0;
    if(hModule != 0)
    {
        OrigSetCapture = (SetCapture_z)GetProcAddress(hModule, "SetCapture");
		if (OrigSetCapture != 0) {
			return OrigSetCapture(hWnd);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl ScreenToClient(  _In_ HWND    hWnd,       LPPOINT lpPoint);
__declspec(dllexport) BOOL cdecl ScreenToClient(  _In_ HWND    hWnd,       LPPOINT lpPoint){
	typedef BOOL (__stdcall *ScreenToClient_z)(HWND,LPPOINT);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	ScreenToClient_z OrigScreenToClient = 0;
    if(hModule != 0)
    {
        OrigScreenToClient = (ScreenToClient_z)GetProcAddress(hModule, "ScreenToClient");
		if (OrigScreenToClient != 0) {
			return OrigScreenToClient(hWnd, lpPoint);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) BOOL cdecl GetCursorPos( _Out_ LPPOINT lpPoint);
__declspec(dllexport) BOOL cdecl GetCursorPos( _Out_ LPPOINT lpPoint){
	typedef BOOL (__stdcall *GetCursorPos_z)(LPPOINT);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetCursorPos_z OrigGetCursorPos = 0;
    if(hModule != 0)
    {
        OrigGetCursorPos = (GetCursorPos_z)GetProcAddress(hModule, "GetCursorPos");
		if (OrigGetCursorPos != 0) {
			return OrigGetCursorPos(lpPoint);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl SetRect(  _Out_ LPRECT lprc,  _In_  int    xLeft,  _In_  int    yTop,  _In_  int    xRight,  _In_  int    yBottom);
__declspec(dllexport) BOOL cdecl SetRect(  _Out_ LPRECT lprc,  _In_  int    xLeft,  _In_  int    yTop,  _In_  int    xRight,  _In_  int    yBottom){
	typedef BOOL (__stdcall *SetRect_z)(LPRECT, int, int, int, int);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	SetRect_z OrigSetRect = 0;
    if(hModule != 0)
    {
        OrigSetRect = (SetRect_z)GetProcAddress(hModule, "SetRect");
		if (OrigSetRect != 0) {
			return OrigSetRect(lprc, xLeft, yTop,xRight, yBottom);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) DWORD cdecl GetSysColor(_In_ int nIndex);
__declspec(dllexport) DWORD cdecl GetSysColor(_In_ int nIndex){
	typedef DWORD (__stdcall *GetSysColor_z)(int);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetSysColor_z OrigGetSysColor = 0;
    if(hModule != 0)
    {
        OrigGetSysColor = (GetSysColor_z)GetProcAddress(hModule, "GetSysColor");
		if (OrigGetSysColor != 0) {
			return OrigGetSysColor(nIndex);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) LPWSTR cdecl CharUpperW( __inout LPWSTR lpsz);
__declspec(dllexport)  LPWSTR cdecl CharUpperW( __inout LPWSTR lpsz){
	typedef LPWSTR (__stdcall *CharUpperW_z)(LPWSTR);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	CharUpperW_z OrigCharUpperW = 0;
    if(hModule != 0)
    {
        OrigCharUpperW = (CharUpperW_z)GetProcAddress(hModule, "CharUpperW");
		if (OrigCharUpperW != 0) {
			return OrigCharUpperW(lpsz);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl SetProcessDefaultLayout(  _In_ DWORD dwDefaultLayout);
__declspec(dllexport) BOOL cdecl SetProcessDefaultLayout(  _In_ DWORD dwDefaultLayout){
	typedef BOOL (__stdcall *SetProcessDefaultLayout_z)(DWORD);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	SetProcessDefaultLayout_z OrigSetProcessDefaultLayout = 0;
    if(hModule != 0)
    {
        OrigSetProcessDefaultLayout = (SetProcessDefaultLayout_z)GetProcAddress(hModule, "SetProcessDefaultLayout");
		if (OrigSetProcessDefaultLayout != 0) {
			return OrigSetProcessDefaultLayout(dwDefaultLayout);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HKL cdecl GetKeyboardLayout(  _In_ DWORD idThread);
__declspec(dllexport) HKL cdecl GetKeyboardLayout(  _In_ DWORD idThread){
	typedef HKL (__stdcall *GetKeyboardLayout_z)(DWORD);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetKeyboardLayout_z OrigGetKeyboardLayout = 0;
	
    if(hModule != 0)
    {
        OrigGetKeyboardLayout = (GetKeyboardLayout_z)GetProcAddress(hModule, "GetKeyboardLayout");
		if (OrigGetKeyboardLayout != 0) {
			return OrigGetKeyboardLayout(idThread);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl CreateCaret(  _In_     HWND    hWnd,  _In_opt_ HBITMAP hBitmap,  _In_     int     nWidth,  _In_     int     nHeight);
__declspec(dllexport) BOOL cdecl CreateCaret(  _In_     HWND    hWnd,  _In_opt_ HBITMAP hBitmap,  _In_     int     nWidth,  _In_     int     nHeight){
	typedef BOOL (__stdcall *CreateCaret_z)(HWND, HBITMAP, int, int);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	CreateCaret_z OrigCreateCaret = 0;
	
    if(hModule != 0)
    {
        OrigCreateCaret = (CreateCaret_z)GetProcAddress(hModule, "CreateCaret");
		if (OrigCreateCaret != 0) {
			return OrigCreateCaret(hWnd, hBitmap, nWidth, nHeight);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl EnableMenuItem(  _In_ HMENU hMenu,  _In_ UINT  uIDEnableItem,  _In_ UINT  uEnable);
__declspec(dllexport) BOOL cdecl EnableMenuItem(  _In_ HMENU hMenu,  _In_ UINT  uIDEnableItem,  _In_ UINT  uEnable){
	typedef BOOL (__stdcall *EnableMenuItem_z)(HMENU, UINT, UINT);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	EnableMenuItem_z OrigEnableMenuItem = 0;
	
    if(hModule != 0)
    {
        OrigEnableMenuItem = (EnableMenuItem_z)GetProcAddress(hModule, "EnableMenuItem");
		if (OrigEnableMenuItem != 0) {
			return OrigEnableMenuItem(hMenu, uIDEnableItem, uEnable);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) DWORD cdecl CheckMenuItem(  _In_ HMENU hmenu,  _In_ UINT  uIDCheckItem,  _In_ UINT  uCheck);
__declspec(dllexport) DWORD cdecl CheckMenuItem(  _In_ HMENU hmenu,  _In_ UINT  uIDCheckItem,  _In_ UINT  uCheck){
	typedef DWORD (__stdcall *CheckMenuItem_z)(HMENU, UINT, UINT);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	CheckMenuItem_z OrigCheckMenuItem = 0;
	
    if(hModule != 0)
    {
        OrigCheckMenuItem = (CheckMenuItem_z)GetProcAddress(hModule, "CheckMenuItem");
		if (OrigCheckMenuItem != 0) {
			return OrigCheckMenuItem(hmenu, uIDCheckItem, uCheck);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) BOOL cdecl GetClientRect( _In_  HWND   hWnd,  _Out_ LPRECT lpRect );
__declspec(dllexport) BOOL cdecl GetClientRect( _In_  HWND   hWnd,  _Out_ LPRECT lpRect ){
	typedef BOOL (__stdcall *GetClientRect_z)(HWND, LPRECT);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetClientRect_z OrigGetClientRect = 0;
	
    if(hModule != 0)
    {
        OrigGetClientRect = (GetClientRect_z)GetProcAddress(hModule, "GetClientRect");
		if (OrigGetClientRect != 0) {
			return OrigGetClientRect(hWnd, lpRect);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) int cdecl GetSystemMetrics(  _In_ int nIndex );
__declspec(dllexport) int cdecl GetSystemMetrics(  _In_ int nIndex ){
	typedef int (__stdcall *GetSystemMetrics_z)(int);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetSystemMetrics_z OrigGetSystemMetrics = 0;
	
    if(hModule != 0)
    {
        OrigGetSystemMetrics = (GetSystemMetrics_z)GetProcAddress(hModule, "GetSystemMetrics");
		if (OrigGetSystemMetrics != 0) {
			return OrigGetSystemMetrics(nIndex);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl InflateRect(  _Inout_ LPRECT lprc,  _In_    int    dx,  _In_    int    dy );
__declspec(dllexport) BOOL cdecl InflateRect(  _Inout_ LPRECT lprc,  _In_    int    dx,  _In_    int    dy ){
	typedef BOOL (__stdcall *InflateRect_z)(LPRECT, int, int);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	InflateRect_z OrigInflateRect = 0;
	
    if(hModule != 0)
    {
        OrigInflateRect = (InflateRect_z)GetProcAddress(hModule, "InflateRect");
		if (OrigInflateRect != 0) {
			return OrigInflateRect(lprc, dx, dy);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) BOOL cdecl InvalidateRect(  _In_ HWND hWnd,  _In_ const RECT *lpRect, _In_ BOOL bErase );
__declspec(dllexport) BOOL cdecl InvalidateRect(  _In_ HWND hWnd,  _In_ const RECT *lpRect, _In_ BOOL bErase ){
	typedef BOOL (__stdcall *InvalidateRect_z)(HWND, const RECT, BOOL);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	InvalidateRect_z OrigInvalidateRect = 0;
	
    if(hModule != 0)
    {
        OrigInvalidateRect = (InvalidateRect_z)GetProcAddress(hModule, "InvalidateRect");
		if (OrigInvalidateRect != 0) {
			return OrigInvalidateRect(hWnd, *lpRect, bErase);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) LRESULT cdecl SendMessageA(  _In_ HWND   hWnd,  _In_ UINT   Msg,  _In_ WPARAM wParam, _In_ LPARAM lParam );
__declspec(dllexport) LRESULT cdecl SendMessageA(  _In_ HWND   hWnd,  _In_ UINT   Msg,  _In_ WPARAM wParam, _In_ LPARAM lParam ){
	typedef LRESULT (__stdcall *SendMessageA_z)(HWND, UINT, WPARAM, LPARAM);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	SendMessageA_z OrigSendMessageA = 0;
	
    if(hModule != 0)
    {
        OrigSendMessageA = (SendMessageA_z)GetProcAddress(hModule, "SendMessageA");
		if (OrigSendMessageA != 0) {
			return OrigSendMessageA(hWnd, Msg, wParam, lParam);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) LRESULT cdecl SendMessageW(  _In_ HWND   hWnd,  _In_ UINT   Msg,  _In_ WPARAM wParam, _In_ LPARAM lParam );
__declspec(dllexport) LRESULT cdecl SendMessageW(  _In_ HWND   hWnd,  _In_ UINT   Msg,  _In_ WPARAM wParam, _In_ LPARAM lParam ){
	typedef LRESULT (__stdcall *SendMessageW_z)(HWND, UINT, WPARAM, LPARAM);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	SendMessageW_z OrigSendMessageW = 0;
	
    if(hModule != 0)
    {
        OrigSendMessageW = (SendMessageW_z)GetProcAddress(hModule, "SendMessageW");
		if (OrigSendMessageW != 0) {
			return OrigSendMessageW(hWnd, Msg, wParam, lParam);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl MessageBeep( _In_ UINT uType );
__declspec(dllexport) BOOL cdecl MessageBeep( _In_ UINT uType ){
	typedef BOOL (__stdcall *MessageBeep_z)(UINT);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	MessageBeep_z OrigMessageBeep = 0;
	
    if(hModule != 0)
    {
        OrigMessageBeep = (MessageBeep_z)GetProcAddress(hModule, "MessageBeep");
		if (OrigMessageBeep != 0) {
			return OrigMessageBeep(uType);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) LONG cdecl GetWindowLongW(  _In_ HWND hWnd, _In_ int  nIndex );
__declspec(dllexport) LONG cdecl GetWindowLongW(  _In_ HWND hWnd, _In_ int  nIndex ){
	typedef LONG (__stdcall *GetWindowLongW_z)(HWND, int);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetWindowLongW_z OrigGetWindowLongW = 0;
	
    if(hModule != 0)
    {
        OrigGetWindowLongW = (GetWindowLongW_z)GetProcAddress(hModule, "GetWindowLongW");
		if (OrigGetWindowLongW != 0) {
			return OrigGetWindowLongW(hWnd, nIndex);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) LONG cdecl SetWindowLongW (_In_ HWND hWnd, _In_ int  nIndex, _In_ LONG dwNewLong);
__declspec(dllexport) LONG cdecl SetWindowLongW (_In_ HWND hWnd, _In_ int  nIndex, _In_ LONG dwNewLong){
	typedef LONG (__stdcall *SetWindowLongW_z)(HWND, int, LONG);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	SetWindowLongW_z OrigSetWindowLongW = 0;
	
    if(hModule != 0)
    {
        OrigSetWindowLongW = (SetWindowLongW_z)GetProcAddress(hModule, "SetWindowLongW");
		if (OrigSetWindowLongW != 0) {
			return OrigSetWindowLongW(hWnd, nIndex, dwNewLong);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) VOID cdecl InitializeLpkHooks (PUSER32_INTERN_INITIALIZEHOOKS zk);

__declspec(dllexport) VOID cdecl InitializeLpkHooks (PUSER32_INTERN_INITIALIZEHOOKS zk){
	typedef VOID (__stdcall *InitializeLpkHooks_z)(PUSER32_INTERN_INITIALIZEHOOKS);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	InitializeLpkHooks_z OrigInitializeLpkHooks = 0;
	
    if(hModule != 0)
    {
        OrigInitializeLpkHooks = (InitializeLpkHooks_z)GetProcAddress(hModule, "InitializeLpkHooks");
		if (OrigInitializeLpkHooks != 0) {
			OrigInitializeLpkHooks(zk);
		}
    }
	return;

}
extern "C" __declspec(dllexport) int cdecl GetKeyboardLayoutList(_In_  int nBuff, _Out_ HKL *lpList );
__declspec(dllexport) int cdecl GetKeyboardLayoutList(_In_  int nBuff, _Out_ HKL *lpList){
	typedef int (__stdcall *GetKeyboardLayoutList_z)(int, HKL);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetKeyboardLayoutList_z OrigGetKeyboardLayoutList = 0;
	
    if(hModule != 0)
    {
        OrigGetKeyboardLayoutList = (GetKeyboardLayoutList_z)GetProcAddress(hModule, "GetKeyboardLayoutList");
		if (OrigGetKeyboardLayoutList != 0) {
			return OrigGetKeyboardLayoutList(nBuff, *lpList);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) BOOL cdecl GetWindowRect( _In_  HWND   hWnd,  _Out_ LPRECT lpRect );
__declspec(dllexport) BOOL cdecl GetWindowRect( _In_  HWND   hWnd,  _Out_ LPRECT lpRect ){
	typedef BOOL (__stdcall *GetWindowRect_z)(HWND, LPRECT);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetWindowRect_z OrigGetWindowRect = 0;
	
    if(hModule != 0)
    {
        OrigGetWindowRect = (GetWindowRect_z)GetProcAddress(hModule, "GetWindowRect");
		if (OrigGetWindowRect != 0) {
			return OrigGetWindowRect(hWnd, lpRect);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) DWORD cdecl GetAppCompatFlags2( HTASK hTask );
__declspec(dllexport) DWORD cdecl GetAppCompatFlags2( HTASK hTask ){
	typedef int (__stdcall *GetAppCompatFlags2_z)(HTASK);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetAppCompatFlags2_z OrigGetAppCompatFlags2 = 0;
	
    if(hModule != 0)
    {
        OrigGetAppCompatFlags2 = (GetAppCompatFlags2_z)GetProcAddress(hModule, "GetAppCompatFlags2");
		if (OrigGetAppCompatFlags2 != 0) {
			return OrigGetAppCompatFlags2(hTask);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) DWORD cdecl UserRealizePalette2 (HDC hDC);
__declspec(dllexport) DWORD cdecl UserRealizePalette2 (HDC hDC){
	typedef DWORD (__stdcall *UserRealizePalette2_z)(HDC);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	UserRealizePalette2_z OrigUserRealizePalette2 = 0;
	
    if(hModule != 0)
    {
        OrigUserRealizePalette2 = (UserRealizePalette2_z)GetProcAddress(hModule, "UserRealizePalette2");
		if (OrigUserRealizePalette2 != 0) {
			return OrigUserRealizePalette2(hDC);
		}
    }
	return 0;
}


extern "C" __declspec(dllexport) UINT cdecl UserRealizePalette (HDC hDC);
__declspec(dllexport) UINT cdecl UserRealizePalette (HDC hDC){
	typedef UINT (__stdcall *UserRealizePalette_z)(HDC);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	UserRealizePalette_z OrigUserRealizePalette = 0;
	
    if(hModule != 0)
    {
        OrigUserRealizePalette = (UserRealizePalette_z)GetProcAddress(hModule, "UserRealizePalette");
		if (OrigUserRealizePalette != 0) {
			return OrigUserRealizePalette(hDC);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) DWORD cdecl GetAppCompatFlags( HTASK hTask );
__declspec(dllexport) DWORD cdecl GetAppCompatFlags( HTASK hTask ){
	typedef int (__stdcall *GetAppCompatFlags_z)(HTASK);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetAppCompatFlags_z OrigGetAppCompatFlags = 0;
	
    if(hModule != 0)
    {
        OrigGetAppCompatFlags = (GetAppCompatFlags_z)GetProcAddress(hModule, "GetAppCompatFlags");
		if (OrigGetAppCompatFlags != 0) {
			return OrigGetAppCompatFlags(hTask);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) int cdecl ReleaseDC(    __in_opt HWND hWnd,    __in HDC hDC);
__declspec(dllexport) int cdecl ReleaseDC(    __in_opt HWND hWnd,    __in HDC hDC){
	typedef int (__stdcall *ReleaseDC_z)(HWND, HDC);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	ReleaseDC_z OrigReleaseDC = 0;
	
    if(hModule != 0)
    {
        OrigReleaseDC = (ReleaseDC_z)GetProcAddress(hModule, "ReleaseDC");
		if (OrigReleaseDC != 0) {
			return OrigReleaseDC(hWnd, hDC);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) DWORD cdecl CharLowerBuffW( __inout_ecount(cchLength) LPWSTR lpsz,  __in DWORD cchLength);

__declspec(dllexport)  DWORD cdecl CharLowerBuffW( __inout_ecount(cchLength) LPWSTR lpsz,  __in DWORD cchLength){
	typedef DWORD (__stdcall *CharLowerBuffW_z)(LPWSTR, DWORD);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	CharLowerBuffW_z OrigCharLowerBuffW = 0;
	
    if(hModule != 0)
    {
        OrigCharLowerBuffW = (CharLowerBuffW_z)GetProcAddress(hModule, "CharLowerBuffW");
		if (OrigCharLowerBuffW != 0) {
			return OrigCharLowerBuffW(lpsz, cchLength);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl IntersectRect( __out LPRECT lprcDst,__in CONST RECT *lprcSrc1,__in CONST RECT *lprcSrc2);
__declspec(dllexport) BOOL cdecl IntersectRect( __out LPRECT lprcDst,__in CONST RECT *lprcSrc1,__in CONST RECT *lprcSrc2){
	typedef BOOL (__stdcall *IntersectRect_z)(LPRECT, CONST RECT, CONST RECT);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	IntersectRect_z OrigIntersectRect = 0;
	
    if(hModule != 0)
    {
        OrigIntersectRect = (IntersectRect_z)GetProcAddress(hModule, "IntersectRect");
		if (OrigIntersectRect != 0) {
			return OrigIntersectRect(lprcDst, *lprcSrc1, *lprcSrc2);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) HDC cdecl GetDC(    __in_opt HWND hWnd);

__declspec(dllexport)  HDC cdecl GetDC(    __in_opt HWND hWnd){
	typedef HDC (__stdcall *GetDC_z)(HWND);
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	GetDC_z OrigGetDC = 0;
	
    if(hModule != 0)
    {
        OrigGetDC = (GetDC_z)GetProcAddress(hModule, "GetDC");
		if (OrigGetDC != 0) {
			return OrigGetDC(hWnd);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) BOOL cdecl IsThreadDesktopComposited();
__declspec(dllexport) BOOL cdecl IsThreadDesktopComposited(){
	typedef BOOL (__stdcall *IsThreadDesktopComposited_z)();
	HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
	IsThreadDesktopComposited_z OrigIsThreadDesktopComposited = 0;
    if(hModule != 0)
    {
        OrigIsThreadDesktopComposited = (IsThreadDesktopComposited_z)GetProcAddress(hModule, "IsThreadDesktopComposited");
		if (OrigIsThreadDesktopComposited != 0) {
			return OrigIsThreadDesktopComposited();
		}
    }
	return FALSE;
}
extern "C" __declspec(dllexport) DWORD cdecl CharUpperBuffA(
    __inout_ecount(cchLength) LPSTR lpsz,
    __in DWORD cchLength);

__declspec(dllexport) DWORD cdecl CharUpperBuffA(
    __inout_ecount(cchLength) LPSTR lpsz,
    __in DWORD cchLength){
		typedef DWORD (__stdcall *CharUpperBuffA_z)(LPSTR, DWORD);
		HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
		CharUpperBuffA_z OrigCharUpperBuffA = 0;

    if(hModule != 0)
    {
        OrigCharUpperBuffA = (CharUpperBuffA_z)GetProcAddress(hModule, "CharUpperBuffA");
		if (OrigCharUpperBuffA != 0) {
			return OrigCharUpperBuffA(lpsz, cchLength);
		}
    }
	return 0;
}

extern "C" __declspec(dllexport) int cdecl MessageBoxA(
    __in_opt HWND hWnd,
    __in_opt LPCSTR lpText,
    __in_opt LPCSTR lpCaption,
    __in UINT uType);

 __declspec(dllexport) int cdecl MessageBoxA(
    __in_opt HWND hWnd,
    __in_opt LPCSTR lpText, 
    __in_opt LPCSTR lpCaption,
    __in UINT uType){
		typedef int (__stdcall *msgbox)(HWND, LPCSTR, LPCSTR, UINT);
		int result = 0;
		
		HMODULE hModule = LoadLibraryA("c:\\windows\\system32\\user32.dll");
		msgbox OrigMessageBoxA = 0;

    if(hModule != 0)
    {
        OrigMessageBoxA = (msgbox)GetProcAddress(hModule, "MessageBoxA");
		
		/*
		FILE * pFile;
		char buffer[64] = {0};
		pFile = fopen ("myfile.bin", "wb");
		fprintf(pFile, "MessageBoxA\r\n");
		fclose (pFile);
		*/
		if (OrigMessageBoxA != 0) {
			result = OrigMessageBoxA(0,"Hi","lol",0);

		}
    }
		return result;
}



BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

