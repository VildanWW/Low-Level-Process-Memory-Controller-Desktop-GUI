#include "pch.h"

#include <string>

#include "IconsFontAwesome5.h"
#include "Visuals.h"
#include "Theme.h"

namespace Gui {
	namespace Menu {
		Visuals::Visuals() {
			subTabs = {"Esp"};
		}

		std::string Visuals ::GetName() const {
			return "Visuals";
		}

		const char* Visuals::GetItem() const {
			return ICON_FA_EYE;
		}

		void Visuals::Draw() {
			ImVec2 screenSize = ImGui::GetIO().DisplaySize;

			ImGui::PushStyleColor(ImGuiCol_ChildBg, Palette::ChildBg);
			ImGui::BeginChild("Visuals", ImVec2(screenSize.x * 0.08f, 0), true);

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