#include "pch.h"

#include <string>
#include <vector>

#include "Combat.h"
#include "imgui.h"
#include "Theme.h"

namespace Gui {
	namespace Menu {
		std::string Combat::GetName() const {
			return "Combat";
		}

        void Combat::Draw() {
            ImVec2 screenSize = ImGui::GetIO().DisplaySize;
            std::vector<std::string> subTabs{ "Aimbot", "Ragebot", "NoRecoil" };

            ImGui::PushStyleColor(ImGuiCol_ChildBg, Palette::ChildBg);

            ImGui::BeginChild("Combat_Sidebar", ImVec2(120.0f, 0), true);

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
