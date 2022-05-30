#ifndef __RBACKEND_H
#define __RBACKEND_H

#include "rshared.h"

typedef struct {
    void (*Init)( void );
    void (*Clean)( void );
    void (*Begin_Frame)( void );
    void (*End_Frame)( void );
} renderBackend_t;

void RB_Create( renderBackendAPI_t api, renderBackend_t *rbOut );

#endif