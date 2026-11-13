#include "pch.h"
#include "AntiFlash.h"
#include "Config.h"
#include "EventBus.h"

namespace Core {
	namespace Functionals {
		void AntiFlash::Initialize() {
			screenToken = Events::EventBus::SubscribeScreen([this](const char* param_1, int param_2, const unsigned char* param_3) {
				return HandleAntiFlashScreen(param_1, param_2, param_3);
			});
		}

		void AntiFlash::ShutDown() {
			Events::EventBus::UnsubscribeScreen(screenToken);
		}

		bool AntiFlash::HandleAntiFlashScreen(const char* param_1, int param_2, const unsigned char* param_3) {
			if (Settings::configSettings.visuals.antiFlash.running) {
				return true;
			}
			return false;
		}
	}
}
