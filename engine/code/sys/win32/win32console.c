#include "../../shared.h"

#ifdef CS_WIN32_DEFINED

#include "../sys.h"
#include <string.h>

// #define EDIT_ID			100

#include "win32shared.h"

HWND g_hConsoleWin;
HWND g_hScrollBuffer;

void Sys_ConsolePrint( const char *msg )
{
    #define BUFFER_SIZE     10000
    char buffer[BUFFER_SIZE];
    char *bufferPtr = buffer;

    Sys_Memset( buffer, 0, BUFFER_SIZE );
    for ( int i = 0; msg[i] && ( bufferPtr - buffer ) < sizeof( buffer ) - 1; i++ ) {
        if ( msg[i] == '\n' ) {
            bufferPtr[0] = '\r';
            bufferPtr[1] = '\n';
            bufferPtr+=2;
        }
        else if ( IsColoredText(&msg[i]) ) {
            i++;
        }
        else {
            *bufferPtr = msg[i];
            bufferPtr++;
        }
    }

	// SendMessage( g_hScrollBuffer, EM_LINESCROLL, 0, 0xffff );
	// SendMessage( g_hScrollBuffer, EM_SCROLLCARET, 0, 0 );
	SendMessage( g_hScrollBuffer, EM_REPLACESEL, 0, (LPARAM)buffer );

    #undef BUFFER_SIZE
}

static LONG WINAPI ConsoleWndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
    switch ( uMsg ) {
        case WM_CREATE:
            // SetBkColor( (HDC)wParam, RGB( 0x00, 0x00, 0xb0 ) );
            return 0;
        case WM_CLOSE:
            PostQuitMessage( 0 );
            return 0;
    }

    return DefWindowProc( hWnd, uMsg, wParam, lParam );
}

// console for logging messages
void Sys_CreateConsole()
{
    RECT winRect;
    WNDCLASS wc;
    DWORD dwStyle;
    HINSTANCE hInstance;
    
    hInstance = GetModuleHandle( NULL );

    memset( &wc, 0, sizeof( wc ) );
    wc.lpfnWndProc      = (WNDPROC)ConsoleWndProc;
    wc.hInstance        = hInstance;
    wc.hCursor          = LoadCursor( NULL, IDC_ARROW );
    wc.hbrBackground    = (void*)COLOR_WINDOW;
    wc.hIcon            = LoadIcon( hInstance, IDI_APPLICATION );
    wc.lpszClassName    = "Logger Console";

    if ( !RegisterClass(&wc) ) {
        MessageBox( NULL, "Sys_CreateConsole: Can't register window class", "Warning", MB_ICONWARNING );
        return;
    }

    winRect.left = 0;
    winRect.right = 600;
    winRect.top = 0;
    winRect.bottom = 600;

    dwStyle = WS_POPUPWINDOW | WS_CAPTION | WS_MINIMIZEBOX;
    AdjustWindowRect( &winRect, dwStyle, FALSE );

    g_hConsoleWin = CreateWindowEx(
            0,
            "Logger Console",
            "Logger Console",
            dwStyle,
            0, 0, winRect.right - winRect.left, winRect.bottom - winRect.top,
            NULL,
            NULL,
            hInstance,
            NULL );

    if ( !g_hConsoleWin ) {
        MessageBox( NULL, "Sys_CreateConsole: Can't register console window", "Warning", MB_ICONWARNING );
        return;
    }

   	g_hScrollBuffer = CreateWindow( 
            "edit",
            NULL,
            WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL | ES_READONLY,
		    25, 25, winRect.right - 50, winRect.bottom - 50,
			g_hConsoleWin, 
			// (HMENU)EDIT_ID,
            NULL,
			hInstance,
            NULL );
	
    if ( !g_hScrollBuffer ) {
        MessageBox( NULL, "Sys_CreateConsole: Can't create scroll buffer", "Warning", MB_ICONWARNING );
        return;
    }

    // SendMessage( g_hScrollBuffer, WM_SETFONT, ( WPARAM ) g_hFont, 0 ); 

    ShowWindow( g_hConsoleWin, SW_SHOWDEFAULT );
}

void Sys_QuitConsole()
{
    if ( g_hConsoleWin ) {
        DestroyWindow( g_hConsoleWin );
        g_hConsoleWin = NULL;
    }
}

#endif