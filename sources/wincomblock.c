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

#include <stdio.h>
#include <windows.h>
#include <locale.h>

#define _CRT_NO_SECURE_WARNINGS

// HEADER FUNCTIONS
void WinRegistry();
void block();

/*
******************
 NOT FINISHED YET
******************
*/
//void WinRegistry()
//{   
     // %p is used to print value of any variable in hexa-decimal form
  //  printf("> KEY_LOCAL_MACHINE (%p)", HKEY_LOCAL_MACHINE);

    //long long llReturn;
    //HKEY key;
    //WCHAR wszRegistryKeyName[] = L"SOFTWARE\\Policies\\Microsoft\\Windows";

    // The RegOpenKeyEx takes 5 params:
    /*
        1 - The first is an HKEY and can be the path of the localization of the Key;
        2 - The second is the name of a subkey that we wish to open. The subkey can be a path
            or we can specify NULL;
        3 - The third is reserved. We must specify 0 here. (Don't mess with this guy for now);
        4 - The fourth parameter is an access mask that describes the security level for the new key;
    */
    //llReturn = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
                        //wszRegistryKeyName,
                        //0,
                        //KEY_READ,
                        //&key);

    // Checking the return value

    //if (llReturn == ERROR_SUCCESS)
    //{
     //   printf("Key acquired!!!");
    //}
    //else {
      //  printf("Duplicate registry keu not created.");
        //exit(EXIT_FAILURE);
    //}

    // We should close an open key handle with RegCloseKey() function.
    //RegCloseKey(key);
//}

void block()
{   
    // reg add HKLM\System\CurrentControlSet\Services\USBSTOR /t REG_DWORD /v "Start" /d 4 /f 
    // reg add HKLM\System\CurrentControlSet\Services\USBSTOR /t REG_DWORD /v Start /d 4 /f 
    char block_cmd[] = "reg add HKEY_LOCAL_MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\RemovableStorageDevices /v Deny_All /t REG_DWORD /d 1";

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

// DLL entry point
BOOL WINAPI DllMain(HINSTANCE h, DWORD reason, LPVOID reserved)
{
    setlocale(LC_ALL, "");
    int choice;
    // WinRegistry();
    if (reason == DLL_PROCESS_ATTACH)
    {
        printf("\nNOTA: O PROGRAMA DEVE SER EXECUTADO COM\033[0;33m PRIVILEGIOS DE ADMINISTRADOR.\n\033[0m");
        printf("\n> Process Attached.\n");
        printf("> Digite 0 para BLOQUEAR todas portas USB: \n");
        printf("> Digite 1 para DESBLOQUEAR todas portas USB: ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            block();
            Sleep(500);
            printf("[!] O Windows será reiniciado para que as alteracoes sejam aplicadas.\n");
            Sleep(500);
            system("C:\\WINDOWS\\System32\\shutdown /r");
        } 
        else if (choice == 1) 
        {
            printf("> Opcao indisponivel no momento.\n");
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
        printf("> Process Detached.\n");
    }
    
}