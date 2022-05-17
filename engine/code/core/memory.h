#ifndef __MEMORY_H
#define __MEMORY_H

#include "shared.h"

#include <stdlib.h>

typedef enum {
    MEMTAG_DEFAULT,
    MEMTAG_ARRAY,

    NUM_TAGS
} memoryTag_t;

void Mem_Init();
void Mem_Shutdown();

CSAPI void* C_Malloc( size_t size, memoryTag_t memoryTag );
CSAPI void C_Free( void *ptr, size_t size, memoryTag_t memoryTag );
CSAPI void* C_MemCpy( void *dst, const void *src, size_t size );
CSAPI void* C_Memset( void *str, int c, size_t n );

#endif