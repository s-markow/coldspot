#ifndef __VULKANDEFS_H
#define __VULKANDEFS_H

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_win32.h>

typedef struct {
    VkInstance instance;
    VkAllocationCallbacks* allocator;
    VkSurfaceKHR surface;
} vulkanContext_t;

cbool Sys_CreateVulkanSurface( vulkanContext_t *context );

#endif