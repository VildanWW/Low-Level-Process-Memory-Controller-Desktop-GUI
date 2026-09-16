#include "pch.h"
#include "MovementController.h"
#include "MinHook.h"
#include "Offsets.h"
#include <Windows.h>

void MovementController::Initialize() {
	uintptr_t absoluteMoveAddress = Offsets::clientBase + GameFunctions::moveAddress;

	MH_CreateHook((LPVOID)absoluteMoveAddress, &MovementController::hk_moveHandler, (LPVOID*)&MovementController::o_moveHandler);
	
	MH_EnableHook((LPVOID)absoluteMoveAddress);
}

void MovementController::ShutDown() {
	uintptr_t absoluteMoveAddress = Offsets::clientBase + GameFunctions::moveAddress;
	MH_DisableHook((LPVOID)absoluteMoveAddress);
}

unsigned int __fastcall MovementController::hk_moveHandler(char param_1) {
	unsigned int originalValue = o_moveHandler(param_1);
	unsigned int modifiedValue = originalValue;

	if (GetAsyncKeyState(VK_SPACE) & 0x8000) 
	{
		DWORD_PTR clientBase = (DWORD_PTR)GetModuleHandleA("client.dll");
		int* airAddress = (int*)(clientBase + Offsets::jumpAddress);

		if (airAddress != nullptr) 
		{
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

