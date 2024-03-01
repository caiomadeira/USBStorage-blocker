#include<stdio.h>
#include<Windows.h>

// DLL entry point

BOOL WINAPI DllMain(HINSTANCE h, DWORD reason, LPVOID reserved)
{
    if (reason == DLL_PROCESS_ATTACH)
    {
        printf("COM-BLOCKER: Process Attached.\n");
        Sleep(1000);
        return TRUE;
    } 
    else if (reason == DLL_PROCESS_DETACH) {
        Sleep(1000);
        printf("COM-BLOCKER: Process Detached.\n");
    }
}