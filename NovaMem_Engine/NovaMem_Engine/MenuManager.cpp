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

        void MenuManager::UploadTabs() {
            menuManager.AddTab(std::make_unique<Combat>());
            menuManager.AddTab(std::make_unique<Movement>());
            menuManager.AddTab(std::make_unique<Visuals>());
            menuManager.AddTab(std::make_unique<Misc>());
        }

        void MenuManager::InitStyle() {
            ImGuiStyle& style = ImGui::GetStyle();

            float fontSize = ImGui::GetFontSize();

            style.WindowRounding = fontSize * 0.4f;
            style.ChildRounding = fontSize * 0.25f;
            style.FrameRounding = fontSize * 0.25;
            style.ItemSpacing = ImVec2(fontSize * 0.5f, fontSize * 0.40f);

            // 1. Center (Window background): #3E2352
            style.Colors[ImGuiCol_WindowBg] = ImVec4(0.243f, 0.137f, 0.321f, 1.00f);

            // 2. Up/down (Lines and headers): #B18CCD
            style.Colors[ImGuiCol_Separator] = ImVec4(0.694f, 0.549f, 0.803f, 1.00f);
            style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.694f, 0.549f, 0.803f, 1.00f);
            style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.694f, 0.549f, 0.803f, 1.00f);
            style.Colors[ImGuiCol_Border] = ImVec4(0.694f, 0.549f, 0.803f, 1.00f);

            // 3. Left (sets the default color for all child windows): #7525B0
            style.Colors[ImGuiCol_ChildBg] = ImVec4(0.458f, 0.145f, 0.690f, 1.00f);

            // Color of text (white)
            style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
            style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.8f, 0.8f, 0.8f, 0.6f);

            // Colors for 3 states headers
            style.Colors[ImGuiCol_Header] = ImVec4(0.694f, 0.549f, 0.803f, 1.00f);
            style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.694f, 0.549f, 0.803f, 0.5f);
            style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.694f, 0.549f, 0.803f, 1.00f);

            // Colors for 3 states button
            style.Colors[ImGuiCol_Button] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
            style.Colors[ImGuiCol_ButtonHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.1f);
            style.Colors[ImGuiCol_ButtonActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.2f);
        }

        void MenuManager::DrawHeader(ImDrawList* drawList, ImVec2 windowPos, ImVec2 windowSize, float height) {}
        
        void MenuManager::DrawFooter(ImDrawList* drawList, ImVec2 windowPos, ImVec2 windowSize, float height) {}

        void MenuManager::DrawMainWindow() {
            ImVec2 screenSize = ImGui::GetIO().DisplaySize;
            ImGui::SetNextWindowSize(ImVec2(screenSize.x * 0.4f, screenSize.y * 0.5f), ImGuiCond_FirstUseEver);

            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f)); // first aArgument needed to spaces set new values, second argument - spaces set 0 for 4 sides
            ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse;

            bool isOpen = ImGui::Begin("NovaMem Engine", &Core::Settings::configSettings.menuOpen, windowFlags);
            
            ImGui::PopStyleVar(); // this method very needed because sets standart values in menu

            if (!isOpen) { 
                ImGui::End(); 
                return; 
            }

            ImGuiIO& io = ImGui::GetIO();
            io.MouseDown[0] = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0;

            float titleBarHeight = screenSize.y * 0.050f;
            float footerHeight = screenSize.y * 0.025f;

            ImVec2 windowPos = ImGui::GetWindowPos();
            ImVec2 windowSize = ImGui::GetWindowSize();

            if (ImGui::IsMouseHoveringRect(windowPos, ImVec2(windowPos.x + windowSize.x, windowPos.y + titleBarHeight)) && io.MouseDown[0]) {
                if (!ImGui::IsAnyItemActive() && (io.MouseDelta.x != 0.0f || io.MouseDelta.y != 0.0f)) {
                    ImGui::SetWindowPos(ImVec2(windowPos.x + io.MouseDelta.x, windowPos.y + io.MouseDelta.y));
                }
            }

            ImDrawList* drawList = ImGui::GetWindowDrawList(); 

            DrawHeader(drawList, windowPos, windowSize, titleBarHeight);

            ImGui::SetCursorPosY(titleBarHeight);

            ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.0f, 0.0f, 0.0f, 0.00f));

            float contentHeight = windowSize.y - titleBarHeight - footerHeight;

            ImGui::BeginChild("MainContent", ImVec2(windowSize.x, contentHeight), false, ImGuiWindowFlags_NoBackground);

            if (!tabs.empty() && activeTabId < tabs.size()) {
                tabs[activeTabId]->Draw();
            }

            ImGui::EndChild();
            ImGui::PopStyleColor();

            DrawFooter(drawList, windowPos, windowSize, footerHeight);

            ImGui::End();
        }
	}
}


/*void MenuManager::DrawMainWindow() {

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
        ImGui::Separator();

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

        ImGui::Separator();

        ImGui::End();
    }
}*/