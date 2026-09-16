#include "pch.h"
#include "MovementController.h"
#include "MinHook.h"
#include "Offsets.h"

void MovementController::Initialize() {
	MH_CreateHook((LPVOID)(Offsets::clientBase + GameFunctions::moveAddress), &MovementController::hk_moveHandler, (LPVOID*)&MovementController::o_moveHandler);
	
	MH_EnableHook((LPVOID)(Offsets::clientBase + GameFunctions::moveAddress));
}

void MovementController::ShutDown() {
	MH_DisableHook((LPVOID)(Offsets::clientBase + GameFunctions::moveAddress));
}

unsigned int __fastcall MovementController::hk_moveHandler(char param_1) {
    unsigned int originalValue = o_moveHandler(param_1);
    unsigned int modifiedValue = originalValue;

    if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
        int* airAddress = (int*)(Offsets::clientBase + Offsets::jumpAddress);

        if (airAddress != nullptr) {
            int airState = *airAddress;

            if (airState == 0) { 
                modifiedValue = originalValue | 2;
            }
            else {
                modifiedValue = originalValue & 0xfffffffd;
            }
        }
    }
    return modifiedValue;
}