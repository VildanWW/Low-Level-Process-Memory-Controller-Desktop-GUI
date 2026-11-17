#pragma once

#include "ConfigTypes.h"

namespace Core {
	namespace Settings {
		struct Visuals {
			struct Players {
				bool running = false;
				
				struct Box {
					bool running = false;
					BoxType type = BoxType::Box2D;
				};

				struct Name {
					bool running = false;
				};

				struct HealthBar {
					bool running = false;
				};

				struct ArmorBar {
					bool running = false;
				};

				struct Weapon {
					bool running = false;
					bool icon = false;
				};

				struct Skeleton {
					bool running = false;
				};

				struct Snaplines {
					bool running = false;
				};

				struct OffscreenArrows {
					bool running = false;
				};

				struct SoundEsp {
					bool running = false;
				};

				struct Flags {
					bool running = false;
					bool reloading = true;
					bool flashed = true;
					bool defusing = true;
				};
			} players;

			struct World {
				struct NoFlash {
					bool running = true;
				} noFlash;

				struct NoSmoke {
					bool running = true;
				} noSmoke;
			} world;
		};
	}
}