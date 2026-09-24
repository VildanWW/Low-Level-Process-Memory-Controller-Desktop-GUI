#pragma once

typedef unsigned int(__fastcall* t_MoveHandler)(char param_1);
typedef unsigned int(__cdecl* t_ScreenFadeMsg)(const char* param_1, int param_2, const unsigned char* param_3);

namespace Hooks {
	inline t_MoveHandler o_MoveHandler = nullptr;
	inline t_ScreenFadeMsg o_ScreenHandler = nullptr;

	unsigned int __fastcall hk_MoveHandler(char param_1);
	unsigned int __cdecl hk_ScreenHandler(const char* param_1, int param_2, const unsigned char* param_3);

	void Initialize();
	void ShutDown();
}

