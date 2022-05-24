#include "cmath.h"
#include <time.h>
#include <stdlib.h>

static cbool seeded;

int m_random()
{
    if ( !seeded ) {
        srand( time(0) /*tmp*/ );
        seeded = ctrue;
    }
    return rand();
}

float m_sin( float x )
{
    return 0.0f;
}

float m_cos( float x ){
    return 0.0f;
}

float m_sqrt( float x )
{
    return 0.0f;
}