#pragma once

namespace Gui {
	namespace Menu {
		void Render();
	}

	namespace Combat {
		// Aim
		inline bool aimbot = false;
		inline float aimFov = 15.0f;

		// Ragebot
		inline bool ragebot = false;

		// NoRecoil
		inline bool noRecoil = false;

		// Draw
		void DrawSettings();
	}

	namespace Movement {
		// BunnyHop
		inline bool bunnyhHop = false;

		void DrawSettings();
	}

	namespace Visuals {
		// Esp
		inline bool esp = false;

		void DrawSettings();
	}

	namespace Misc {
		

		void DrawSettings();
	}
}


