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

#include <stdio.h> //tmp

const char *CLASS_NAME  = "CS Class";

cbool Sys_CreateWindow( sysState_t *state, int width, int height )
{
    WNDCLASS wc;
    RECT winRect;
    DWORD dwStyle;
    // LARGE_INTEGER freq;

    memset( &wc, 0, sizeof(wc) );
    wc.lpfnWndProc      = Main_WndProc;
    wc.hInstance        = winState.hInstance;
    wc.hCursor          = LoadCursor( NULL, IDC_ARROW );
    wc.hIcon            = LoadIcon( winState.hInstance, IDI_APPLICATION );
    wc.lpszClassName    = CLASS_NAME;

    if ( !RegisterClass(&wc) ) {
        //Log_Printf
        printf( "Error: register class ");
        return cfalse;
    }

    winRect.left = 0;
    winRect.top = 0;
    winRect.right = width;
    winRect.bottom = height;

    dwStyle = WS_OVERLAPPEDWINDOW;
    AdjustWindowRect( &winRect, dwStyle, FALSE );

    winState.hWnd = CreateWindowEx(
        0, 
        CLASS_NAME,
        "Test Window",
        dwStyle,
        200, 200, width, height,
        NULL,
        NULL,
        winState.hInstance,
        NULL ); 
    
    if ( !winState.hWnd ) {
        //Log_Printf
        return cfalse;
    }

    ShowWindow( winState.hWnd, SW_SHOW );
    // QueryPerformanceFrequency( &freq );
    
    return ctrue;
}

void Sys_Quit( sysState_t *state )
{
    if ( winState.hWnd ) {
        DestroyWindow( winState.hWnd );
    }
    // A DLL must explicitly unregister its classes when it is unloaded.
    UnregisterClass( CLASS_NAME, winState.hInstance );
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
