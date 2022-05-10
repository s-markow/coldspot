#include "../sys.h"

#ifdef CS_WIN32_DEFINED
#include <windows.h>

typedef struct {
    HWND hWnd;
    HINSTANCE hInstance;
} win32Vars_t;

win32Vars_t win32Vars;

void Sys_Init( sysState_t *state )
{
    // state->internalPtr
}

#endif