#ifndef __SHARED_H
#define __SHARED_H

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



#define COLOR_ESCAPE_CHAR       '^'
#define IsColoredText(str)      ( str && *(str) == COLOR_ESCAPE_CHAR && *((str)+1) && *((str)+1) != COLOR_ESCAPE_CHAR )

#endif
