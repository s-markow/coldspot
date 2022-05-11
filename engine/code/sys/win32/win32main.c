#include "win32shared.h"

#ifdef main
#undef main
#endif

int main( int argc, char **argv );

// main entry point for win32 applications
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int nCmdShow )
{
   int argc;
   char **argv;

   (void)hPrevInstance;

   winState.hInstance = hInstance;
   argc = 0; // tmp
   argv = NULL; // tmp

   return main( argc, argv );
}
