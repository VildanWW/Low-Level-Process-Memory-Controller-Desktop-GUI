#pragma once

namespace Core {
	namespace Hooks {
		typedef unsigned int(__fastcall* t_MoveHandler)(char param_1);
		typedef unsigned int(__cdecl* t_ScreenFadeMsg)(const char* param_1, int param_2, const unsigned char* param_3);
		typedef void(APIENTRY* t_GlBegin)(unsigned int param_1);
		typedef void(APIENTRY* t_GlVertex3F)(float param_1, float param_2, float param_3);
		typedef BOOL(WINAPI* t_WglSwapBuffers)(HDC hdc);
		typedef LRESULT(CALLBACK* t_WndProc)(HWND hWnd, UINT uInt, WPARAM wParam, LPARAM lParam);

		inline t_MoveHandler o_MoveHandler = nullptr;
		inline t_ScreenFadeMsg o_ScreenHandler = nullptr;
		inline t_GlBegin o_GlBeginHandler = nullptr;
		inline t_GlVertex3F o_GlVertex3F = nullptr;
		inline t_WglSwapBuffers o_WglSwapBuffers = nullptr;
		inline t_WndProc o_WndProc = nullptr;

		unsigned int __fastcall hk_MoveHandler(char param_1);
		unsigned int __cdecl hk_ScreenHandler(const char* param_1, int param_2, const unsigned char* param_3);
		void APIENTRY hk_GlBeginHandler(unsigned int param_1);
		void APIENTRY hk_GlVertex3F(float param_1, float param_2, float param_3);
		BOOL WINAPI hk_WglSwapBuffers(HDC hdc);
		LRESULT CALLBACK hk_WndProc(HWND hWnd, UINT uInt, WPARAM wParam, LPARAM lParam);

		inline HWND gameHwnd = nullptr;
		inline WNDPROC wndProc = nullptr;
		inline bool unloadingFromGame = false;

		void Initialize();
		void ShutDown();
	}
}

