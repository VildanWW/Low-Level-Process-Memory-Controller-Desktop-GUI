#pragma once
#include "Gui.h"
#include <string>

namespace Gui {
	namespace Menu {
		class Movement : public Menu {
			virtual std::string GetName() const override;
			virtual void Draw() override;
		};
	}
}

