#pragma once
#include <string>

#include "Gui.h"

namespace Gui {
	namespace Menu {
		class Misc : public Menu {
			virtual std::string GetName() const override;

			virtual void Draw() override;
		};
	}
}
