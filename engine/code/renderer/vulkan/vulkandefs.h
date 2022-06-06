#ifndef __VULKANDEFS_H
#define __VULKANDEFS_H

#include <vulkan/vulkan.h>
#if defined(CS_WIN32_DEFINED)
#include <windows.h>
#include <vulkan/vulkan_win32.h>
#elif defined(CS_LINUX_DEFINED)
#include <vulkan/
#endif

typedef struct {
    VkInstance instance;
    VkAllocationCallbacks* allocator;
    VkSurfaceKHR surface;
} vulkanContext_t;

cbool Sys_CreateVulkanSurface( vulkanContext_t *context );

#endif