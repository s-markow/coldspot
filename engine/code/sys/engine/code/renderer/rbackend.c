#include "rbackend.h"


#include "rshared.h"

void RB_Create( renderBackendAPI_t api, renderBackend_t *rbOut )
{
    if ( api == RBACKEND_OPENGL ) {
        rbOut->Init = GL_InitBackend;
    }
    else if ( api == RBACKEND_VULKAN ) {
        rbOut->Init = VK_InitBackend;
    }
}