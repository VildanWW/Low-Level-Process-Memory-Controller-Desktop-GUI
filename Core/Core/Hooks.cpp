#include "pch.h"
#include "Hooks.h"
#include "Offsets.h"
#include "MinHook.h"
#include "EventBus.h"

void Hooks::Initialize() {
	MH_CreateHook((LPVOID)Offsets::absoluteMoveAddress, &hk_MoveHandler, (LPVOID*)&o_MoveHandler);
	MH_CreateHook((LPVOID)Offsets::absoluteScreenAddress, &hk_ScreenHandler, (LPVOID*)&o_ScreenHandler);

	MH_EnableHook(MH_ALL_HOOKS);
}

void Hooks::ShutDown() {
	MH_DisableHook(MH_ALL_HOOKS);

	EventBus::moveList.clear();
	EventBus::screenList.clear();
}

unsigned int __fastcall Hooks::hk_MoveHandler(char param_1) {
	unsigned int value = o_MoveHandler(param_1);

	for (const auto& [token, callback] : EventBus::moveList) {
		value = callback(param_1, value);
	}
	return value;
}

unsigned int __cdecl Hooks::hk_ScreenHandler(const char* param_1, int param_2, const unsigned char* param_3) {
	bool allowMessage = true;

	for (const auto& [token, callback] : EventBus::screenList) {
		if (!callback(param_1, param_2, param_3)) {
			allowMessage = false; 
		}
	}

	if (!allowMessage) {
		return 1;
	}

	return o_ScreenHandler(param_1, param_2, param_3);
}
