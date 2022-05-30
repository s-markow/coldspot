#ifndef __WIN32SHARED_H
#define __WIN32SHARED_H

#include <windows.h>

#include "../../shared.h"

typedef struct {
    HWND hWnd;
    HINSTANCE hInstance;
} winState_t;

extern winState_t winState;

cbool Sys_CreateVulkanSurface();

// win32gl.c
void Win32GL_Shutdown();
cbool Win32GL_Setup();

#endif