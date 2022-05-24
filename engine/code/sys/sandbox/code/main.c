#include <core/interface.h>
#include <core/memory.h>
#include <core/io/logger.h>
#include <core/darray.h>
#include <sys/sys.h>

#include <shared.h>

csConfig_t config;

int main( int argc, char **argv )
{
    unsigned char *test;
    config.winTitle = "Test";
    config.winStartupW = 800;
    config.winStartupH = 600;

    unsigned char* a = DArray_Alloc( 10, 4 );
    // int a[8] = { 0x12, 0x34, 0x56, 0x78, 0x11, 0x22, 0x33, 0x44 };
    // printf( "hhello\n" );
    
    Log_Printf( ERRTYPE_MESSAGE, "%d\n", DArray_GetFieldValue( a, AHDR_CAPACITY ) );
    CS_Init( &config );
    
    // test = C_Malloc( 100, MEMTAG_DARRAY );

    // printf( "%s", Mem_GetStatusString() );    
    // Log_Printf( ERRTYPE_MESSAGE, "%04x", ARRAY_GET_LE_LONG(&a[4]) );
    CS_Run();

    CS_Quit();
    DArray_Free( a );

    // C_Free( test, 100, MEMTAG_DARRAY );

    return 0;
}