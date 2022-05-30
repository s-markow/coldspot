#include "darray.h"
#include "c_memory.h"

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
         + ARRAY_GET_LE_LLONG(&header[AHDR_CAPACITY * 8])
         + ARRAY_GET_LE_LLONG(&header[AHDR_STRIDE * 8]), MEMTAG_DARRAY );
}

size_t DArray_GetFieldValue( const void *array, arrayHeader_t field )
{
    unsigned char *header = (unsigned char*)array - AHDR_NUMFIELDS * 8;
    return header[field * 8];
}

void DArray_SetFieldValue( const void *array, arrayHeader_t field, long long val )
{
    unsigned char *header = (unsigned char*)array - AHDR_NUMFIELDS * 8;
    header[field * 8] = val;
}

void* DArray_Resize( void *array )
{
    size_t stride;
    size_t length;
    void *out;
    
    length = DArray_GetFieldValue( array, AHDR_LENGTH );
    stride = DArray_GetFieldValue( array, AHDR_STRIDE );

    out = DArray_Alloc( DArray_GetFieldValue( array, AHDR_CAPACITY ) * DARRAY_RESIZE_FACTOR, stride );
    C_MemCpy( out, array, length * stride );

    DArray_SetFieldValue( out, AHDR_LENGTH, length );
    DArray_Free( array );

    return out;
}

void* DArray_Reserve( void *array, size_t nElem )
{
    return NULL;
}

void* DArray_Push( void *array, const void* val )
{
    size_t stride;
    size_t length;
    size_t addr;
    
    length = DArray_GetFieldValue( array, AHDR_LENGTH );
    stride = DArray_GetFieldValue( array, AHDR_STRIDE );
    if ( length >= DArray_GetFieldValue( array, AHDR_CAPACITY ) ) {
        array = DArray_Resize( array );
    }
    addr = (size_t)array;
    addr += ( length * stride );
    C_MemCpy( (void*)addr, val, stride );
    DArray_SetFieldValue( array, AHDR_LENGTH, length + 1 );
    return array;
}

void DArray_Pop( void* array, void* dst )
{  
    size_t stride;
    size_t length;
    size_t addr;

    length = DArray_GetFieldValue( array, AHDR_LENGTH );
    stride = DArray_GetFieldValue( array, AHDR_STRIDE );
    
    addr = (size_t)array;
    addr += ( (length - 1) * stride );
    C_MemCpy( dst, (void*)addr, stride );
    DArray_SetFieldValue( array, AHDR_LENGTH, length - 1 );
}