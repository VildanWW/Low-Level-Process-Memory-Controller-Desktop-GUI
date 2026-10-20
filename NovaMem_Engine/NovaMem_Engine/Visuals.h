#pragma once
#include "Gui.h"
#include <string>

namespace Gui {
	namespace Menu {
		class Visuals : public Menu {
			virtual std::string GetName() const override;

			virtual void Draw() override;
		};
	}
}


