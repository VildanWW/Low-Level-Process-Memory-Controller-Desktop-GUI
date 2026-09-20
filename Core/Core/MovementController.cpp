#include "pch.h"
#include "MovementController.h"
#include "MinHook.h"
#include <Windows.h>
#include <math.h>

void MovementController::Initialize() {
	MH_CreateHook((LPVOID)Offsets::absoluteMoveAddress, &MovementController::hk_MoveHandler, (LPVOID*)&MovementController::o_MoveHandler);
	MH_CreateHook((LPVOID)Offsets::absoluteScreenAddress, &MovementController::hk_ScreenHandler, (LPVOID*)&MovementController::o_ScreenHandler);

	MH_EnableHook(MH_ALL_HOOKS);

	//uintptr_t absoluteRotationAddress = Offsets::hwBase + GameFunctions::rotationAddress;
	//MH_CreateHook((LPVOID)absoluteRotationAddress, &MovementController::hk_rotationHandler, (LPVOID*)&MovementController::o_rotationHandler);
	//MH_EnableHook((LPVOID)absoluteRotationAddress);
}

void MovementController::ShutDown() {
	MH_DisableHook(MH_ALL_HOOKS);

	//uintptr_t absoluteRotationAddress = Offsets::hwBase + GameFunctions::rotationAddress;
	//MH_DisableHook((LPVOID)absoluteRotationAddress);
}

unsigned int __fastcall MovementController::hk_MoveHandler(const char param_1) {
	unsigned int originalValue = o_MoveHandler(param_1);
	unsigned int modifiedValue = originalValue;

	if (Offsets::airAddress != nullptr) {
		int airState = *Offsets::airAddress; 

		if (GetAsyncKeyState(Offsets::bhopKey) & 0x8000) {
			if (airState == 0) {
				modifiedValue |= Offsets::jumpFlag; 
			}
			else {
				modifiedValue &= ~Offsets::jumpFlag;
			}
		}
	}

	return modifiedValue;
}

unsigned int __cdecl MovementController::hk_ScreenHandler(const char* param_1, int param_2, const unsigned char* param_3) {
	// Оставляем тело функции пустым, тем самым блокируя обработку сетевого сообщения ослепления
	return 1;
}

//void __stdcall MovementController::hk_RotationHandler(float* param_1) {}