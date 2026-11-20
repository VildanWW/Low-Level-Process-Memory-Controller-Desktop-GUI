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
				} box;

				struct Name {
					bool running = false;
				} name;

				struct HealthBar {
					bool running = false;
				} healthBar;

				struct ArmorBar {
					bool running = false;
				} armorBar;

				struct Weapon {
					bool running = false;
					bool icon = false;
				} weapon;

				struct Skeleton {
					bool running = false;
				} skeleton;

				struct Snaplines {
					bool running = false;
				} snaplines;

				struct OffscreenArrows {
					bool running = false;
				} offScreenArrows;

				struct SoundEsp {
					bool running = false;
				} soundEsp;

				struct Flags {
					bool running = false;
					bool reloading = true;
					bool flashed = true;
					bool defusing = true;
				} flags;

				struct EspPreview {
					bool running = false;
				} espPreview;
			} players;

			struct World {
				struct DroppedWeapons {
					bool running = true;
				} droppedWeapons;

				struct PlantedC4 {
					bool running = true;
				} plantedC4;

				struct Projectiles {
					bool running = true;
				} projectiles;

				struct BulletTracers {
					bool running = false;
				} bulletTracers;

				struct BulletImpacts {
					bool running = false;
				} bulletImpacts;

				struct NoFlash {
					bool running = true;
				} noFlash;

				struct NoSmoke {
					bool running = true;
				} noSmoke;

				struct NoVisualRecoil {
					bool running = false;
				} noVisualRecoil;
			} world;

			struct Models {
				struct EnemyChams {
					bool running = false;
				} enemyChams;

				struct Material {
					bool running = false;
				} material;

				struct BacktrackChams {
					bool running = false;
				} backtrackChams;

				struct LocalHands {
					bool running = false;
				} localHands;	

				struct LocalWeapon {
					bool running = false;
				} localWeapon;

				struct GlowOutline {
					bool running = false;
				} glowOutline;
			} models;

			struct View {
				float fovChanger = -1.0f;

				struct ViewModel {
					bool running = false;
				} viewModel;

				struct ThirdPerson {
					bool running = false;
				} thirdPerson;

				struct SniperCrosshair {
					bool running = false;
				} sniperCrosshair;

				struct RecoilCrosshair {
					bool running = false;
				} recoilCrosshair;

				struct DisableScopeOverlay {
					bool running = false;
				} disableScopeOverlay;
			} view;
		};
	}
}