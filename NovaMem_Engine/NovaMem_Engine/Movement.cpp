#include "pch.h"

#include <string>
#include <imgui.h>
#include <vector>

#include "IconsFontAwesome5.h"
#include "Movement.h"
#include "Theme.h"

namespace Gui {
	namespace Menu {
		Movement::Movement() {}

		std::string Movement::GetName() const {
			return "Movement";
		}

		const char* Movement::GetItem() const {
			return ICON_FA_BOLT;
		}

		void Movement::Draw() {}
	}
}