#include "pch.h"
#include "AntiFlash.h"

void AntiFlash::Initialize() {
	running = true;

	screenToken = EventBus::SubscribeScreen([this](const char* param_1, int param_2, const unsigned char* param_3) {
		return HandleAntiFlashScreen(param_1, param_2, param_3);
	});
}

void AntiFlash::ShutDown() {
	running = false;

	EventBus::UnsubscribeScreen(screenToken);
}

bool AntiFlash::HandleAntiFlashScreen(const char* param_1, int param_2, const unsigned char* param_3) {
	return false;
}
