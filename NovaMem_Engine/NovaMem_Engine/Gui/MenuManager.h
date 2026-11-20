#pragma once
#include <vector>
#include <memory>

#include "ImGui.h"

namespace Gui {
	namespace Menu {
		class Menu;
	}
}

namespace Gui {
	namespace Menu {
		class MenuManager {
		private:
			std::vector<std::unique_ptr<Menu>> tabs;

			size_t activeTabId = 0;

			void DrawHeader(ImDrawList* drawList, ImVec2 windowPos, ImVec2 windowSize, float height);
			void DrawFooter(ImDrawList* drawList, ImVec2 windowPos, ImVec2 windowSize, float height);
		public:
			MenuManager();
			~MenuManager();

			void AddTab(std::unique_ptr<Menu> upTab);
			void DrawMainWindow();
			void UploadTabs();
			void InitStyle();

			MenuManager(const MenuManager&) = delete;
			MenuManager& operator=(const MenuManager&) = delete;
			MenuManager(MenuManager&&) = delete;
			MenuManager& operator=(MenuManager&&) = delete;
		};

		inline MenuManager menuManager;
	}
}


