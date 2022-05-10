#ifndef __SYS_H
#define __SYS_H

#include <stdlib.h>

#include "../shared.h"

typedef struct {
    void *internalPtr;
} sysState_t;

void Sys_Init( sysState_t *state );

void Sys_Quit( sysState_t *state );

void *Sys_Alloc( size_t size, cbool aligned );
void Sys_Free( void *ptr );
void *Sys_MemCpy( void *dst, const void *src, size_t size );

cbool Sys_PumpMessages( sysState_t *state );

void Sys_Sleep( unsigned long ms );

// syscon.c
void Sys_Printf( const char *fmt, ... );

#endif