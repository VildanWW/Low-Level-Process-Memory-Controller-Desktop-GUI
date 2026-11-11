#include "pch.h"

#include <string>

#include "Misc.h"
#include "IconsFontAwesome5.h"

namespace Gui {
	namespace Menu {
		std::string Misc::GetName() const {
			return "Misc";
		}

		const char* Misc::GetItem() const {
			return ICON_FA_BOX_OPEN;
		}

		void Misc::Draw() {}
	}
}