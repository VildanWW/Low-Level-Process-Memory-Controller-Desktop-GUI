#pragma once
#include <string>

#include "Gui.h"

namespace Gui {
	namespace Menu {
		class Misc : public Menu {
		public:
			Misc();

			virtual std::string GetName() const override;
			virtual const char* GetItem() const override;

			virtual void Draw() override;
		};
	}
}
