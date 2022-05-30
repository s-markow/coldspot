#ifndef __FILESYS_H
#define __FILESYS_H

#include "../shared.h"

#define FILE_READ       1
#define FILE_WRITE      2

typedef struct {
    void *h;
} hfile_t;

hfile_t *FS_Open( const char* filepath, int mode );

#endif