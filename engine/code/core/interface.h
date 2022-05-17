#ifndef __INTERFACE_H
#define __INTERFACE_H

#include "shared.h"

typedef struct {
// windowed systems vs non-windowed systems
#if defined ( CS_WIN32_DEFINED ) || defined ( CS_LINUX_DEFINED )
    char *winTitle;
    // startup window dimensions
    int winStartupX, winStartupY;
    int winStartupW, winStartupH;
#else
#endif
} csConfig_t;

CSAPI void CS_Init( csConfig_t *config );
CSAPI void CS_Run();
CSAPI void CS_Quit();

#endif