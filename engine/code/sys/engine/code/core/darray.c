#include "darray.h"
#include "memory.h"

#include <stdlib.h>

#define DARRAY_RESIZE_FACTOR        2


// typedef struct {
//     size_t capacity;
//     size_t _length;
//     size_t stride;
// } arrayHeader_t;

void* DArray_Alloc( size_t length, size_t stride )
{
    unsigned char *array;

    array = C_Malloc( AHDR_NUMFIELDS + length * stride, MEMTAG_DARRAY );
    
    array[AHDR_CAPACITY * 8] = length;
    array[AHDR_LENGTH * 8] = 0;
    array[AHDR_STRIDE * 8] = stride;

    return (void*)(array + AHDR_NUMFIELDS * 8);
}

void DArray_Free( void *array )
{
    unsigned char *header = (unsigned char*)array - AHDR_NUMFIELDS * 8;
    C_Free( array, sizeof( arrayHeader_t )
        + ARRAY_GET_LE_LLONG(header[AHDR_CAPACITY * 8]) + ARRAY_GET_LE_LLONG(header[AHDR_STRIDE * 8]), MEMTAG_DARRAY );
}

size_t DArray_GetFieldValue( const void *array, size_t field )
{
    unsigned char *header = (unsigned char*)array - AHDR_NUMFIELDS * 8;
    return header[field * 8];
}

void* DArray_Resize( void *array )
{
    return NULL;
}

void* DArray_Reserve( void *array, size_t nElem )
{
    return NULL;
}

void* DArray_Push( const void* val )
{
    return NULL;    
}

void DArray_Pop( void* array, void* dst )
{  
}