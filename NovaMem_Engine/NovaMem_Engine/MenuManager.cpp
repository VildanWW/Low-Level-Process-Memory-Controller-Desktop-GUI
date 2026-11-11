#include "pch.h"

#include "MenuManager.h"
#include "ImGui.h"
#include "Tabs.h"
#include "Config.h"
#include "Theme.h"
#include "IconsFontAwesome5.h"

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
            style.Colors[ImGuiCol_WindowBg] = Palette::Background;

            // 2. Up/down (Lines and headers): #B18CCD
            style.Colors[ImGuiCol_Separator] = Palette::Accent;
            style.Colors[ImGuiCol_SeparatorHovered] = Palette::Accent;
            style.Colors[ImGuiCol_SeparatorActive] = Palette::Accent;
            style.Colors[ImGuiCol_Border] = Palette::Accent;

            // 3. Left (sets the default color for all child windows): #7525B0
            style.Colors[ImGuiCol_ChildBg] = Palette::ChildBg;

            // Color of text (white)
            style.Colors[ImGuiCol_Text] = Palette::TextMain;
            style.Colors[ImGuiCol_TextDisabled] = Palette::TextDisabled;

            // Colors for 3 states headers
            style.Colors[ImGuiCol_Header] = Palette::Accent;
            style.Colors[ImGuiCol_HeaderHovered] = Palette::AccentHovered;
            style.Colors[ImGuiCol_HeaderActive] = Palette::Accent;

            // Colors for 3 states button
            style.Colors[ImGuiCol_Button] = Palette::BtnTransperent;
            style.Colors[ImGuiCol_ButtonHovered] = Palette::BtnHovered;
            style.Colors[ImGuiCol_ButtonActive] = Palette::BtnActive;
        }

        void MenuManager::DrawHeader(ImDrawList* drawList, ImVec2 windowPos, ImVec2 windowSize, float height) {
            ImVec2 headerTopLeft = windowPos;
            ImVec2 headerBottomRight = ImVec2(windowPos.x + windowSize.x, windowPos.y + height);
            float rounding = ImGui::GetStyle().WindowRounding;
            drawList->AddRectFilled(headerTopLeft, headerBottomRight, ImGui::ColorConvertFloat4ToU32(Palette::Accent), rounding, ImDrawFlags_RoundCornersTop);
        
            float fontSize = ImGui::GetFontSize();
            float framePaddingY = ImGui::GetStyle().FramePadding.y;

            float textHeight = ImGui::GetTextLineHeight();
            float textCenterY = windowPos.y + (height - textHeight) * 0.5f;

            float buttonHeight = fontSize + framePaddingY * 2.0f;
            float buttonCenterY = windowPos.y + (height - buttonHeight) * 0.5f;
            ImGui::SetCursorScreenPos(ImVec2(windowPos.x + windowSize.x * 0.01f, textCenterY));

            ImGui::PushStyleColor(ImGuiCol_Text, Palette::Background);
            ImGui::Text("NovaMem Engine");
            ImGui::PopStyleColor();

            float logoWidth = ImGui::CalcTextSize("NovaMem Engine").x;
            float startPadding = windowSize.x * 0.01f;
            ImGui::SetCursorScreenPos(ImVec2(windowPos.x + startPadding + logoWidth + windowSize.x * 0.03f, buttonCenterY));

            for (int i = 0; i < tabs.size(); i++) {
                std::string nameTab = tabs[i]->GetName();
                const char* itemTab = tabs[i]->GetItem();
                float spacing = windowSize.x * 0.005f;

                ImVec2 nameSize = ImGui::CalcTextSize(nameTab.c_str());
                ImVec2 iconSize = ImGui::CalcTextSize(itemTab);
                ImVec2 totalSize(nameSize.x + spacing + iconSize.x, buttonHeight);

                ImVec2 cursorScreenPos = ImGui::GetCursorScreenPos();

                if (ImGui::InvisibleButton(nameTab.c_str(), totalSize)) {
                    activeTabId = i;
                }

                float textY = cursorScreenPos.y + (buttonHeight - nameSize.y) * 0.5f;

                ImU32 textColor = (activeTabId == i) ? ImGui::GetColorU32(Palette::Background) : ImGui::GetColorU32(Palette::TextMuted);

                drawList->AddText(ImVec2(cursorScreenPos.x, textY), textColor, nameTab.c_str());

                ImU32 iconColor = ImGui::GetColorU32(ImVec4(Palette::ItemTabs));
                drawList->AddText(ImVec2(cursorScreenPos.x + nameSize.x + spacing, textY), iconColor, itemTab);

                if (i < tabs.size() - 1) {
                    float nextX = ImGui::GetItemRectMax().x + windowSize.x * 0.015f;
                    ImGui::SetCursorScreenPos(ImVec2(nextX, buttonCenterY));
                }
            }

            ImVec2 xButtonSize = ImVec2(fontSize + ImGui::GetStyle().FramePadding.x * 2.0f, buttonHeight);
            ImGui::SetCursorScreenPos(ImVec2(windowPos.x + windowSize.x - xButtonSize.x - windowSize.x * 0.02f, buttonCenterY));
            
            ImGui::PushStyleColor(ImGuiCol_Text, Palette::Background);
            
            if (ImGui::Button(ICON_FA_TIMES, xButtonSize)) {
                Core::Settings::configSettings.menuOpen = false;
                Core::RequestShutdown();
            }

            ImGui::PopStyleColor();
        }

        void MenuManager::DrawFooter(ImDrawList* drawList, ImVec2 windowPos, ImVec2 windowSize, float height) {
            ImVec2 footerTopLeft = ImVec2(windowPos.x, windowPos.y + windowSize.y - height);
            ImVec2 footerBottomRight = ImVec2(windowPos.x + windowSize.x, windowPos.y + windowSize.y);
            float rounding = ImGui::GetStyle().WindowRounding;
            drawList->AddRectFilled(footerTopLeft, footerBottomRight, ImGui::ColorConvertFloat4ToU32(Palette::Accent), rounding, ImDrawFlags_RoundCornersBottom);

            float buttonHeight = ImGui::GetFontSize() + ImGui::GetStyle().FramePadding.y * 2.0f;
            float centerY = footerTopLeft.y + (height - buttonHeight) * 0.5f;

            ImGui::SetCursorScreenPos(ImVec2(windowPos.x + windowSize.x * 0.02f, centerY));

            ImGui::PushStyleColor(ImGuiCol_Button, Palette::ChildBg);
            if (ImGui::Button(ICON_FA_COG)) {
                // Logic settings
            }

            ImGui::SetCursorScreenPos(ImVec2(ImGui::GetItemRectMax().x + windowSize.x * 0.01f, centerY));
            if (ImGui::Button(ICON_FA_SEARCH)) {
                // logic search
            }

            ImGui::PopStyleColor();
        }
        
        void MenuManager::DrawMainWindow() {
            ImVec2 screenSize = ImGui::GetIO().DisplaySize;
            ImGui::SetNextWindowSize(ImVec2(screenSize.x * 0.6f, screenSize.y * 0.6f), ImGuiCond_FirstUseEver);

            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f)); // first aArgument needed to spaces set new values, second argument - spaces set 0 for 4 sides
            ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;

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

            float pixelY = windowSize.y * (1.0f / windowSize.y);

            ImGui::SetCursorPosY(titleBarHeight- pixelY);

            ImGui::PushStyleColor(ImGuiCol_ChildBg, Palette::BtnTransperent);

            float contentHeight = windowSize.y - titleBarHeight - footerHeight;

            ImGui::BeginChild("MainContent", ImVec2(windowSize.x, contentHeight + (pixelY * 2.0f)), false, ImGuiWindowFlags_NoBackground);

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