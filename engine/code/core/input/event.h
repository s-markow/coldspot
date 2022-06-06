#ifndef __EVENT_H
#define __EVENT_H

#include "shared.h"

typedef union {
    char string[16];
    unsigned char uchars[16];
    char chars[16];
    unsigned short ushorts[8];
    short shorts[8];
    float floats[4];
    unsigned long ulongs[4];
    long longs[4];
    double doubles[2];
    unsigned long long ulonglongs[2];
    long long longlongs[2];
} evtContext_t; // void* ?

typedef enum {
    EVT_QUIT,
    EVT_KEY_PRESSED,
    EVT_KEY_RELEASED,
    EVT_MOUSE_PRESSED,
    EVT_MOUSE_RELEASED,
    EVT_MOUSE_MOVE,
    EVT_MOUSE_WHEEL,
    EVT_RESIZE,

    EVT_NUMEVENTS
} evtMessage_t;

void Evt_Init();
void Evt_Shutdown();

typedef cbool (*OnEventFunc)( evtMessage_t message, evtContext_t data, void* sender, void* listener );

CSAPI cbool Evt_Register( evtMessage_t message, void* listener, OnEventFunc onEvent );
CSAPI cbool Evt_Dispatch( evtMessage_t message, void* sender, evtContext_t context );

#endif