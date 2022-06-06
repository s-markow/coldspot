#include "c_string.h"

#include <string.h>

size_t C_StrLen( const char* str )
{
  return strlen(str);
}

char *C_StrDup( const char* str )
{
  return NULL;
}

int C_StrCmp( const char* str1, const char* str2 )
{
  return strcmp( str1, str2 ); 
}

char *C_StrCpy( char *dst, const char* src )
{
  return strcpy( dst, src );
}

char *C_StrnCpy( char *dst, const char* src, size_t n )
{
   return NULL;
}

char *C_StrEmpty( char *str )
{
  if ( str )
     str[0] = '\0';

  return str;
}

char *C_StrTrim( char *str )
{
  return NULL;
}