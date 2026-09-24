#include "pch.h"
#include "Bhop.h"
#include "Hooks.h"
#include "Offsets.h"

void Bhop::Initialize() {
	running = true;
	
	moveToken = EventBus::SubscribeMove([this](char param_1, unsigned int value) {
		return HandleBhopMove(param_1, value);
	});
}

void Bhop::ShutDown() {
	running = false;
	EventBus::UnsubscribeMove(moveToken);
}

unsigned int Bhop::HandleBhopMove(char param_1, unsigned int value) {
    if (Offsets::airAddress == nullptr) return value;

    if (GetAsyncKeyState(Offsets::bhopKey) & 0x8000) {
        if (*Offsets::airAddress == 0)
            value |= Offsets::jumpFlag;
        else
            value &= ~Offsets::jumpFlag;
    }
    return value;
}