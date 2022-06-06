#ifndef __C_ASSERT_H
#define __C_ASSERT_H

#include "shared.h"

#define ASSERT_ENABLE

#ifdef ASSERT_ENABLE
#ifdef _MSC_VER
#define HALT { __asm int 3 }
#else
#define HALT   __builtin_trap()
#endif
#endif

CSAPI void __assert( const char *expr, const char *msg, const char *file, int line );

#undef assert

#define assert( expr )      \
{                           \
    if( expr ) {            \
    }                       \
    else {                  \
        __assert( #expr, "", __FILE__, __LINE__ );   \
        HALT;       \
    }               \
}

#endif