#pragma once

#include <string>
#include <nlohmann/json.hpp>

namespace Core {

	void RequestShutdown();

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

			bool menuOpen = true;
			std::string pathJson = "NovaMem_Engine_config.json";
		};

		inline ConfigSettings configSettings;

		NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Aim, running);
		NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Ragebot, running);
		NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(NoRecoil, running);
		NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Bhop, running);
		NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Wh, running);

		NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(CombatStruct, aim, rageBot, noRecoil);
		NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(MovementStruct, bhop);
		NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(VisualsStruct, wh);

		NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(ConfigSettings, combat, movement, visuals);
	}
}