#include "interface.h"

#include "../sys/sys.h"
#include "io/logger.h"

typedef struct {
    int winCurrentW, winCurrentH;
    sysState_t sysState;
} csState_t;

static csState_t csState;

void CS_Init( csConfig_t *config )
{
    Log_Init();
    
    Sys_CreateWindow( &csState.sysState, config->winStartupW, config->winStartupH );
    csState.winCurrentW = config->winStartupW;
    csState.winCurrentH = config->winStartupH;
}


void CS_Run()
{
    while( 1 ) {
        Sys_PumpEvents();
    }
}