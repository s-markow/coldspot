#include "c_time.h"

void CTime_Update( ctime_t *time )
{
    if ( time->start != 0.0f ) {
        
    }
}

void CTime_Start( ctime_t *time )
{
    time->elapsed = 0.0f;
}

void CTime_Stop( ctime_t *time )
{
    time->start = 0.0f;
}