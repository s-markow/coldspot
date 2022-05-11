#include <windows.h>

#ifdef main
#undef main
#endif

extern HINSTANCE g_hInstance;
int main( int argc, char **argv );

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int nCmdShow )
{
   int argc;
   char **argv;

   (void)hPrevInstance;

   g_hInstance = hInstance;
   return main( argc, argv );
}
