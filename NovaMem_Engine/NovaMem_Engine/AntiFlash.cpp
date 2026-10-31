#include "pch.h"
#include "AntiFlash.h"

namespace Core {
	namespace Functionals {
		void AntiFlash::Initialize() {
			running = true;

			screenToken = Events::EventBus::SubscribeScreen([this](const char* param_1, int param_2, const unsigned char* param_3) {
				return HandleAntiFlashScreen(param_1, param_2, param_3);
			});
		}

		void AntiFlash::ShutDown() {
			running = false;

			Events::EventBus::UnsubscribeScreen(screenToken);
		}

		bool AntiFlash::HandleAntiFlashScreen(const char* param_1, int param_2, const unsigned char* param_3) {
			return false;
		}
	}
}
