#include "darray.h"
#include "c_memory.h"

#include <stdlib.h>

#define DARRAY_RESIZE_FACTOR        2


// typedef struct {
//     size_t capacity;
//     size_t _length;
//     size_t stride;
// } arrayHeader_t;

void* DArray_Alloc( size_t nElem, size_t elemSize )
{
    unsigned char *array;

    array = C_Malloc( AHDR_NUMFIELDS + nElem * elemSize, MEMTAG_DARRAY );
    
    array[AHDR_CAPACITY * 8] = nElem;
    array[AHDR_NUM_ELEM * 8] = 0;
    array[AHDR_ELEMSIZE * 8] = elemSize;

    return (void*)(array + AHDR_NUMFIELDS * 8);
}

void DArray_Free( void *array )
{
    unsigned char *header = (unsigned char*)array - AHDR_NUMFIELDS * 8;

    C_Free( array, sizeof( arrayHeader_t )
         + ARRAY_GET_LE_LLONG(&header[AHDR_CAPACITY * 8])
         + ARRAY_GET_LE_LLONG(&header[AHDR_ELEMSIZE * 8]), MEMTAG_DARRAY );
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
    size_t elemSize;
    size_t nElem;
    void *out;
    
    nElem = DArray_GetFieldValue( array, AHDR_NUM_ELEM );
    elemSize = DArray_GetFieldValue( array, AHDR_ELEMSIZE );

    out = DArray_Alloc( DArray_GetFieldValue( array, AHDR_CAPACITY ) * DARRAY_RESIZE_FACTOR, elemSize );
    C_MemCpy( out, array, nElem * elemSize );

    DArray_SetFieldValue( out, AHDR_NUM_ELEM, nElem );
    DArray_Free( array );

    return out;
}

void* DArray_Reserve( void *array, size_t nElem )
{
    return NULL;
}

void* DArray_Push( void *array, const void* val )
{
    size_t elemSize;
    size_t nElem;
    size_t addr;
    
    nElem = DArray_GetFieldValue( array, AHDR_NUM_ELEM );
    elemSize = DArray_GetFieldValue( array, AHDR_ELEMSIZE );
    if ( nElem >= DArray_GetFieldValue( array, AHDR_CAPACITY ) ) {
        array = DArray_Resize( array );
    }
    addr = (size_t)array;
    addr += ( nElem * elemSize );
    C_MemCpy( (void*)addr, val, elemSize );
    DArray_SetFieldValue( array, AHDR_NUM_ELEM, nElem + 1 );
    return array;
}

void DArray_Pop( void* array, void* dst )
{  
    size_t elemSize;
    size_t nElem;
    size_t addr;

    nElem = DArray_GetFieldValue( array, AHDR_NUM_ELEM );
    elemSize = DArray_GetFieldValue( array, AHDR_ELEMSIZE );
    
    addr = (size_t)array;
    addr += ( (nElem - 1) * elemSize );
    C_MemCpy( dst, (void*)addr, elemSize );
    DArray_SetFieldValue( array, AHDR_NUM_ELEM, nElem - 1 );
}

void *DArray_PopAt( void *array, size_t idx, void* dst )
{
    return array;
}