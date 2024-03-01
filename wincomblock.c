/* Caio Madeira */

// If _WIN32 (x64 or x86) include the library
#ifdef _WIN32
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#endif

void block()
{
    printf(">COM-BLOCKER: Process Attached.\n");
    #ifdef _WIN64 // Only 64x
        printf("Win x64-bit"); puts("");
    #else // 86x
        printf("Win x86-bit"); puts("");
    #endif
    Sleep(1000);
}


// DLL entry point
BOOL WINAPI DllMain(HINSTANCE h, DWORD reason, LPVOID reserved)
{
    if (reason == DLL_PROCESS_ATTACH)
    {
        block();
        return TRUE;
    } 
    else if (reason == DLL_PROCESS_DETACH) {
        Sleep(1000);
        printf(">COM-BLOCKER: Process Detached.\n");
    }
}