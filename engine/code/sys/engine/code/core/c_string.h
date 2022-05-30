#ifndef __C_STRING_H
#define __C_STRING_H

#include "shared.h"

#include <stdlib.h>

CSAPI size_t C_StrLen( const char* str );
CSAPI char *C_StrDup( const char* str );
CSAPI int C_StrCmp( const char* str1, const char* str2 );
CSAPI char *C_StrCpy( char *dst, const char* src );
CSAPI char *C_StrnCpy( char *dst, const char* src, size_t n );
CSAPI char *C_StrEmpty( char *str );
CSAPI char *C_StrTrim( char *str );

#endif