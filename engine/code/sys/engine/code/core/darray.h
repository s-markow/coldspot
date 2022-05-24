#ifndef __DARRAY_H
#define __DARRAY_H

#include "shared.h"

typedef enum {
    AHDR_CAPACITY,
    AHDR_LENGTH,
    AHDR_STRIDE,
///////////////////////////
    AHDR_NUMFIELDS
} arrayHeader_t;

CSAPI void* DArray_Alloc( size_t length, size_t stride );
CSAPI void DArray_Free( void *array );
CSAPI size_t DArray_GetFieldValue( const void *array, size_t field );
CSAPI void* DArray_Resize( void *array );
CSAPI void* DArray_Reserve( void *array, size_t nElem );
CSAPI void* DArray_Push( const void* val );
CSAPI void DArray_Pop( void* array, void* dst );

#endif