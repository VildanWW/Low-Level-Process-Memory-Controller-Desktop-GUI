#include "pch.h"

#include <string>

#include "IconsFontAwesome5.h"
#include "Visuals.h"

namespace Gui {
	namespace Menu {
		std::string Visuals ::GetName() const {
			return "Visuals";
		}

		const char* Visuals::GetItem() const {
			return ICON_FA_EYE;
		}

		void Visuals::Draw() {}
	}
}