#include "pch.h"

#include <string>
#include <imgui.h>
#include <vector>

#include "IconsFontAwesome5.h"
#include "Movement.h"
#include "Theme.h"
#include "Config.h"
#include "Widgets.h"

namespace Gui {
	namespace Menu {
		Movement::Movement() { 
			subTabs = {"Jumping", "Exploits", "Control"};
		}

		std::string Movement::GetName() const {
			return "Movement";
		}

		const char* Movement::GetItem() const {
			return ICON_FA_BOLT;
		}

		void Movement::Draw() {
			auto& cfg = Core::Settings::configSettings;

			ImGui::Columns(3, "MovementGrid", false);

			BeginCard({ "Jumping" });
			FeatureToggle({ "BunnyHop", "Auto-jump on landing", &cfg.movement.jumping.bunnyHop.running});
			FeatureToggle({ "AutoStrafe", "Strafe to gain air speed", &cfg.movement.jumping.autoStrafe.running });
			FeatureToggle({ "GroundStrafe", "Strafe assist on ground", &cfg.movement.jumping.groundStrafe.running });
			FeatureToggle({ "AutoDuck","Crouch mid-air for height", &cfg.movement.jumping.autoDuck.running });
			EndCard();

			ImGui::NextColumn();

			BeginCard({ "Exploits" });
			FeatureToggle({ "JumpBug", "Negate fall damage on land", &cfg.movement.exploits.jumpBug.running });
			FeatureToggle({ "EdgeBug","Survive lethal drops on edge", &cfg.movement.exploits.edgeBug.running });
			FeatureToggle({ "EdgeJump", "Auto-jump at ledge edge", &cfg.movement.exploits.edgeJump.running });
			FeatureToggle({ "FastRun", "Speed boost via strafing", &cfg.movement.exploits.fastRun.running });
			EndCard();

			ImGui::NextColumn();

			BeginCard({"Control" });
			FeatureToggle({ "FastStop", "Instant velocity halt", &cfg.movement.control.fastStop.running });
			FeatureToggle({ "AutoPeek", "Return to origin after shot", &cfg.movement.control.autoPeek.running });
			FeatureToggle({ "SlowWalk", "Reduced movement speed", &cfg.movement.control.slowWalk.running });
			FeatureToggle({ "SpeedHack", "Engine timescale multiplier", &cfg.movement.control.speedHack.running });
			EndCard();

			ImGui::Columns(1);
		}
	}
}