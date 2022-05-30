#include "../../shared.h"

#ifdef CS_WIN32_DEFINED
#include "../sys.h"
#include "resource.h"
#include "core/io/logger.h"
#include "core/c_memory.h"
#include "win32shared.h"

#include <stdlib.h>

// static vulkanContext_t context;

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

void *Sys_MemSet( void *str, int c, size_t n )
{
    // tmp
    return memset( str, c, n );
}

void Sys_Sleep( unsigned long ms )
{
    Sleep( ms );
}

static LARGE_INTEGER startTime;
static double clkFrequency;

void Sys_InitTime()
{
    LARGE_INTEGER freq;
    QueryPerformanceFrequency( &freq );
    QueryPerformanceFrequency( &startTime );
    clkFrequency = (double)1 / freq.QuadPart;
}

double Sys_GetTimeMS()
{
    LARGE_INTEGER now;

    if ( !clkFrequency ) {
        Sys_InitTime();
    }
    QueryPerformanceCounter( &now );

    return (double)now.QuadPart * clkFrequency;
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

cbool Sys_CreateWindow( sysState_t *state, int width, int height, char *winTitle, cbool fullscreen )
{
    // memoryTag_t t; // tmp

    if ( !winState.hInstance ) {
        WNDCLASS wc;
        RECT winRect;
        DWORD dwStyle;
        DWORD exStyle;

        // for ( int i = 0; i < 100; i++ ) {
        //     Log_Printf( ERRTYPE_MESSAGE, "hel^3lo %d\n", i );
        // }

        // for ( int i = 0; i < NUM_MEMTAGS; i++ ) {
        //     Log_Printf( ERRTYPE_MESSAGE, "%s\n", memTagsStr[i] );
        // }

        winState.hInstance = GetModuleHandle( NULL );

        C_MemSet( &wc, 0, sizeof(wc) );
        wc.lpfnWndProc      = Main_WndProc;
        wc.hInstance        = winState.hInstance;
        wc.hCursor          = LoadCursor( NULL, IDC_ARROW );
        wc.hIcon            = LoadIcon(  winState.hInstance, MAKEINTRESOURCE(IDI_CSICON) );
        wc.lpszClassName    = CLASS_NAME;

        if ( !RegisterClass(&wc) ) {
            Log_Printf( ERRTYPE_FATAL, "Sys_CreateWindow: Can't register window class\n" );
            return cfalse;
        }

        winRect.left = 0;
        winRect.top = 0;
        winRect.right = width;
        winRect.bottom = height;

        if ( fullscreen ) {
            exStyle = WS_EX_TOPMOST;
            dwStyle = WS_POPUP | WS_VISIBLE;
        }
        else {
            exStyle = 0;
            dwStyle = WS_OVERLAPPEDWINDOW; //WS_OVERLAPPED | WS_BORDER | WS_CAPTION | WS_VISIBLE;
            AdjustWindowRect( &winRect, dwStyle, FALSE );
        }

        winState.hWnd = CreateWindowEx(
            exStyle, 
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

        Win32GL_Setup(); // tmp

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
    Win32GL_Shutdown();
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
        case WM_CREATE:
            return 0;
        case WM_DESTROY:
            // Sys_Clean( NULL );
            Sys_QuitConsole();
            PostQuitMessage( 0 );
            // exit(0);
            return 0;
        // case WM_RESIZE:
        //     return 0;
        case WM_MOUSEMOVE:
            return 0;
        case WM_MOUSEWHEEL:
            return 0;
    }

    return DefWindowProc( hWnd, uMsg, wParam, lParam );
}

cbool Sys_CreateContext( sysState_t *state )
{
    return ctrue;
}

#endif