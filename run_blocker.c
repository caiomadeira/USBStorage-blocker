/* Caio Madeira */

#ifdef _WIN32
#include<Windows.h>
#endif

#define FILENAME "wincomblock.dll"

void main()
{
    LoadLibraryA(FILENAME);

}