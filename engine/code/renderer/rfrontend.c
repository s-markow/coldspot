#include "rfrontend.h"
#include "rbackend.h"

typedef struct {
    renderBackend_t renderBackend;
} rsys_t;

static rsys_t* rsys;

void RF_Init()
{
    RB_Init( RBACKEND_OPENGL, &rsys->renderBackend );
    // RB_Init( api select prioritize, )
}

void RF_Clean()
{
}

void RF_RenderFrame()
{
}

void RF_InitTexture( /* texture_t *tex*/ )
{
}

void RF_CleanTexture( /* texture_t *tex*/ )
{
}