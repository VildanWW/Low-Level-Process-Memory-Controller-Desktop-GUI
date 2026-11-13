#include "pch.h"

#include <Windows.h>

#include "Bhop.h"
#include "Offsets.h"
#include "Config.h"
#include "EventBus.h"

namespace Core {
    namespace Functionals {
        void Bhop::Initialize() {
            moveToken = Events::EventBus::SubscribeMove([this](char param_1, unsigned int value) {
                return HandleBhopMove(param_1, value);
            });
        }

        void Bhop::ShutDown() {
            Events::EventBus::UnsubscribeMove(moveToken);
        }

        unsigned int Bhop::HandleBhopMove(char param_1, unsigned int value) {
            if (Offsets::airAddress == nullptr) return value;

            if ((GetAsyncKeyState(Offsets::bhopKey) & 0x8000) && Settings::configSettings.movement.bhop.running) {
                if (*Offsets::airAddress == 0)
                    value |= Offsets::jumpFlag;
                else
                    value &= ~Offsets::jumpFlag;
            }
            return value;
        }
    }
}
