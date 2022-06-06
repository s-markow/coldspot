#include "c_math.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>

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

float fVec3Normalize( const fvec3_t in, fvec3_t out )
{
    float len, invlen;

    len = sqrt( in.x * in.x + in.y * in.y + in.z * in.z );
    if ( len == 0 ) {
        return 0.0f;
    }

    invlen = 1.0f/len;
    out.x = in.x * invlen;
    out.y = in.y * invlen;
    out.z = in.z * invlen;

    return len;   
}