#include "pch.h"

#include <string>
#include <vector>

#include "IconsFontAwesome5.h"
#include "Combat.h"
#include "imgui.h"
#include "Theme.h"

namespace Gui {
	namespace Menu {
        Combat::Combat() {
            subTabs = {"Ragebot", "Legit", "Weapons"};
        }

        std::string Combat::GetName() const {
			return "Combat";
		}

        const char* Combat::GetItem() const {
            return ICON_FA_CROSSHAIRS;
        }

        void Combat::Draw() {
            
        }
	}
}
