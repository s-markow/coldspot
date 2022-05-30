#ifndef __SHARED_H
#define __SHARED_H

#define strfy(x)    #x
#define xstrfy(x)   strfy(x)


#if defined( WIN32 ) || defined( _WIN32 ) || defined( __WIN32__ )
#define CS_WIN32_DEFINED
#elif defined( __linux__ )
#define CS_LINUX_DEFINED
#else
#error Not supported on this system!
#endif

#ifdef CS_WIN32_DEFINED
#if defined( CSEXPORT )
#define CSAPI __declspec( dllexport )
#else
#define CSAPI __declspec( dllimport )
#endif
#else
#define CSAPI __attribute__ ((visibility ("default")))
#endif

typedef enum {
    cfalse, ctrue
} cbool;

#define ARRAY_GET_LE_WORD( ptr )      ( (short)(ptr)[0] | (short)(ptr)[1] << 8 )
#define ARRAY_GET_LE_LONG( ptr ) \
    ( (long)(ptr)[0] | (long)(ptr)[1] << 8 | (long)(ptr)[2] << 16 | (long)(ptr)[3] << 24 )
#define ARRAY_GET_LE_LLONG( ptr )  \
    ((long long)(ptr)[0] \
    | (long long)(ptr)[1] << 8 \
    | (long long)(ptr)[2] << 16 \
    | (long long)(ptr)[3] << 24 \
    | (long long)(ptr)[4] << 32 \
    | (long long)(ptr)[5] << 40 \
    | (long long)(ptr)[6] << 48 \
    | (long long)(ptr)[7] << 56)

#define COLOR_ESCAPE_CHAR       '^'
#define IsColoredText(str)      ( str && *(str) == COLOR_ESCAPE_CHAR && *((str)+1) && *((str)+1) != COLOR_ESCAPE_CHAR )

#endif
