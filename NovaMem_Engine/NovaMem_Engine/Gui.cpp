#include "pch.h"
#include "Gui.h"
#include "imgui.h"

namespace Gui {
	namespace Menu {
		void Render() {
			ImGui::Begin("NovaMem Engine");

			Gui::Combat::DrawSettings();
			Gui::Movement::DrawSettings();
			Gui::Visuals::DrawSettings();
			Gui::Misc::DrawSettings();

			ImGui::End();
		}
	}

	namespace Combat {
		void DrawSettings() {

		}
	}

	namespace Movement {
		void DrawSettings() {

		}
	}

	namespace Visuals {
		void DrawSettings() {

		}
	}

	namespace Misc {
		void DrawSettings() {

		}
	}
}