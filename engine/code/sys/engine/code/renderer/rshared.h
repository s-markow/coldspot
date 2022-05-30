#ifndef __RSHARED_H
#define __RSHARED_H

#include <stddef.h>

// #ifdef _WIN32
// #define VK_USE_PLATFORM_WIN32_KHR
// #include "vulkan/vulkan.h"
// #include "vulkan/vk_sdk_platform.h"
// #else
// #define VK_USE_PLATFORM_XCB_KHR
// #include <vulkan/vulkan.h>
// #include <vulkan/vk_sdk_platform.h>
// #endif

void GL_InitBackend();
void VK_InitBackend();

typedef enum {
    RBACKEND_OPENGL,
    RBACKEND_VULKAN,
    RBACKEND_DIRECT3D
} renderBackendAPI_t;

#endif