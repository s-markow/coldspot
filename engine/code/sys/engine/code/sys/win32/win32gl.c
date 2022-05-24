#include "../../shared.h"

#ifdef CS_WIN32_DEFINED

#include "win32shared.h"
#include "../gldefs.h"
#include "core/memory.h"

static cbool Win32GL_Setup()
{
    int pixelFormat;
    WNDCLASS dummyWC;
    PIXELFORMATDESCRIPTOR pfd;
    HWND hDummyWnd = NULL;
    HDC dummyDC = NULL;
    HGLRC dummyRC = NULL;
    unsigned int numFormats;
    int attr[7];
    int pixelFormatAttr[16];

    C_MemSet( &pfd, 0, sizeof(pfd) );
    pfd.nSize           = sizeof( pfd );
    pfd.nVersion        = 1
    pfd.dwFlags         = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType      = PFD_TYPE_RGBA;
    pfd.cColorBits      = 24;
    pfd.cDepthBits      = 24;
    pfd.cStencilBits    = 8;

    attr[0] = WGL_CONTEXT_MAJOR_VERSION_ARB;
    attr[1] = 9; // set major version later
    attr[2] = WGL_CONTEXT_MINOR_VERSION_ARB;
    attr[3] = 9; // set minor version later;
    attr[4] = WGL_CONTEXT_PROFILE_MASK_ARB;
    attr[5] = WGL_CONTEXT_CORE_PROFILE_BIT_ARB;
    attr[7] = 0;

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

    C_MemSet( &dummyWc, 0, sizeof(dummyWC) );
    dummyWC.style = CS_HREDRAW | CS_VREDRAW | CD_OWNDC;
    dummyWC.lpfnWndProc = DefWindowProc;
    dummyWC.hInstance = GetModuleHande( NULL );
    dummyWC.lpszClassName = "dummy";

    if ( !RegisterClass(&dummyWC) ) {
        Log_Printf( ERRTYPE_FATAL, "Win32GL_Setup: Can't register dummy window class.\n" );
        return cfalse;
    }

    hDummyWnd = CreateWindow(
        dummyWC.lpszClassName, "Dummy Window", 0,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL, dummyWC.hInstance, NULL );
    );

    if ( !dummyWC ) {
        Log_Printf( ERRTYPE_FATAL, "Win32GL_Setup: Can't create dummy window.\n" );
        return cfalse;
    }

    return ctrue; 
}

#endif