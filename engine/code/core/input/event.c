#include "event.h"
#include "../c_memory.h"
#include "../darray.h"

#define     MAX_MSG_TYPES       1024

// cbool eventsActive;

typedef struct {
    void *listener;
    OnEventFunc CallBackFunc;
} evtRegisteredEvent_t;

typedef struct {
    evtRegisteredEvent_t *events; 
} evtMessageEntry_t;

typedef struct {
    evtMessageEntry_t registeredMessages[MAX_MSG_TYPES];
} evtSysState_t;


static evtSysState_t* evtStatePtr;

// void Evt_Init()
// {
// }

void Evt_Shutdown()
{
}

cbool Evt_Register( evtMessage_t message, void* listener, OnEventFunc onEvent )
{
    size_t numRegistered;
    evtRegisteredEvent_t registered;

    if ( !evtStatePtr ) {
        return cfalse;
    }    

    if ( evtStatePtr->registeredMessages[message].events == 0 ) {
        evtStatePtr->registeredMessages[message].events = DArray_Alloc( 1, sizeof(registered) );
    }

    numRegistered = DArray_GetFieldValue( evtStatePtr->registeredMessages[message].events, AHDR_NUM_ELEM );
     for ( size_t i = 0; i < numRegistered; i++ ) {
        if ( evtStatePtr->registeredMessages[message].events[i].listener == listener )
            return cfalse;
    }
    // numRegistered = DArray_GetFieldValue( registeredMessages, AHDR_NUM_ELEM );
    // for ( size_t i = 0; i < numRegistered; i++ ) {
    //     // evtRegisteredEvent_t registered;
    // }
    registered.listener = listener;
    registered.CallBackFunc = onEvent;
    // DArray_Push( evtStatePtr->registered[message].events, registered );

    return cfalse;
}

cbool Evt_Dispatch( evtMessage_t message, void* sender, evtContext_t context )
{
    size_t numRegistered;

    if ( !evtStatePtr ) {
        return cfalse;
    }

    if ( evtStatePtr->registeredMessages[message].events == 0 ) {
        return cfalse;
    }

    numRegistered = DArray_GetFieldValue( evtStatePtr->registeredMessages[message].events, AHDR_NUM_ELEM );
     for ( size_t i = 0; i < numRegistered; i++ ) {
        evtRegisteredEvent_t registered = evtStatePtr->registeredMessages[message].events[i];

        if ( registered.CallBackFunc( message, context, sender, registered.listener ) ) {
            return ctrue; // message handled
        }
    }

    return cfalse;  
}