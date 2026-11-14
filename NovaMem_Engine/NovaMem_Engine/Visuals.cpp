#include "pch.h"

#include <string>
#include <vector>

#include "IconsFontAwesome5.h"
#include "Visuals.h"
#include "Theme.h"
#include "imgui.h"

namespace Gui {
	namespace Menu {
		Visuals::Visuals() {}

		std::string Visuals ::GetName() const {
			return "Visuals";
		}

		const char* Visuals::GetItem() const {
			return ICON_FA_EYE;
		}

		void Visuals::Draw() {
			
		}
	}
}