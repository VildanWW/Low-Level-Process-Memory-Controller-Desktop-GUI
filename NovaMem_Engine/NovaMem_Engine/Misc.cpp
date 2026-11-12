#include "pch.h"

#include <string>

#include "IconsFontAwesome5.h"
#include "Misc.h"
#include "Config.h"
#include "Theme.h"

namespace Gui {
	namespace Menu {
		Misc::Misc() {
			subTabs = {};
		}

		std::string Misc::GetName() const {
			return "Misc";
		}

		const char* Misc::GetItem() const {
			return ICON_FA_BOX_OPEN;
		}

		void Misc::Draw() {
			ImVec2 screenSize = ImGui::GetIO().DisplaySize;

			ImGui::PushStyleColor(ImGuiCol_ChildBg, Palette::ChildBg);
			ImGui::BeginChild("Misc", ImVec2(screenSize.x * 0.08f, 0), true);

			for (int i = 0; i < subTabs.size(); i++) {
				bool isSelected = (currentTab == i);
				if (ImGui::Selectable(subTabs[i].c_str(), isSelected)) {
					currentTab = i;
				}
			}
			ImGui::EndChild();
			ImGui::PopStyleColor();
		}
	}
}