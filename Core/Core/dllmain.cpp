// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include "MinHook.h"
#include "BaseFunctional.h"
#include "Hooks.h"
#include "Offsets.h"
#include "Bhop.h"      
#include "AntiFlash.h"
#include <memory>
#include <vector>


void InitializeAddressesAndModules(std::vector<std::unique_ptr<BaseFunctional>>& functional) {
    Offsets::clientBase = (uintptr_t)GetModuleHandleA("client.dll");
    Offsets::hwBase = (uintptr_t)GetModuleHandleA("hw.dll");
    Offsets::absoluteMoveAddress = Offsets::clientBase + GameFunctions::moveAddress;
    Offsets::absoluteScreenAddress = Offsets::hwBase + GameFunctions::screenFadeAddress;

    Offsets::airAddress = (int*)(Offsets::clientBase + Offsets::jumpAddress);

    functional.push_back(std::make_unique<Bhop>());
    functional.push_back(std::make_unique<AntiFlash>());
}

DWORD WINAPI MainThread(LPVOID lpParam) {
    MH_Initialize();

    std::vector<std::unique_ptr<BaseFunctional>> functional;

    InitializeAddressesAndModules(functional);

    Hooks::Initialize();

    for (size_t i = 0; i < functional.size(); i++) {
        functional[i]->Initialize();
    }

    while (!(GetAsyncKeyState(VK_END) & 0x8000)) {
        Sleep(1);
    }

    for (size_t i = 0; i < functional.size(); i++) {
        functional[i]->ShutDown();
    }

    Hooks::ShutDown();
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