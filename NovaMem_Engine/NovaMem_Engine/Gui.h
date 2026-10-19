#pragma once
#include <string>

namespace Gui {
	namespace Menu {
		class Menu {
		public:
			Menu() = default;
			virtual ~Menu() = default;

			virtual std::string GetName() const = 0;
			virtual void Draw() = 0;

			Menu(const Menu&) = delete;
			Menu& operator=(const Menu&) = delete;
			Menu(Menu&&) = delete;
			Menu& operator=(Menu&&) = delete;
		};
	}
}


