#include "pch.h"

#include <string>
#include <imgui.h>
#include <vector>

#include "IconsFontAwesome5.h"
#include "Movement.h"
#include "Theme.h"

namespace Gui {
	namespace Menu {
		Movement::Movement() {
			subTabs = {"Bhop"};
		}

		std::string Movement::GetName() const {
			return "Movement";
		}

		const char* Movement::GetItem() const {
			return ICON_FA_BOLT;
		}

		void Movement::Draw() {
			
			ImVec2 screenSize = ImGui::GetIO().DisplaySize;

			ImGui::PushStyleColor(ImGuiCol_ChildBg, Palette::ChildBg);
			ImGui::BeginChild("Movement", ImVec2(screenSize.x * 0.08f, 0), true);
			
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