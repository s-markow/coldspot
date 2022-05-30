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
CSAPI size_t DArray_GetFieldValue( const void *array, arrayHeader_t field );
CSAPI void DArray_SetFieldValue( const void *array, arrayHeader_t field, long long val );
CSAPI void* DArray_Resize( void *array );
CSAPI void* DArray_Reserve( void *array, size_t nElem );
CSAPI void* DArray_Push( void *array, const void* val );
CSAPI void DArray_Pop( void* array, void* dst );

// #define DArray_Push( a, val ) \
//     do { \
//         void *v; \
//         C_MemCpy( v, val, sizeof(val) ); \
//         _DArray_Push( a, v ); \
//     } while (0)

#endif