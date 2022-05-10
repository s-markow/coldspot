#include "logger.h"
#include "../assert.h"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

static const char *LOG_STRING_LABEL[6] = {
    "[FATAL ERROR]: ",
    "[ERROR]: ",
    "[WARNING]: ",
    "[MESSAGE]: ",
    "[DEBUG]: ",
    "[TRACE]: "
};

void Log_Init()
{

}

void Log_Quit()
{

}

void Log_Printf( errType_t errType , const char *fmt, ... )
{
    char buffer[10000];

    va_list va_args;
    va_start( va_args, fmt );
    vsnprintf( buffer, 10000, fmt, va_args );
    va_end( va_args );

    // tmp
    printf( "%s%s\n", LOG_STRING_LABEL[errType], buffer );
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