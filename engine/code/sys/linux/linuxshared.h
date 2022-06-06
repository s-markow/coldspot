#ifndef __LINUXSHARED_H
#define __LINUXSHARED_H

// #include <windows.h>

#include "../../shared.h"

typedef struct {
    void *x;
    // HWND hWnd;
    // HINSTANCE hInstance;
} winState_t;

extern winState_t winState;

cbool Sys_CreateVulkanSurface(); // Linux_

// linuxgl.c
void LinuxGL_Shutdown();
cbool LinuxGL_Setup();

#endif