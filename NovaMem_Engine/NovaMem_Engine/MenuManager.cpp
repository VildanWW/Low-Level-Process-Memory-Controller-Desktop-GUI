#include "pch.h"
#include "MenuManager.h"
#include "ImGui.h"
#include "Tabs.h"
#include "Config.h"

namespace Gui {
	namespace Menu {
		void MenuManager::AddTab(std::unique_ptr<Menu> upTab) {
			tabs.push_back(std::move(upTab));
		}
		void MenuManager::DrawMainWindow() {

			ImVec2 screenSize = ImGui::GetIO().DisplaySize;

			ImGui::SetNextWindowSize(ImVec2(screenSize.x * 0.4f, screenSize.y * 0.5f), ImGuiCond_FirstUseEver);

			ImGuiIO& io = ImGui::GetIO();
			io.MouseDown[0] = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0;

			if (ImGui::Begin("NovaMem Engine", &Core::Settings::configSettings.menuOpen, ImGuiWindowFlags_NoCollapse)) {

				if (ImGui::IsWindowHovered(ImGuiHoveredFlags_ChildWindows) && io.MouseDown[0]) {
					if (!ImGui::IsAnyItemActive() && (io.MouseDelta.x != 0.0f || io.MouseDelta.y != 0.0f)) {
						ImVec2 pos = ImGui::GetWindowPos();
						ImGui::SetWindowPos(ImVec2(pos.x + io.MouseDelta.x, pos.y + io.MouseDelta.y));
					}
				}

				ImGui::TextDisabled("Tabs:");
				ImGui::SameLine();

				for (size_t i = 0; i < tabs.size(); i++) {
					if (ImGui::Button(tabs[i]->GetName().c_str())) {
						activeTabId = i;
					}
					if (i < tabs.size() - 1) ImGui::SameLine();
				}

				ImGui::Separator();

				ImGui::BeginChild("MainContent", ImVec2(0, 0), false);
				
				if (!tabs.empty() && activeTabId < tabs.size()) {
					tabs[activeTabId]->Draw();
				}
				
				ImGui::EndChild();

				ImGui::End();
			}
		}
	}
}