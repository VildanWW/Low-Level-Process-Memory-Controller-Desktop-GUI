#pragma once
#include <vector>
#include <memory>
#include "MenuManager.h"

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
		public:
			MenuManager() = default;
			void AddTab(std::unique_ptr<Menu> upTab);
			void DrawMainWindow();

			MenuManager(const MenuManager&) = delete;
			MenuManager& operator=(const MenuManager&) = delete;
			MenuManager(MenuManager&&) = delete;
			MenuManager& operator=(MenuManager&&) = delete;
		};

		inline MenuManager menuManager;
	}
}

