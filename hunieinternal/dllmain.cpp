// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include <iostream>
#include <vector>
#include <TlHelp32.h>
#include <Psapi.h>
DWORD GetPointerAddress(DWORD ptr, std::vector<DWORD> offsets) {
    DWORD addr = ptr;
    for (int i = 0; i < offsets.size();i++) {
        addr = *(DWORD*)addr;
        addr += offsets[i];

    }
    return addr;

} 
int points;
DWORD WINAPI MainThread(HMODULE hModule) {
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);
    
    printf("huniepop trainer by donaldemil360\n");
    printf("f12 to take off top \n");
    printf("f11 to get inf money\n");
    printf("f10 to finish level\n");
    
    
    Sleep(2000);
    AllocConsole();
    FILE* fd;
    freopen_s(&fd, "CONIN$", "r", stdin);

    DWORD moduleBase = (DWORD)GetModuleHandle("mono.dll");
    DWORD modulebase2 = (DWORD)GetModuleHandle("HuniePop.exe");
    int x = 100;
    while (!GetAsyncKeyState(VK_END)) {
        if (GetAsyncKeyState(VK_F12) & 1) {
            int* topOff = (int*)GetPointerAddress(moduleBase + 0x001F3948, { 0x58,0x554,0x10,0x1C,0x4,0x24,0xC,0xB4,0x58,0xA80 });
            *topOff = 1166774416;
            std::cout << "her top is off, "<<"its NNN what are u doing?\n";
            Sleep(2000);
            *topOff = 1166746494;
        }
        if (GetAsyncKeyState(VK_F11) &1) {
            int* money = (int*)GetPointerAddress(modulebase2 + 0x009585E0, { 0xC,0x268,0x80,0x6C,0x14,0x14,0x68 });
            *money = 99999;
            std::cout << "money is now: " << *money << std::endl << "no longer brokie\n";
        }
        if (GetAsyncKeyState(VK_F10) &1) {
            int* totalpt = (int*)GetPointerAddress(moduleBase + 0x002021B4, { 0x298,0x90,0x90,0x8C,0x14,0x10,0xA4 });
            int* pointchange = (int*)GetPointerAddress(moduleBase + 0x002021B4, { 0x298,0x90,0x90,0x8C,0x14,0x10,0xA0 });
            *pointchange = *totalpt;
            std::cout << "successfully completed level\n"<<"fucking noob\n";
            
        }
        

    }
    if (GetAsyncKeyState(VK_END)) {
        fclose(f);
        fclose(fd);
        FreeConsole();
    }
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MainThread, NULL, 0, NULL);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

