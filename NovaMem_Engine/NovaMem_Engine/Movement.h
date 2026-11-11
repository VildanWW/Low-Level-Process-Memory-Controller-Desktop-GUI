#pragma once
#include <string>

#include "Gui.h"

namespace Gui {
	namespace Menu {
		class Movement : public Menu {
		public:
			virtual std::string GetName() const override;
			virtual const char* GetItem() const override;
			virtual void Draw() override;
		};
	}
}

