#include "../sys.h"

#ifdef CS_WIN32_DEFINED
#include <windows.h>

typedef struct {
    HWND hWnd;
    HINSTANCE hInstance;
} winState_t;

winState_t winState;

void Sys_Init( sysState_t *state )
{
    state->internalPtr = &winState;
}

#endif
