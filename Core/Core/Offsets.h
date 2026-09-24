#pragma once
#include "Hotkeys.h"

struct Offsets {
	static constexpr uintptr_t jumpAddress = 0x1E94C0;

	static inline int* airAddress = 0;
	static inline uintptr_t clientBase = 0;
	static inline uintptr_t hwBase = 0;
	static inline uintptr_t absoluteMoveAddress = 0;
	static inline uintptr_t absoluteScreenAddress = 0;

	static constexpr int bhopKey = static_cast<int>(Hotkeys::Bhop);
	static constexpr unsigned int jumpFlag = static_cast<unsigned int>(GoldSrcButtons::IN_JUMP);
};

struct GameFunctions {
	static constexpr uintptr_t moveAddress = 0x9B880;
	static constexpr uintptr_t screenFadeAddress = 0xAFCA0;
};

//static constexpr uintptr_t rotationAddress = 0x2DC2B20;
//static constexpr int duckKey = static_cast<int>(Hotkeys::AutoDuck);
//static constexpr uintptr_t rotationAddress = 0x31D20;
