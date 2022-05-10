#ifndef __SHARED_H
#define __SHARED_H

#define CS_WIN32_DEFINED    ( WIN32 || _WIN32 || __WIN32__ )

#if defined( CSEXPORT )
#define CSAPI __declspec( dllexport )
#elif defined( CSIMPORT )
#define CSAPI __declspec( dllimport )
#endif

typedef enum {
    cfalse, ctrue
} cbool;

#endif
