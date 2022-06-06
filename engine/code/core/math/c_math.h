#ifndef __C_MATH_H
#define __C_MATH_H

#include "shared.h"

#define M_PI    3.14159265358979323846
#define M_SQRT2 1.4142135623730950488

typedef struct {
    float x, y;
} fvec2_t;

typedef struct {
    double x, y;
} dvec2_t;

// typedef float fvect3_t[3];

typedef struct {
    float x, y, z;
} fvec3_t;

typedef struct {
    double x, y, z;
} dvec3_t;

typedef struct {
    float x, y, z, w;
} fvec4_t;

typedef struct {
    double x, y, z, w;
} dvec4_t;

typedef fvec4_t fquat_t;
typedef dvec4_t dquat_t;

#define Vec2Clr( v )            do { (v).x = (v).y = 0; } while (0)
#define Vec2Add( res, u, v )     do { (res).x = (u).x + (v).x; (res).y = (u).y + (v).y; } while(0)
#define Vec2Sub( res, u, v )     do { (res).x = (u).x - (v).x; (res).y = (u).y - (v).y; } while(0)
#define Vec2ScalarMult( res, s, v )  do { (res).x = s * (u).x; (res).y = s * (u).y; } while (0)

#define Vec3Clr( v )            do { (v).x = (v).y = (v).z = 0; } while (0)
#define Vec3Neg( res, v )       do { (res).x = -(v).x; (res).y = -(v).y; (res).z = -(v).z; } while (0)
#define Vec3Add( res, u, v )     do { (res).x = (u).x + (v).x; (res).y = (u).y + (v).y; (res).z = (u).z + (v).z; } while(0)
#define Vec3Sub( res, u, v )     do { (res).x = (u).x - (v).x; (res).y = (u).y - (v).y; (res).z = (u).z - (v).z; } while(0)
#define Vec3ScalarMult( res, s, v )  do { (res).x = s * (u).x; (res).y = s * (u).y; (res).z = s * (u).z; } while (0)
#define VecCross( res, u, v )
#define VecDot( u, v )          ( (u).x * (v).x + (u).y * (v).y + (u).z + (v).z )

#define Vec4Clr( v )            do { (v).x = (v).y = (v).z = (v).w = 0; } while (0)
#define QuatClr( q )            Vec4Clr( v )


CSAPI float fVec3Normalize( const fvec3_t in, fvec3_t out );
// dvec3_t dVec3Normalize( const dvec3_t in, dvec3_t out );

CSAPI int m_random();

CSAPI float m_sin( float x );
CSAPI float m_cos( float x );
CSAPI float m_sqrt( float x );

#endif