#include "../../shared.h"
#include <string.h>
#include "vulkandefs.h"

static vulkanContext_t vkContext;

// static char* extensions[100];

// return false when one required extension not found
/*static*/ cbool VK_ValidateRequiredExtensions( const char **required, VkExtensionProperties *available, int nExtensions, int nAvailable )
{
    for ( int i = 0; i < nExtensions; i++ ) {
        cbool found = cfalse;
        for ( int i = 0; i < nAvailable; i++ ) {
            if ( !strcmp( available[i].extensionName, required[i] ) ) {
                return ctrue;
                break;
            }
        }

        if ( !found ) {
            return cfalse;
        }
    }

    return ctrue;
}

// return false when one required layer not found
/*static*/ cbool VK_ValidateRequiredLayers( const char **required, VkLayerProperties *available, int nLayers, int nAvailable )
{
    for ( int i = 0; i < nLayers; i++ ) {
        cbool found = cfalse;
        for ( int i = 0; i < nAvailable; i++ ) {
            if ( !strcmp( available[i].layerName, required[i] ) ) {
                return ctrue;
                break;
            }
        }

        if ( !found ) {
            return cfalse;
        }
    }

    return ctrue;
}

void VK_InitBackend()
{
    VkApplicationInfo vkAppInfo;
    VkInstanceCreateInfo vkCreateInfo;

    vkAppInfo.sType                 = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    vkAppInfo.apiVersion            = VK_API_VERSION_1_2;
    vkAppInfo.pApplicationName      = "temp";
    vkAppInfo.applicationVersion    = VK_MAKE_VERSION(1, 0, 0);
    vkAppInfo.pEngineName           = "CS Engine";
    vkAppInfo.engineVersion         = VK_MAKE_VERSION(1, 0, 0);

    vkCreateInfo.sType                  = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    vkCreateInfo.pApplicationInfo       = &vkAppInfo;
    // vkCreateInfo.enabledExtensionCount  =
    // vkCreateInfo.ppEnabledExtensionNames    =
    // vkCreateInfo.enabledLayerCount      =
    // vkCreateInfo.ppEnabledLayerNames    =

    Sys_CreateVulkanSurface( &vkContext );
}