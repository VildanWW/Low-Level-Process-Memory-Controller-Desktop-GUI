#pragma once
#include <cstdint>

struct Offsets {
	static constexpr uintptr_t jumpAddress = 0x1E94C0;

	static inline uintptr_t rotation = 0;

	static inline uintptr_t clientBase = 0;
	static inline uintptr_t hwBase = 0;
};

struct GameFunctions {
	static constexpr uintptr_t moveAddress = 0x9B880;
	static constexpr uintptr_t rotationAddress = 0x31D20;
};
