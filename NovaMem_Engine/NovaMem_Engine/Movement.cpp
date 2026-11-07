#include "pch.h"

#include <string>
#include <imgui.h>

#include "Movement.h"
#include "Config.h"
#include "Theme.h"

using namespace Core::Settings;

namespace Gui {
	namespace Menu {
		std::string Movement::GetName() const {
			return "Movement";
		}

		void Movement::Draw() {
			
			ImVec2 screenSize = ImGui::GetIO().DisplaySize;

			std::vector<std::string> subTabs{ "Bhop" };

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