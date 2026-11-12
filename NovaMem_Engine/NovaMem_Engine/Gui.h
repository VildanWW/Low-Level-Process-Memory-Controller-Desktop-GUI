#pragma once
#include <string>
#include <vector>

namespace Gui {
	namespace Menu {
		class Menu {
		protected:
			int currentTab = 0;

			std::vector<std::string> subTabs;
		public:
			Menu() = default;
			virtual ~Menu() = default;

			virtual void Draw() = 0;
			virtual std::string GetName() const = 0;
			virtual const char* GetItem() const = 0;

			Menu(const Menu&) = delete;
			Menu& operator=(const Menu&) = delete;
			Menu(Menu&&) = delete;
			Menu& operator=(Menu&&) = delete;
		};
	}
}
