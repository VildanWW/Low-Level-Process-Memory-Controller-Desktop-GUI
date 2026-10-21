#pragma once

namespace Core {
	namespace Settings {
		// Combat
		struct Aim {
			bool running = false;
		};
		struct Ragebot {
			bool running = false;
		};
		struct NoRecoil {
			bool running = false;
		};
		// Movement
		struct Bhop {
			bool running = false;
		};
		// Visuals 
		struct Wh {
			bool running = false;
		};
		// Misc

		struct CombatStruct {
			Aim aim;
			Ragebot rageBot;
			NoRecoil noRecoil;
		};
		struct MovementStruct {
			Bhop bhop;
		};
		struct VisualsStruct {
			Wh wh;
		};

		struct ConfigSettings {
			CombatStruct combat;
			MovementStruct movement;
			VisualsStruct visuals;
		};

		inline ConfigSettings configSettings;
	}
}