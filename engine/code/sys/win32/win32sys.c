#include "../../shared.h"

#ifdef CS_WIN32_DEFINED
#include "../sys.h"
#include "core/io/logger.h"
#include "win32shared.h"

#include <stdlib.h>

// static double clkFreq;
// static LARGE_INTEGER startTime;

winState_t winState;

static LRESULT CALLBACK Main_WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

void *Sys_Alloc( size_t size, cbool aligned )
{
    // tmp
    return malloc( size );
}

void Sys_Free( void *ptr, cbool aligned )
{
    // tmp
    free( ptr );
}

void *Sys_MemCpy( void *dst, const void *src, size_t size )
{
    // tmp
    return memcpy( dst, src, size );
}

void *Sys_Memset( void *str, int c, size_t n )
{
    // tmp
    return memset( str, c, n );
}

void Sys_Sleep( unsigned long ms )
{
    Sleep( ms );
}

// LARGE_INTEGER startTime;

double Sys_GetTime()
{
    // LARGE_INTEGER now;
    // LARGE_INTEGER freq;
    // double clkPeriod;

    // if ( !frequency ) {
    //     QueryPerformanceFrequency( &freq );
    //     clkPeriod = 1.0 / (double)freq.QuadPart;
    //     // QueryPerformanceFrequency( &startTime );
    // }
    // QueryPerformanceCounter( &now );
    // return (double)now.QuadPart * clkPeriod;
    return 0.0;
}

void Sys_PumpEvents()
{
    MSG msg;

    while( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) ) {
        TranslateMessage( &msg );
        DispatchMessage( &msg );
    }
}

const char *CLASS_NAME  = "CS Class";

cbool Sys_CreateWindow( sysState_t *state, int width, int height, char *winTitle )
{
    if ( !winState.hInstance ) {
        WNDCLASS wc;
        RECT winRect;
        DWORD dwStyle;

        Log_Printf( ERRTYPE_MESSAGE, "hello %d\n", 1 );
        Log_Printf( ERRTYPE_TRACE, "hello %d\n", 2 );

        winState.hInstance = GetModuleHandle( NULL );

        Sys_Memset( &wc, 0, sizeof(wc) );
        wc.lpfnWndProc      = Main_WndProc;
        wc.hInstance        = winState.hInstance;
        wc.hCursor          = LoadCursor( NULL, IDC_ARROW );
        wc.hIcon            = LoadIcon( winState.hInstance, IDI_APPLICATION );
        wc.lpszClassName    = CLASS_NAME;

        if ( !RegisterClass(&wc) ) {
            Log_Printf( ERRTYPE_FATAL, "Sys_CreateWindow: Can't register window class\n" );
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
            winTitle,
            dwStyle,
            200, 200, width, height,
            NULL,
            NULL,
            winState.hInstance,
            NULL ); 
    
        if ( !winState.hWnd ) {
            Log_Printf( ERRTYPE_FATAL, "Sys_CreateWindow: Can't create main window\n" );
            return cfalse;
        }

        ShowWindow( winState.hWnd, SW_SHOW );
        return ctrue;
    }
    else {
        Log_Printf( ERRTYPE_WARNING, "Sys_CreateWindow: Main window already created. Nothing to do...\n" );
    }

    return cfalse;
}

void Sys_Clean( sysState_t *state )
{
    Log_Printf( ERRTYPE_MESSAGE, "quitting...\n" );
    Sleep( 2000 );
    if ( winState.hWnd ) {
        DestroyWindow( winState.hWnd );
        winState.hWnd = NULL;
    }
    // A DLL must explicitly unregister its classes when it is unloaded.
    // UnregisterClass( CLASS_NAME, winState.hInstance );
}

LRESULT CALLBACK Main_WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
    switch ( uMsg ) {
        case WM_DESTROY:
            // Sys_Clean( NULL );
            Sys_QuitConsole();
            PostQuitMessage( 0 );
            // exit(0);
            return 0;
    }

    return DefWindowProc( hWnd, uMsg, wParam, lParam );
}

cbool Sys_CreateContext( sysState_t *state )
{
    return ctrue;
}

#endif