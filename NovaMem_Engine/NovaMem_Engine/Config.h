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
		struct AntiFlash {
			bool running = false;
		};
		struct AntiSmoke {
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
			AntiFlash antiFlash;
			AntiSmoke antiSmoke;
		};

		struct ConfigSettings {
			CombatStruct combat;
			MovementStruct movement;
			VisualsStruct visuals;

			bool menuOpen = true;
		};

		inline ConfigSettings configSettings;
		inline std::string pathJson = ""; // had to be rescheduled pathJson from ConfigSettings to namespace Settings because json clear pathJson

		NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Aim, running);
		NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Ragebot, running);
		NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(NoRecoil, running);
		NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Bhop, running);
		NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Wh, running);
		NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(AntiFlash, running);
		NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(AntiSmoke, running);

		NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(CombatStruct, aim, rageBot, noRecoil);
		NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(MovementStruct, bhop);
		NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(VisualsStruct, wh, antiFlash, antiSmoke);

		NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(ConfigSettings, combat, movement, visuals);
	}
}