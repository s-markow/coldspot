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

#endif