#ifndef __WIN32SHARED_H
#define __WIN32SHARED_H

#include <windows.h>

typedef struct {
    HWND hWnd;
    HINSTANCE hInstance;
} winState_t;


#endif