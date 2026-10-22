#include "pch.h"
#include "Combat.h"
#include <string>
#include "imgui.h"
#include <vector>

namespace Gui {
	namespace Menu {
		std::string Combat::GetName() const {
			return "Combat";
		}

		void Combat::Draw() {
			static int currentTab = 0;
			ImVec2 screenSize = ImGui::GetIO().DisplaySize;

			std::vector<std::string> subTabs{ "Aimbot", "Ragebot", "NoRecoil" };

			ImGui::BeginChild("Combat", ImVec2(screenSize.x * 0.08f, 0), true);

			for (int i = 0; i < subTabs.size(); i++) {
				bool isSelected = (currentTab == i);
				if (ImGui::Selectable(subTabs[i].c_str(), isSelected)) {
					currentTab = i;
				}
			}

			ImGui::EndChild();
		}
	}
}
