/* General system independent signatures routing to different platforms */

#ifndef __SYS_H
#define __SYS_H

#include <stdlib.h>

#include "../shared.h"

typedef struct {
    void *internalPtr;
} sysState_t;

// windowed systems vs non-windowd systems
#if defined ( CS_WIN32_DEFINED ) || defined ( CS_LINUX_DEFINED )
// win32console.c
void Sys_ConsolePrint( const char *msg );
void Sys_CreateConsole();
void Sys_QuitConsole();
cbool Sys_CreateWindow( sysState_t *state, int width, int height, char *winTitle );
#endif

// create some context
cbool Sys_CreateContext( sysState_t *state );


void Sys_Clean( sysState_t *state );

void *Sys_Alloc( size_t size, cbool aligned );
void Sys_Free( void *ptr, cbool aligned );
void *Sys_MemCpy( void *dst, const void *src, size_t size );
void *Sys_MemSet( void *str, int c, size_t n );

void Sys_PumpEvents();

CSAPI void Sys_Sleep( unsigned long ms );
CSAPI double Sys_GetTime();

// syscon.c
void Sys_Printf( const char *fmt, ... );

#endif