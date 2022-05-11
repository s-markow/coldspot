#ifndef __SHARED_H
#define __SHARED_H

#if defined( WIN32 ) || defined( _WIN32 ) || defined( __WIN32__ )
#define CS_WIN32_DEFINED
#endif

#if defined( CSEXPORT )
#define CSAPI __declspec( dllexport )
#elif defined( CSIMPORT )
#define CSAPI __declspec( dllimport )
#endif

typedef enum {
    cfalse, ctrue
} cbool;

#endif
