#include "pch.h"

#include "Widgets.h"
#include "imgui.h"
#include "Theme.h"

namespace Gui {
	bool FeatureToggle(const TabInfo& tabInfo) {
		if (!tabInfo.nameTab)
			return false;

		const ImGuiStyle& style = ImGui::GetStyle();
		const float fontSize = ImGui::GetFontSize();
		const float boxSize = fontSize * 1.15f;

		ImVec2 pos = ImGui::GetCursorScreenPos();
		float availWidth = ImGui::GetContentRegionAvail().x;
		float itemHeight = fontSize * 2.1f;

		ImGui::InvisibleButton(tabInfo.nameTab, ImVec2(availWidth, itemHeight));
		bool clicked = ImGui::IsItemClicked();

		if (clicked && tabInfo.stateTab) { 
			*tabInfo.stateTab = !(*tabInfo.stateTab);
		}

		ImDrawList* drawList = ImGui::GetWindowDrawList();

		float boxY = pos.y + (itemHeight - boxSize) * 0.5f;
		ImVec2 boxMin(pos.x, boxY);
		ImVec2 boxMax(pos.x + boxSize, boxY + boxSize);

		bool isChecked = tabInfo.stateTab && *tabInfo.stateTab;
		float rounding = boxSize * 0.25f;

		if (isChecked) {
			float glowPad = boxSize * 0.16f;
			drawList->AddRectFilled( ImVec2(boxMin.x - glowPad, boxMin.y - glowPad), ImVec2(boxMax.x + glowPad, boxMax.y + glowPad), ImGui::ColorConvertFloat4ToU32(Gui::Palette::AccentHovered), rounding + glowPad * 0.5f);

			drawList->AddRectFilled(boxMin, boxMax, ImGui::ColorConvertFloat4ToU32(Gui::Palette::Accent), rounding);

			ImVec2 checkPts[3] = { ImVec2(boxMin.x + boxSize * 0.27f, boxMin.y + boxSize * 0.52f), ImVec2(boxMin.x + boxSize * 0.44f, boxMin.y + boxSize * 0.69f), ImVec2(boxMin.x + boxSize * 0.74f, boxMin.y + boxSize * 0.34f)};
			drawList->AddPolyline(checkPts, IM_ARRAYSIZE(checkPts), ImGui::ColorConvertFloat4ToU32(Gui::Palette::CardBg), ImDrawFlags_None, boxSize * 0.13f);
		}
		else {
			ImVec4 borderCol = ImGui::IsItemHovered() ? Gui::Palette::BorderHovered : Gui::Palette::Border;

			drawList->AddRectFilled(boxMin, boxMax, ImGui::ColorConvertFloat4ToU32(Gui::Palette::Background), rounding);
			drawList->AddRect(boxMin, boxMax, ImGui::ColorConvertFloat4ToU32(borderCol), rounding);
		}

		float textX = boxMax.x + style.ItemInnerSpacing.x * 2.0f;
		drawList->AddText(ImVec2(textX, pos.y), ImGui::ColorConvertFloat4ToU32(Gui::Palette::TextMain), tabInfo.nameTab);

		if (tabInfo.description) {
			drawList->AddText(ImVec2(textX, pos.y + fontSize), ImGui::GetColorU32(ImGuiCol_TextDisabled), tabInfo.description);
		}

		return clicked;
	}

	void BeginCard(const CardInfo& info) {
		float cardRounding = ImGui::GetStyle().WindowRounding;
		float fontSize = ImGui::GetFontSize();

		ImGui::PushStyleColor(ImGuiCol_ChildBg, Gui::Palette::CardBg);
		ImGui::PushStyleColor(ImGuiCol_Border, Gui::Palette::Border);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, cardRounding * 0.65f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(fontSize * 0.9f, fontSize * 0.8f));
		
		ImGui::BeginChild(info.title, ImVec2(0.0f, 0.0f), ImGuiChildFlags_Borders | ImGuiChildFlags_AutoResizeY);
		
		if (info.title) {
			ImGui::TextColored(Gui::Palette::TextMain, "%s", info.title);
		}
		
		ImGui::Spacing();
		
		ImDrawList* drawList = ImGui::GetWindowDrawList();
		ImVec2 windowPos = ImGui::GetWindowPos();
		float windowWidth = ImGui::GetWindowWidth();
		float lineY = ImGui::GetCursorScreenPos().y;

		drawList->AddLine( ImVec2(windowPos.x, lineY), ImVec2(windowPos.x + windowWidth, lineY), ImGui::ColorConvertFloat4ToU32(Gui::Palette::Border));

		ImGui::Spacing();
	}
	void EndCard() {
		ImGui::EndChild();
		ImGui::PopStyleVar(2);
		ImGui::PopStyleColor(2);
	}
}