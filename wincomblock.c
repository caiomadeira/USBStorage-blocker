/* 
Caio Madeira 

For x86_x64 visual command line tools compiler

C:\Users\Administrator\Documents\GitHub\COM-blocker
cd C:\Users\vboxuser\Desktop\COM-blocker
cl /LD wincomblock.c
cl run_blocker.c
run_blocker.exe

cd C:\Users\vboxuser\Desktop\COM-blocker && cl /LD wincomblock.c && cl run_blocker.c && run_blocker.exe
cd C:\Users\Administrator\Documents\GitHub\COM-blocker && cl /LD wincomblock.c && cl run_blocker.c && run_blocker.exe

*/
#define _CRT_NO_SECURE_WARNINGS
// If _WIN32 (x64 or x86) include the library
#ifdef _WIN32
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#endif

// HEADER FUNCTIONS
void block();
void unblock();

void block()
{   
    // reg add HKLM\System\CurrentControlSet\Services\USBSTOR /t REG_DWORD /v "Start" /d 4 /f 
    // reg add HKLM\System\CurrentControlSet\Services\USBSTOR /t REG_DWORD /v Start /d 4 /f 
    char block_cmd[] = "reg add HKLM\\System\\CurrentControlSet\\Services\\USBSTOR /t REG_DWORD /v Start /d 4 /f";

    printf("block: %s", block_cmd);

    #ifdef _WIN64 // Only 64x
        printf("Win x64-bit.\n"); puts("");
        system(block_cmd);
        printf("blocked\n"); puts("");
    #else // 86x
        printf("Win x86-bit"); puts("");
        system(block_cmd);
        printf("blocked\n"); puts("");
    #endif
    //MessageBox(0, "Sucess!", "USB PORTS BLOCKED", 1);
}

void unblock()
{
    // 3 - FOR UNBLOCK
    // reg add HKLM\System\CurrentControlSet\Services\USBSTOR /t REG_DWORD /v "Start" /d 3 /f 
    char block_cmd[] = "reg add HKLM\\System\\CurrentControlSet\\Services\\USBSTOR /t REG_DWORD /v Start /d 1 /f";

    printf("unblock: %s", block_cmd);

    #ifdef _WIN64 // Only 64x
        printf("Win x64-bit.\n"); puts("");
        system(block_cmd);
        printf("unblocked\n"); puts("");
    #else // 86x
        printf("Win x86-bit"); puts("");
        system(block_cmd);
        printf("unblocked\n"); puts("");
    #endif
    //MessageBox(0, "Sucess!", "USB PORTS BLOCKED", 1);
}

// DLL entry point
BOOL WINAPI DllMain(HINSTANCE h, DWORD reason, LPVOID reserved)
{
    int choice;
    if (reason == DLL_PROCESS_ATTACH)
    {
        printf("NOTA: O PROGRAMA DEVE SER EXECUTADO COM PRIVILEGIOS DE ADMINISTRADOR.\n");
        printf(">COM-BLOCKER: Process Attached.\n");
        printf("> Digite 0 para BLOQUEAR todas portas USB: \n");
        printf("> Digite 1 para DESBLOQUEAR todas portas USB: \n");
        scanf("%d", &choice);

        if (choice == 0)
        {
            block();
        } 
        else if (choice == 1) 
        {
            unblock();
        }
        else 
        {
           printf("Opcao invalida.\n");
           exit(-1);
        }

        return TRUE;
    } 
    else if (reason == DLL_PROCESS_DETACH) {
        Sleep(1000);
        printf(">COM-BLOCKER: Process Detached.\n");
    }
    
    system("pause");
}