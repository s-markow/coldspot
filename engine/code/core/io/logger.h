#ifndef __LOGGER_H
#define __LOGGER_H

#include "shared.h"

#ifndef CSRELEASEBUILD
#define LOG_ENABLE_DEBUG
#define LOG_ENABLE_TRACE
#endif

#define LOG_ENABLE_WARNINGS
#define LOG_ENABLE_MESSAGES

typedef enum {
    ERRTYPE_FATAL,
    ERRTYPE_ERROR,
    ERRTYPE_WARNING,
    ERRTYPE_MESSAGE,
#ifdef LOG_ENABLE_DEBUG
    ERRTYPE_DEBUG,
#endif
#ifdef LOG_ENABLE_TRACE
    ERRTYPE_TRACE
#endif
} errType_t;

void Log_Init();
void Log_Quit();

CSAPI void Log_Printf( errType_t errType, const char *fmt, ... );

#endif