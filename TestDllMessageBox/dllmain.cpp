// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <Windows.h>
#include <cstdio>

DWORD WINAPI ThreadMain(HMODULE m) 
{
    HANDLE hx = new HANDLE();
    HWND window_rust = FindWindowA(0, "Rust");
    if (!window_rust) {
        MessageBoxA(0, "Are You Sure It's Rust Window? :0", "TestDll", MB_OK || MB_SETFOREGROUND || MB_ICONQUESTION);
        DisableThreadLibraryCalls(m);
        CloseHandle(hx); //Current Handle Closing :D
    }
    MessageBoxA(window_rust, "Hello World!!!", "TestDll", MB_OK || MB_SETFOREGROUND); //MessageBox :D
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout); //Console :D
    printf("Hello From RustClient :D");
    return TRUE;
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ThreadMain, 0, 0, 0); //CreateThread :D
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

