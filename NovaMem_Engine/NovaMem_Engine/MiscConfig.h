#pragma once

namespace Core {
	namespace Settings {
		struct Misc {
			struct Hud {
				struct Radar {
					bool running = false;
				} radar;

				struct Logs {
					bool running = false;
				} logs;

				struct PreserveKillFeed {
					bool running = false;
				} preserveKillFeed;
			} hud;

			struct Indicators {
				struct CrossHair {
					bool running = false;
				} crossHair;
			} indicators;

			struct Windows {
				struct BombTimer {
					bool running = false;
				} bombTimer;

				struct SpectatorsList {
					bool running = false;
				} spectatorList;

				struct TeamYourDamage {
					bool running = false;
				} teamYourDamage;
			} windows;

			struct HitEffects {
				struct HitSound {
					bool running = false;
				} hitSound;

				struct HitMarker {
					bool running = false;
				} hitMarker;
			} hitEffects;

			struct Grenades {
				struct Prediction {
					bool running = false;
				} prediction;

				struct ProximityWarning {
					bool running = false;
				} proximityWarning;
			} grenades;

			struct AutoBuy {
				struct Primary {
					bool running = false;
				} primary;

				struct Secondary {
					bool running = false;
				} secondary;

				struct Armor {
					bool running = false;
				} armor;

				struct Utility {
					bool running = false;
				} utility;

				struct Equipment {
					bool running = false;
				} equipment;
			} autoBuy;

			struct Menu {
				struct MenuKey {
					bool running = false;
				} menuKey;

				struct AccentColor {
					bool running = false;
				} accentColor;

				struct WaterMark {
					bool running = false;
				} waterMark;

				struct KeyBindList {
					bool running = false;
				} keyBindList;

				struct ConfigPushPop {
					bool running = false;
				} configPushPop;
			} menu;
		};
	}
}