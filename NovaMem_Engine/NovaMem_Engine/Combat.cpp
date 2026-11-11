#include "pch.h"

#include <string>
#include <vector>

#include "IconsFontAwesome5.h"
#include "Combat.h"
#include "imgui.h"
#include "Theme.h"

namespace Gui {
	namespace Menu {
		std::string Combat::GetName() const {
			return "Combat";
		}

        const char* Combat::GetItem() const {
            return ICON_FA_CROSSHAIRS;
        }

        void Combat::Draw() {
            ImVec2 screenSize = ImGui::GetIO().DisplaySize;
            std::vector<std::string> subTabs{ "Aimbot", "Ragebot", "NoRecoil" };

            ImGui::PushStyleColor(ImGuiCol_ChildBg, Palette::ChildBg);

            ImGui::BeginChild("Combat_Sidebar", ImVec2(screenSize.x * 0.08f, 0), true);

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
