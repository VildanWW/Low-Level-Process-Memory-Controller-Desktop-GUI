#include "pch.h"

#include <string>
#include <vector>

#include "IconsFontAwesome5.h"
#include "Misc.h"
#include "Theme.h"
#include "imgui.h"

namespace Gui {
	namespace Menu {
		Misc::Misc() {}

		std::string Misc::GetName() const {
			return "Misc";
		}

		const char* Misc::GetItem() const {
			return ICON_FA_BOX_OPEN;
		}

		void Misc::Draw() {}
	}
}