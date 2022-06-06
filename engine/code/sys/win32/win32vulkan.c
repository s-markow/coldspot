#include "../../shared.h"

#ifdef CS_WIN32_DEFINED

#include "win32shared.h"
#include "core/io/logger.h"

#include "../../renderer/vulkan/vulkandefs.h"

extern winState_t winState;

VkSurfaceKHR vkSurface;

cbool Sys_CreateVulkanSurface( vulkanContext_t *context )
{
    if ( !winState.hInstance )
        return cfalse;
    VkWin32SurfaceCreateInfoKHR createInfo = {VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR};

    createInfo.hinstance = winState.hInstance;
    createInfo.hwnd = winState.hWnd;

    if ( vkCreateWin32SurfaceKHR(context->instance, &createInfo, context->allocator, &vkSurface) != VK_SUCCESS ) {
        Log_Printf( ERRTYPE_FATAL, "Can't create Vulkan surface.\n" );
        return cfalse;
    }

    context->surface = vkSurface;
    
    return ctrue;
}

#endif