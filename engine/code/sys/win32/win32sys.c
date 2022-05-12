#include "../../shared.h"

#ifdef CS_WIN32_DEFINED
#include "../sys.h"
#include "core/io/logger.h"
#include "win32shared.h"

#include <stdlib.h>


winState_t winState;

// static double clkFreq;
// static LARGE_INTEGER startTime;

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

void *Sys_MemCpy( void *dst, const void *src, size_t size )
{
    // tmp
    return memcpy( dst, src, size );
}

void *Sys_MemSet( void *str, int c, size_t n )
{
    // tmp
    return memset( str, c, n );
}

void Sys_Sleep( unsigned long ms )
{
    Sleep( ms );
}

void Sys_PumpEvents()
{
    MSG msg;

    while( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) ) {
        TranslateMessage( &msg );
        DispatchMessage( &msg );
    }
}

void Sys_Init( sysState_t *state )
{
    WNDCLASS wc;
    RECT wndRect;
    DWORD dwStyle;
    // LARGE_INTEGER freq;

    memset( &wc, 0, sizeof(wc) );
    wc.lpfnWndProc      = Main_WndProc;
    wc.hInstance        = winState.hInstance;
    wc.hCursor          = LoadCursor( NULL, IDC_ARROW );
    wc.hIcon            = LoadIcon( winState.hInstance, IDI_APPLICATION );
    wc.lpszClassName    = "CS Class";

    if ( !RegisterClass(&wc) ) {
        //Log_Printf
    }

    wndRect.left = 0;
    wndRect.top = 0;
    wndRect.right = 800;
    wndRect.bottom = 600;

    dwStyle = WS_OVERLAPPEDWINDOW;
    AdjustWindowRect( &wndRect, dwStyle, FALSE );

    winState.hWnd = CreateWindow( 
        "CS Class", "Test Window", dwStyle, 0, 0, 800, 600, NULL, NULL, winState.hInstance, NULL ); 
    
    if ( !winState.hWnd ) {
        //Log_Printf
    }

    ShowWindow( winState.hWnd, SW_SHOW );
    // QueryPerformanceFrequency( &freq );
}

void Sys_Quit( sysState_t *state )
{
    if ( winState.hWnd ) {
        DestroyWindow( winState.hWnd );
    }
}

LRESULT CALLBACK Main_WndProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch ( msg ) {
        case WM_DESTROY:
            // PostQuitMessage( 0 );
            exit(0);
            return 0;
    }

    return DefWindowProc( hWnd, msg, wParam, lParam );
}

#endif