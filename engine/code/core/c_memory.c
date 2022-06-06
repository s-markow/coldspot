#include "c_memory.h"

#include "../sys/sys.h"
#include "io/logger.h"

#include <stdio.h>
#include <string.h>

#define KIBIBYTE        1024
#define MEBIBYTE        1048576
#define GIBIBYTE        1073741824

int totalAllocatedMem;
int taggedAllocations[NUM_MEMTAGS];

static const char *memTagsStr[NUM_MEMTAGS] = {
    MEMTAGS( CREATE_STRING )
};

void Mem_Init()
{
}

void Mem_Shutdown()
{
}

char *Mem_GetStatusString()
{
    // #define UNIT(x)     "GMKB"[x]
    #define BUFFER_SIZE 8000
    #if 1
    char buffer[BUFFER_SIZE];
    float val;
    char *out;
    int offset = 0;
    int len = 0;
    char unit[4] = " iB";

    for ( int i = 0; i < NUM_MEMTAGS; i++ ) {
        if ( taggedAllocations[i] >= GIBIBYTE ) {
            val = taggedAllocations[i] / (float)GIBIBYTE;
            unit[0] = 'G';
        }
        else if ( taggedAllocations[i] >= MEBIBYTE ) {
            val = taggedAllocations[i] / (float)MEBIBYTE;
            unit[0] = 'M';
        }
        else if ( taggedAllocations[i] >= KIBIBYTE ) {
            val = taggedAllocations[i] / (float)KIBIBYTE;
            unit[0] = 'K';
        }
        else {
            val = (float)taggedAllocations[i];
            unit[0] = 'B';
            unit[1] = '\0';
        }

        len = snprintf( buffer + offset, BUFFER_SIZE, "%s: %.2f %s\n", memTagsStr[i], val, unit );
        offset += len;
    }
    #endif

    out = _strdup(buffer);
    #undef BUFFER_SIZE
    // #undef UNIT
    return out;
}

void* C_Malloc( size_t size, memoryTag_t memoryTag )
{
    void *memBlock;

    totalAllocatedMem += size;
    taggedAllocations[memoryTag] += size;
    memBlock = Sys_Alloc( size, cfalse /*tmp*/ );
    Sys_MemSet( memBlock, 0, size );
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
    return Sys_MemCpy( dst, src, size );
}

void* C_MemSet( void *str, int c, size_t n )
{
    return Sys_MemSet( str, c, n );
}