#pragma once

#include <array>
#include <cstdint>

#include "ConfigTypes.h"

namespace Core {
	namespace Settings {
		struct Combat {
			uint8_t mode = 0;

			struct WeaponProfile {
				struct Legit {
					struct Aimbot {
						bool running = false;
						float fov = -1.0f;
						float smooth = -1.0f;

						struct SilentAim {
							bool running = false;
						} silentAim;
					} aimbot;

					struct TriggerBot {
						bool running = false;
						int delay = -1;
						int hitChance = -1;
						std::array<bool, 20> hitBoxes = { false }; // 20 this is base for selection on body
					} triggerBot;

					struct RCS {
						bool running = false;
					} rcs;
				} legit;

				struct Rage {
					struct Ragebot {
						bool running = false;
						bool autoFire = false;
						bool autoWall = false;
						int minDamage = -1;
						int hitChance = -1;
						bool noRecoil = false;
						bool noSpread = false;
						bool quickStop = false;

						struct MultiPoint {
							bool running = false;
							float headScale = -1.0f;
							float bodyScale = -1.0f;
						} multiPoint;
					} ragebot;
				} rage;
			};

			std::array<WeaponProfile, static_cast<uint8_t>(WeaponCategory::Count)> weapons{};

			struct WeaponMisc {
				struct AutoPistol {
					bool running = false;
				} autoPistol;

				struct FastZoom {
					bool running = false;
				} fastZoom;
			} weaponMisc;

			struct AntiAim {
				bool running = false;
				float pitch = -1.0f;
				float yaw = -1.0f;

				struct FakeLag {
					bool running = false;
				} fakeLag;
			} antiAim;
		};
	}
}