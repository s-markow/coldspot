#ifndef __RSHARED_H
#define __RSHARED_H

typedef enum {
    RBACKEND_OPENGL,
    RBACKEND_VULKAN,
    RBACKEND_DIRECT3D
} renderBackend_t;

#define