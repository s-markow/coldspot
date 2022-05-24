#include "event.h"
#include "memory.h"

#define MAX_MESSAGE_CODES       16384

typedef struct {
    void *evt_listener;
    OnEventFunc CallBackFunc;
} evtMessageEntry_t;

evtMessageEntry_t registeredMessages[MAX_MESSAGE_CODES];

void Evt_Init()
{
}

void Evt_Shutdown()
{
}

CSAPI cbool Evt_Register( unsigned short message, void* listener, OnEventFunc onEvent )
{
    return cfalse;
}

CSAPI cbool Evt_Dispatch( unsigned short message, void* sender, evtContext_t context )
{
    return cfalse;
}