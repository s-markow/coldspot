#ifndef __SYS_H
#define __SYS_H

#include <stdlib.h>

#include "../shared.h"

typedef struct {
    void *internalPtr;
} sysState_t;

cbool Sys_CreateWindow( sysState_t *state, int width, int height );

void Sys_Quit( sysState_t *state );

CSAPI void *Sys_Alloc( size_t size, cbool aligned );
CSAPI void Sys_Free( void *ptr );
CSAPI void *Sys_MemCpy( void *dst, const void *src, size_t size );
CSAPI void *Sys_MemSet( void *str, int c, size_t n );

void Sys_PumpEvents();

CSAPI void Sys_Sleep( unsigned long ms );
CSAPI double Sys_GetTime();

void Sys_CreateConsole();

// syscon.c
void Sys_Printf( const char *fmt, ... );

#endif
