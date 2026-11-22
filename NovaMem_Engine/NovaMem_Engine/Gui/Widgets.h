#pragma once

namespace Gui {
	struct CardInfo {
		const char* title = nullptr;
		const char* tag = nullptr;
		float height = 0.0f;
	};

	struct TabInfo {
		const char* nameTab = nullptr;
		const char* description = nullptr;
		bool* stateTab = nullptr;
	};

	bool FeatureToggle(const TabInfo& tabInfo);

	void BeginCard(const CardInfo& info);
	void EndCard();
}