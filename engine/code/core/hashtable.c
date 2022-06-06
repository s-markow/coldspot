#include "hashtable.h"

#include "shared.h"

typedef struct
{
    int elemCount;
    int elemSize;
    void *data;
} hashTable_t;

CSAPI void HashTable_Create( hashTable_t *hashTable );
CSAPI void HashTable_Clean( hashTable_t *hashTable );
CSAPI cbool HashTable_Set( hashTable_t *hashTable, const char *name, void *inValue );
CSAPI cbool HashTable_Get( hashTable_t *hashTable, const char *name, void *outValue );
