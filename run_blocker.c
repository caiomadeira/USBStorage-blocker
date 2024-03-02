/* Caio Madeira */

#ifdef _WIN32
#include<windows.h>
#endif

#define FILENAME "wincomblock.dll"

void main()
{
    LoadLibraryA(FILENAME);

}