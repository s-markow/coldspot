#include "../../shared.h"

#ifdef CS_WIN32_DEFINED

#include "win32shared.h"
#include "core/io/logger.h"
#include "../../renderer/opengl/gldefs.h"
#include "core/c_memory.h"

HDC g_hDC;
HGLRC g_hRC;

typedef HGLRC WINAPI wglCreateContextAttribsARB_t( HDC hDC, HGLRC hRC, const int* attrList );
typedef BOOL WINAPI wglChoosePixelFormatARB_t
        ( HDC hDC, const int* attrIntList, const float *attrFloatList, unsigned int nMaxFormats,
            int* formats, unsigned int* nFormats );

cbool Win32GL_Setup()
{
    int pixelFormat;
    WNDCLASS dummyWC;
    PIXELFORMATDESCRIPTOR pfd;
    HWND hDummyWnd = NULL;
    HDC dummyDC = NULL;
    HGLRC dummyRC = NULL;
    unsigned int numFormats;
    int attr[7];
    int pixelFormatAttr[17];
    wglCreateContextAttribsARB_t* wglCreateContextAttribsARB;
    wglChoosePixelFormatARB_t* wglChoosePixelFormatARB;

    C_MemSet( &pfd, 0, sizeof(pfd) );
    pfd.nSize           = sizeof( pfd );
    pfd.nVersion        = 1;
    pfd.dwFlags         = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType      = PFD_TYPE_RGBA;
    pfd.cColorBits      = 32;
    pfd.cAlphaBits      = 8;
    pfd.iLayerType      = PFD_MAIN_PLANE;
    pfd.cDepthBits      = 24;
    pfd.cStencilBits    = 8;

    attr[0] = WGL_CONTEXT_MAJOR_VERSION_ARB;
    attr[1] = 9; // set major version later
    attr[2] = WGL_CONTEXT_MINOR_VERSION_ARB;
    attr[3] = 9; // set minor version later;
    attr[4] = WGL_CONTEXT_PROFILE_MASK_ARB;
    attr[5] = WGL_CONTEXT_CORE_PROFILE_BIT_ARB;
    attr[6] = 0;

    pixelFormatAttr[0] = WGL_DRAW_TO_WINDOW_ARB;
    pixelFormatAttr[1] = GL_TRUE;
    pixelFormatAttr[2] = WGL_SUPPORT_OPENGL_ARB;
    pixelFormatAttr[3] = GL_TRUE;
    pixelFormatAttr[4] = WGL_DOUBLE_BUFFER_ARB;
    pixelFormatAttr[5] = GL_TRUE;
    pixelFormatAttr[6] = WGL_ACCELERATION_ARB;
    pixelFormatAttr[7] = WGL_FULL_ACCELERATION_ARB;
    pixelFormatAttr[8] = WGL_PIXEL_TYPE_ARB;
    pixelFormatAttr[9] = WGL_TYPE_RGBA_ARB;
    pixelFormatAttr[10] = WGL_COLOR_BITS_ARB;
    pixelFormatAttr[11] = 32;
    pixelFormatAttr[12] = WGL_DEPTH_BITS_ARB;
    pixelFormatAttr[13] = 24;
    pixelFormatAttr[14] = WGL_STENCIL_BITS_ARB;
    pixelFormatAttr[15] = 8;
    pixelFormatAttr[16] = 0;

    C_MemSet( &dummyWC, 0, sizeof(dummyWC) );
    dummyWC.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    dummyWC.lpfnWndProc = DefWindowProc;
    dummyWC.hInstance = GetModuleHandle( NULL );
    dummyWC.lpszClassName = "dummy";

    if ( !RegisterClass(&dummyWC) ) {
        Log_Printf( ERRTYPE_FATAL, "Win32GL_Setup: Can't register dummy window class.\n" );
        return cfalse;
    }

    hDummyWnd = CreateWindow(
        dummyWC.lpszClassName, "Dummy Window", 0,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL, dummyWC.hInstance, NULL );

    if ( !hDummyWnd ) {
        Log_Printf( ERRTYPE_FATAL, "Win32GL_Setup: Can't create dummy window.\n" );
        return cfalse;
    }

    dummyDC = GetDC( hDummyWnd );
    if ( !dummyDC ) {
        Log_Printf( ERRTYPE_FATAL, "Win32GL_Setup: Can't get dummy device context.\n" );
        return cfalse;        
    }

    pixelFormat = ChoosePixelFormat( dummyDC, &pfd );
    if ( pixelFormat == 0 ) {
        Log_Printf( ERRTYPE_FATAL, "Win32GL_Setup: Can't choose suitable pixel format.\n" );
        return cfalse;        
    }

    if ( !SetPixelFormat( dummyDC, pixelFormat, &pfd ) ) {
         Log_Printf( ERRTYPE_FATAL, "Win32GL_Setup: Can't set dummy pixel format.\n" );
        return cfalse;       
    }

    dummyRC = wglCreateContext( dummyDC );
    if ( !dummyRC ) {
         Log_Printf( ERRTYPE_FATAL, "Win32GL_Setup: Can't create dummy OpenGL rendering context.\n" );
        return cfalse;       
    }

    if ( !wglMakeCurrent( dummyDC, dummyRC ) ) {
        Log_Printf( ERRTYPE_FATAL, "Win32GL_Setup: Can't activate dummy OpenGL rendering context.\n" );
        return cfalse;          
    }

    //TODO: check wglExtensions functions
    wglCreateContextAttribsARB = (wglCreateContextAttribsARB_t*)wglGetProcAddress( "wglCreateContextAttribsARB" );

    if ( !wglCreateContextAttribsARB ) {
        Log_Printf( ERRTYPE_FATAL, "Win32GL_Setup: Can't get proc address (wglCreateContextAttribsARB).\n" );
        return cfalse;        
    }

    wglChoosePixelFormatARB = (wglChoosePixelFormatARB_t*)wglGetProcAddress( "wglChoosePixelFormatARB" );

    if ( !wglChoosePixelFormatARB ) {
        Log_Printf( ERRTYPE_FATAL, "Win32GL_Setup: Can't get proc address (wglChoosePixelFormatARB).\n" );
        return cfalse;        
    }

    // remove the dummy context and create the real ones
    wglMakeCurrent( dummyDC, NULL );
    ReleaseDC( hDummyWnd, dummyDC );
    wglDeleteContext( dummyRC );
    
    g_hDC = GetDC( winState.hWnd );
    if ( !g_hDC ) {
        Log_Printf( ERRTYPE_FATAL, "Win32GL_Setup: Can't create device context.\n" );
        return cfalse;        
    }

    wglChoosePixelFormatARB( g_hDC, pixelFormatAttr, 0, 1, &pixelFormat, &numFormats );
    if ( numFormats == 0 ) {
        Log_Printf( ERRTYPE_FATAL, "Win32GL_Setup: Can't choose suitable pixel format.\n" );
        return cfalse;        
    }

    C_MemSet( &pfd, 0, sizeof( pfd ) );

    if ( g_hDC && !(DescribePixelFormat( g_hDC, pixelFormat, sizeof(pfd), &pfd ))) {
        Log_Printf( ERRTYPE_FATAL, "Win32GL_Setup: Can't obtain pixel format info.\n" );
        return cfalse;        
    }

    if ( g_hDC && !(SetPixelFormat( g_hDC, pixelFormat, &pfd ))) {
        Log_Printf( ERRTYPE_FATAL, "Win32GL_Setup: Can't set the OpenGL pixel format.\n" );
        return cfalse;        
    }

    // set a compatible context version
    while( !( g_hRC = wglCreateContextAttribsARB( g_hDC, 0, attr) ) && attr[1] > 2 ) {
        if ( attr[3] > 0 ) // minor version number
            attr[3]--;
        else {
            attr[3] = 9;
            attr[1]--; //major version number
        }
    }

    if ( !g_hRC ) {
        Log_Printf( ERRTYPE_FATAL, "Win32GL_Setup: Can't create the OpenGL (3.0 and up) context.\n" );
        return cfalse;         
    }

    if ( !wglMakeCurrent( g_hDC, g_hRC ) ) {
        Log_Printf( ERRTYPE_FATAL, "Win32GL_Setup: Can't activate OpenGL rendering context.\n" );
        return cfalse;        
    }

    Log_Printf( ERRTYPE_MESSAGE, "OpenGL Vendor: %s\n", glGetString( GL_VENDOR ) );
    Log_Printf( ERRTYPE_MESSAGE, "OpenGL Version: %s\n", glGetString( GL_VERSION ) );
    Log_Printf( ERRTYPE_MESSAGE, "OpenGL GLSL Version: %s\n", glGetString( GL_SHADING_LANGUAGE_VERSION ) );

    return ctrue; 
}

void Win32GL_Swapbuffers()
{
    SwapBuffers( g_hDC );
}

void Win32GL_Shutdown()
{
    if ( g_hRC ) {
        wglMakeCurrent( NULL, NULL );
        wglDeleteContext( g_hRC );
        g_hRC = NULL;
    }

    if ( g_hDC ) {
        ReleaseDC( winState.hWnd, g_hDC );
        g_hDC = NULL;
    }

    if ( winState.hWnd ) {
        ShowWindow( winState.hWnd, SW_HIDE );
        DestroyWindow( winState.hWnd );
        winState.hWnd = NULL;
    }
}

#endif