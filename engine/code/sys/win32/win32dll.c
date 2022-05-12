#include "../../shared.h"

#ifdef CS_WIN32_DEFINED
#include "../sys.h"
#include "win32shared.h"

#include <stdio.h> //tmp

#ifdef main
#undef main
#endif

extern winState_t winState;

BOOL WINAPI DllMain( HINSTANCE hInstDLL, DWORD fdwReason, LPVOID lpReserved )
{
   switch( fdwReason ) {
      case DLL_PROCESS_ATTACH:
         winState.hInstance = hInstDLL;
         break;
   }
   return TRUE;
}

#endif