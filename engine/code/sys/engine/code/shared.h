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
#elif defined( CSIMPORT )
#define CSAPI __declspec( dllimport )
#endif
#else
#define CSAPI __attribute__ ((visibility ("default")))
#endif

typedef enum {
    cfalse, ctrue
} cbool;

#define ARRAY_GET_LE_WORD( ptr )      ( (ptr)[0] | (ptr)[1] << 8 )
#define ARRAY_GET_LE_LONG( ptr )      ( (ptr)[0] | (ptr)[1] << 8 | (ptr)[2] << 16 | (ptr)[3] << 24 )
#define ARRAY_GET_LE_LLONG( ptr )  \
    ((ptr)[0] | (ptr)[1] << 8 | (ptr)[2] << 16 | (ptr)[3] << 24 | (ptr)[4] << 32 | (ptr)[5] << 40 | (ptr)[6] << 48 | (ptr)[7] << 56)

#define COLOR_ESCAPE_CHAR       '^'
#define IsColoredText(str)      ( str && *(str) == COLOR_ESCAPE_CHAR && *((str)+1) && *((str)+1) != COLOR_ESCAPE_CHAR )

#endif
