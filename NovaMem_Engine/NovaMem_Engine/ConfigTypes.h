#pragma once

#include <cstdint>
#include <cstddef>

namespace Core {
	namespace Settings {
		enum class CombatMode : uint8_t {
			Legit = 0,
			Rage
		};

		enum class WeaponCategory : uint8_t {
			Pistol = 0,
			HeavyPistol,
			SMG,
			Rifle,
			Shotgun,
			Sniper,
			AutoSniper,
			Count
		};

		enum class BoxType : uint8_t {
			Box2D = 0,
			Corner
		};
	}
}