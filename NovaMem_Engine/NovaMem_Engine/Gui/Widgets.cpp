#include "pch.h"

#include "Widgets.h"
#include "imgui.h"
#include "Theme.h"

namespace Gui {
	bool FeatureToggle(const TabInfo& tabInfo) {

		return false;
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
		ImGui::Separator();
		ImGui::Spacing();
	}
	void EndCard() {
		ImGui::EndChild();
		ImGui::PopStyleVar(2);
		ImGui::PopStyleColor(2);
	}
}