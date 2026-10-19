#pragma once
#include "Gui.h"
#include <string>

namespace Gui {
	namespace Menu {
		class Combat : public Menu {
			std::string GetName() const override;

			void Draw() override;
		};
	}
}
