#include "memory.h"

#include "../sys/sys.h"
#include "io/logger.h"

int totalAllocatedMem;
int taggedAllocations[NUM_TAGS];

void Mem_Init()
{
}

void Mem_Shutdown()
{
}

void* C_Malloc( size_t size, memoryTag_t memoryTag )
{
    void *memBlock;

    totalAllocatedMem += size;
    taggedAllocations[memoryTag] += size;
    memBlock = Sys_Alloc( size, cfalse /*tmp*/ );
    Sys_Memset( memBlock, 0, size );
    return memBlock;
}

void C_Free( void *ptr, size_t size, memoryTag_t memoryTag )
{
    totalAllocatedMem -= size;
    taggedAllocations[memoryTag] -= size;
    Sys_Free( ptr, cfalse /*tmp*/ );
}

void* C_MemCpy( void *dst, const void *src, size_t size )
{
    return NULL;
}

void* C_Memset( void *str, int c, size_t n )
{
    return NULL;
}