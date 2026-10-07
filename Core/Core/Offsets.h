#pragma once
#include "Hotkeys.h"

namespace Core {
	namespace Offsets {
		constexpr uintptr_t jumpAddress = 0x1E94C0;

		inline int* airAddress = 0;
		inline uintptr_t clientBase = 0;
		inline uintptr_t hwBase = 0;
		inline uintptr_t opengl32 = 0;
		inline uintptr_t absoluteMoveAddress = 0;
		inline uintptr_t absoluteScreenAddress = 0;
		inline uintptr_t absoluteGlBeginAddress = 0;
		inline uintptr_t absoluteGlVertex3F = 0;

		constexpr int bhopKey = static_cast<int>(Hotkeys::Bhop);
		constexpr unsigned int jumpFlag = static_cast<unsigned int>(GoldSrcButtons::IN_JUMP);
	};

	namespace GameFunctions {
		constexpr uintptr_t moveAddress = 0x9B880;
		constexpr uintptr_t screenFadeAddress = 0xAFCA0;
		constexpr uintptr_t glBeginAddress = 0x274B0;
		constexpr uintptr_t glVertex3F = 0x294F0;
	};

	//constexpr uintptr_t rotationAddress = 0x2DC2B20;
	//constexpr int duckKey = static_cast<int>(Hotkeys::AutoDuck);
	//constexpr uintptr_t rotationAddress = 0x31D20;
}

