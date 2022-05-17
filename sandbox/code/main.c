#include <core/interface.h>
#include <sys/sys.h>

csConfig_t config;

int main( int argc, char **argv )
{
    config.winTitle = "Test";
    config.winStartupW = 800;
    config.winStartupH = 600;
    CS_Init( &config );
    CS_Run();
    CS_Quit();

    return 0;
}