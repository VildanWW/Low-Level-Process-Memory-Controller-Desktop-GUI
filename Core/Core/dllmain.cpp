// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include "MinHook.h"
#include "BaseFunctional.h"
#include "Offsets.h"
#include "MovementController.h"
#include <memory>
#include <vector>

void Initialize(std::vector<std::unique_ptr<BaseFunctional>>& functional) {
    Offsets::clientBase = (uintptr_t)GetModuleHandleA("client.dll");

    functional.push_back(std::make_unique<MovementController>());
}

DWORD WINAPI MainThread(LPVOID lpParam) {
    MH_Initialize();

    std::vector<std::unique_ptr<BaseFunctional>> functional;

    Initialize(functional);

    for (int i = 0; i < functional.size(); i++) {
        functional[i]->Initialize();
    }

    while (!(GetAsyncKeyState(VK_END) & 0x8000)) {
        Sleep(100);
    }

    for (int i = 0; i < functional.size(); i++) {
        functional[i]->ShutDown();
    }

    MH_Uninitialize();
    FreeLibraryAndExitThread((HMODULE)lpParam, 0);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        CreateThread(NULL, 0, MainThread, hModule, 0, NULL);
    }
    return TRUE;
}