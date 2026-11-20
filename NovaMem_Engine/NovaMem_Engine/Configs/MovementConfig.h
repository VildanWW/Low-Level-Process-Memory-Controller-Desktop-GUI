#pragma once

namespace Core {
	namespace Settings {
		struct Movement {
			struct Jumping {
				struct BunnyHop {
					bool running = true;
				} bunnyHop;

				struct AutoStrafe {
					bool running = false;
				} autoStrafe;

				struct GroundStrafe {
					bool running = false;
				} groundStrafe;

				struct AutoDuck {
					bool running = false;
				} autoDuck;
			} jumping;

			struct Exploits {
				struct JumpBug {
					bool running = false;
				} jumpBug;

				struct EdgeBug {
					bool running = false;
				} edgeBug;

				struct EdgeJump {
					bool running = false;
				} edgeJump;

				struct FastRun {
					bool running = false;
				} fastRun;
			} exploits;

			struct Control {
				struct FastStop {
					bool running = false;
				} fastStop;

				struct AutoPeek {
					bool running = false;
				} autoPeek;

				struct SlowWalk {
					bool running = false;
				} slowWalk;

				struct SpeedHack {
					bool running = false;
				} speedHack;
			} control;
		};
	}
}