#ifndef __MEMORY_H
#define __MEMORY_H

#include "shared.h"

#include <stdlib.h>

#define MEMTAGS( M ) \
    M( DEFAULT ) \
    M( ARRAY ) \
    M( DARRAY )

#define CREATE_ENUM(e) MEMTAG_##e,
#define CREATE_STRING(s) #s,

typedef enum {
    MEMTAGS( CREATE_ENUM )
    NUM_MEMTAGS
} memoryTag_t;

// typedef enum {
//     MEMTAG_DEFAULT,
//     MEMTAG_ARRAY,

//     NUM_TAGS
// } memoryTag_t;

void Mem_Init();
void Mem_Shutdown();

CSAPI char* Mem_GetStatusString();
CSAPI void* C_Malloc( size_t size, memoryTag_t memoryTag );
CSAPI void C_Free( void *ptr, size_t size, memoryTag_t memoryTag );
CSAPI void* C_MemCpy( void *dst, const void *src, size_t size );
CSAPI void* C_MemSet( void *str, int c, size_t n );

#endif