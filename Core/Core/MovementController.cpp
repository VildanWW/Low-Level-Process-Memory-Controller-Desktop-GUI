#include "pch.h"
#include "MovementController.h"
#include "MinHook.h"
#include "Offsets.h"
#include <Windows.h>
#include <math.h>

void MovementController::Initialize() {
	uintptr_t absoluteMoveAddress = Offsets::clientBase + GameFunctions::moveAddress;

	MH_CreateHook((LPVOID)absoluteMoveAddress, &MovementController::hk_MoveHandler, (LPVOID*)&MovementController::o_MoveHandler);
	MH_EnableHook((LPVOID)absoluteMoveAddress);

	//uintptr_t absoluteRotationAddress = Offsets::hwBase + GameFunctions::rotationAddress;

	//MH_CreateHook((LPVOID)absoluteRotationAddress, &MovementController::hk_rotationHandler, (LPVOID*)&MovementController::o_rotationHandler);
	//MH_EnableHook((LPVOID)absoluteRotationAddress);
}

void MovementController::ShutDown() {
	uintptr_t absoluteMoveAddress = Offsets::clientBase + GameFunctions::moveAddress;
	MH_DisableHook((LPVOID)absoluteMoveAddress);

	//uintptr_t absoluteRotationAddress = Offsets::hwBase + GameFunctions::rotationAddress;
	//MH_DisableHook((LPVOID)absoluteRotationAddress);
}

unsigned int __fastcall MovementController::hk_MoveHandler(char param_1) {
	unsigned int originalValue = o_MoveHandler(param_1);
	unsigned int modifiedValue = originalValue;

	if (GetAsyncKeyState(VK_SPACE) & 0x8000) 
	{
		int* airAddress = (int*)(Offsets::clientBase + Offsets::jumpAddress);

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

void __stdcall MovementController::hk_RotationHandler(float* param_1) {}