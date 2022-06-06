#include "rbackend.h"


#include "rshared.h"

void RB_Init( renderBackendAPI_t api, renderBackend_t *rbOut )
{
    switch( api ) {
            case RBACKEND_OPENGL:
            rbOut->Init = GL_InitBackend;
        break;
        case RBACKEND_DIRECT3D:
            // rbOut->Init = D3D_InitBackend;
            break;
        case RBACKEND_VULKAN:
            rbOut->Init = VK_InitBackend;
            break;
        default:
            break;
    }
    // if ( api == RBACKEND_OPENGL ) {
    //     rbOut->Init = GL_InitBackend;
    // }
    // else if ( api == RBACKEND_VULKAN ) {
    //     rbOut->Init = VK_InitBackend;
    // }
}