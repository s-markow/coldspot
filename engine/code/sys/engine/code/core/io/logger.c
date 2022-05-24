#include "logger.h"
#include "../assert.h"

#include "sys/sys.h"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

static const char *LOG_STRING_LABEL[6] = {
    "[FATAL ERROR]",
    "[ERROR]",
    "[WARNING]",
    "[MESSAGE]",
    "[DEBUG]",
    "[TRACE]"
};

void Log_Init()
{
 // windowed systems vs non-windowed systems
#if defined ( CS_WIN32_DEFINED ) || defined ( CS_LINUX_DEFINED )
    Sys_CreateConsole();
#else
#endif
}

void Log_Quit()
{
 // windowed systems vs non-windowed systems
#if defined ( CS_WIN32_DEFINED ) || defined ( CS_LINUX_DEFINED )
    Sys_QuitConsole();
#else
#endif
}

void Log_Printf( errType_t errType, const char *fmt, ... )
{
    #define BUFFER_SIZE 10000
    char buffer[BUFFER_SIZE];
    char out[BUFFER_SIZE];
    va_list va_args;

    Sys_MemSet( buffer, 0, BUFFER_SIZE );
    Sys_MemSet( out, 0, BUFFER_SIZE );

    va_start( va_args, fmt );
    vsnprintf( buffer, BUFFER_SIZE, fmt, va_args );
    va_end( va_args );

    sprintf( out, "%s: %s", LOG_STRING_LABEL[errType], buffer );
    Sys_ConsolePrint( out );

    #undef BUFFER_SIZE
}

void __assert( const char *expr, const char *msg, const char *file, int line )
{
    Log_Printf( ERRTYPE_FATAL, "False Assertion %s, %s, [FILE]: %s, [LINE]: %d\n", expr, msg, file, line );
}

// void s__assert( const char *expr, const char *msg, const char *file, int line )
// {    
//     Log_Printf( ERRTYPE_FATAL, "False Assertion %s, %s, [FILE]: %s, [LINE]: %d\n", expr, msg, file, line );
//     __asm {
//          int 3    // test
//    }
// }