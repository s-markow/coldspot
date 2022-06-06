#include "interface.h"

#include "../sys/sys.h"
#include "io/logger.h"

typedef struct {
// for windowed systems
#if defined ( CS_WIN32_DEFINED ) || defined ( CS_LINUX_DEFINED )    
    int winCurrentW, winCurrentH;
#endif
    sysState_t sysState;
} csState_t;

static csState_t csState;


void CS_Init( csConfig_t *config )
{
    Log_Init();

 // windowed systems vs non-windowed systems
#if defined ( CS_WIN32_DEFINED ) || defined ( CS_LINUX_DEFINED )
    if ( !Sys_CreateWindow( &csState.sysState, 100, 100, config->winStartupW-20, config->winStartupH-20, config->winTitle, cfalse ) ) {
        Log_Printf( ERRTYPE_FATAL, "CS_Init: Can't create main window.\n" );
        return;
    }

    csState.winCurrentW = config->winStartupW;
    csState.winCurrentH = config->winStartupH;
#endif

    if ( !Sys_CreateContext( &csState.sysState ) ) {
        Log_Printf( ERRTYPE_FATAL, "CS_Init: Can't create context.\n" );
        return;      
    }

}

void CS_Quit()
{
    Sys_Clean( &csState.sysState );
}


void CS_Run()
{
    while( 1 ) {
        Sys_PumpEvents();

        // Render
        // UpdateInput
    }
}