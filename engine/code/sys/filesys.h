#ifndef __FILESYS_H
#define __FILESYS_H

#include "../shared.h"

#define FILE_READ       1
#define FILE_WRITE      2

typedef struct {
    void *h;
} hfile_t;

CSAPI hfile_t *FS_Open( const char* filepath, int mode );
CSAPI void FS_Close( hfile_t *file );
CSAPI void FS_Write( hfile_t *file, size_t dataSize, const void *bytes, size_t *bytesWritten );
CSAPI void FS_ReadAll( hfile_t *file, byte *out, size_t *bytesRead );

#endif