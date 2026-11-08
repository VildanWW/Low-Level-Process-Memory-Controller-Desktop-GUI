// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"

#include <mutex>
#include <condition_variable>
#include <thread>
#include "spdlog/sinks/msvc_sink.h"
#include <spdlog/spdlog.h>

#include "MinHook.h"
#include "Hooks.h"
#include "Offsets.h"
#include "FunctionalsManager.h"
#include "JsonSerializer.h"

namespace Core {

    namespace {
        std::mutex shutdownMutex;
        std::condition_variable shutdownSV;
        bool shutDownProgram = false;
    }

    extern void RequestShutdown() { 
        {
            std::lock_guard<std::mutex> lock(shutdownMutex);
            shutDownProgram = true;
            shutdownSV.notify_one();
        }
    }

    void InitializeLogger() {
        auto msvc_sink = std::make_shared<spdlog::sinks::msvc_sink_mt>();
        auto logger = std::make_shared<spdlog::logger>("msvc_logger", msvc_sink);
        spdlog::set_default_logger(logger);
        spdlog::set_level(spdlog::level::trace);
    }

    DWORD WINAPI MainThread(LPVOID lpParam) {
        InitializeLogger();
        Utils::JsonSerializer::Initialize();

        MH_Initialize();
        Offsets::InitializeOffsets();
        Hooks::Initialize();

        Functionals::FunctionalsManager functionalManager;
        functionalManager.InitializeAddressesAndModules();
        functionalManager.StartWorking();

        std::unique_lock<std::mutex> lock(shutdownMutex);
        shutdownSV.wait(lock, []() { return shutDownProgram; });

        Hooks::unloadingFromGame = true;

        while (Hooks::activeHooksCount > 0) {
            std::this_thread::yield();
        }

        spdlog::info("Active hooks count: {}", Hooks::activeHooksCount.load());
        Utils::JsonSerializer::LoadToFile();

        functionalManager.Shutdown();
        Hooks::ShutDown();
        MH_Uninitialize();

        FreeLibraryAndExitThread((HMODULE)lpParam, 0);
        return 0;
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        CreateThread(NULL, 0, Core::MainThread, hModule, 0, NULL);
    }
    return TRUE;
}
