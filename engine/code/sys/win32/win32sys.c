#include "../../shared.h"

#ifdef CS_WIN32_DEFINED
#include "../sys.h"
#include "../core/io/logger.h"

#include <stdlib.h>

#include <windows.h>

typedef struct {
    HWND hWnd;
    HINSTANCE hInstance;
} winState_t;

winState_t winState;

LRESULT CALLBACK Main_WndProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );

void *Sys_Alloc( size_t size, cbool aligned )
{
    // tmp
    return malloc( size );
}

void Sys_Free( void *ptr )
{
    // tmp
    free( ptr );
}

void Sys_PumpEvents()
{
    MSG msg;

    while( PeekMessage(&msg, NULL, 0, 0, PM_REMOVE ) ) {
        TranslateMessage( &msg );
        DispatchMessage( &msg );
    }
}

void Sys_Init( sysState_t *state )
{
    HWND hWnd;
    WNDCLASS wc;
    RECT wndRect;
    DWORD dwStyle;

    memset( &wc, 0, sizeof(wc) );
    wc.lpfnWndProc      = Main_WndProc;
    wc.hInstance        = g_hInstance;
    wc.hCursor          = LoadCursor( NULL, IDC_ARROW );
    wc.hIcon            = LoadIcon( g_hInstance, IDI_APPLICATION );
    wc.lpszClassName    = "CS Class";

    if ( !RegisterClass(&wc) ) {
        //Log_Printf
    }

    dwStyle = WS_OVERLAPPEDWINDOW;
    AdjustWindowRect( &wndRect, dwStyle, FALSE );

    if ( !hWnd ) {
        //Log_Printf
    }
}

#endif