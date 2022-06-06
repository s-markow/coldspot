#include "filesys.h"

#include <stddef.h>

hfile_t *FS_Open( const char* filepath, int mode )
{
    return NULL;
}

void FS_Close( hfile_t *file )
{
}

void FS_Write( hfile_t *file, size_t dataSize, const void *bytes, size_t *bytesWritten )
{
}

void FS_ReadAll( hfile_t *file, byte *out, size_t *bytesRead )
{
}