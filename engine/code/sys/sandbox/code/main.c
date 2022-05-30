#include <core/interface.h>
#include <core/c_memory.h>
#include <shared.h>
#include <core/io/logger.h>
#include <core/darray.h>
#include <sys/sys.h>

#include <shared.h>

csConfig_t config;


typedef struct {
    float b;
    int a;
} test_t;

// #include <windows.h>

int main( int argc, char **argv )
{
    // unsigned char *test;
    config.winTitle = "Test";
    config.winStartupW = 800;
    config.winStartupH = 600;

    //  SetDllDirectory( "c:/coldspot/engine/bin"); //test

    test_t t;
     test_t u = { 23, 45 };
    test_t v = { 100, 243 };        
    test_t dst;
    t.a = 12;
    t.b = 4.3f;
    // long long i = ARRAY_GET_LE_LLONG( &a[8] );
    
    unsigned char* a = DArray_Alloc( 10, sizeof(t) );
    // int a[8] = { 0x12, 0x34, 0x56, 0x78, 0x11, 0x22, 0x33, 0x44 };
    // printf( "hhello\n" );
    
    // int dst[3];
    CS_Init( &config );
    
    // Log_Printf( ERRTYPE_MESSAGE, "%llx\n", i );
    // test = C_Malloc( 100, MEMTAG_DARRAY );

    // printf( "%s", Mem_GetStatusString() );    
    Log_Printf( ERRTYPE_MESSAGE, "%d\n", DArray_GetFieldValue( a, AHDR_CAPACITY ) );
    Log_Printf( ERRTYPE_MESSAGE, "%d\n", DArray_GetFieldValue( a, AHDR_STRIDE ) );

    // int s[3] = { 1, 2, 3 };
    DArray_Push( a, &t );
        DArray_Push( a, &u );
            DArray_Push( a, &v );
    DArray_Pop( a, &dst );

    Log_Printf( ERRTYPE_MESSAGE, "%d\n", dst.a );
    Log_Printf( ERRTYPE_MESSAGE, "%f\n", dst.b );

    DArray_Pop( a, &dst );

    Log_Printf( ERRTYPE_MESSAGE, "%d\n", dst.a );
    Log_Printf( ERRTYPE_MESSAGE, "%f\n", dst.b );

    DArray_Pop( a, &dst );

    Log_Printf( ERRTYPE_MESSAGE, "%d\n", dst.a );
    Log_Printf( ERRTYPE_MESSAGE, "%f\n", dst.b );    

    CS_Run();

    CS_Quit();
    DArray_Free( a );

    // C_Free( test, 100, MEMTAG_DARRAY );

    return 0;
}