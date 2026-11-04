#include "pch.h"

#include <string>
#include <imgui.h>

#include "Movement.h"
#include "Config.h"

using namespace Core::Settings;

namespace Gui {
	namespace Menu {
		std::string Movement::GetName() const {
			return "Movement";
		}

		void Movement::Draw() {
			ImGui::Checkbox("BunnyHop", &configSettings.movement.bhop.running);
		}
	}
}