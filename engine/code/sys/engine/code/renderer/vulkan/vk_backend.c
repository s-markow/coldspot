#include "../../shared.h"
#include "vulkandefs.h"

static vulkanContext_t vkContext;

void VK_InitBackend()
{
    Sys_CreateVulkanSurface( &vkContext );
}