#ifndef __C_TIME_H
#define __C_TIME_H

#include "shared.h"

typedef struct {
    float start;
    float elapsed;
} ctime_t;

void CTime_Update( ctime_t *time );
void CTime_Start( ctime_t *time );
void CTime_Stop( ctime_t *time );


#endif