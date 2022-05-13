#ifndef __INTERFACE_H
#define __INTERFACE_H

#include "shared.h"

typedef struct {
#ifdef CS_WIN32_DEFINED // TODO: and other window systems
    char *winName;
    // startup window dimensions
    int winStartupX, winStartupY;
    int winStartupW, winStartupH;
#endif
} csConfig_t;

CSAPI csConfig_t csConfig;

CSAPI void CS_Init( csConfig_t *config );
CSAPI void CS_Run();

#endif