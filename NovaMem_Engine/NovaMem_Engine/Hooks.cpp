#include "pch.h"
#include "Hooks.h"
#include "Offsets.h"
#include "MinHook.h"
#include "EventBus.h"
#include <imgui_impl_opengl2.h>
#include <imgui_impl_win32.h>
#include "MenuManager.h"
#include "Tabs.h"
#include <memory>

namespace Core {
	namespace Hooks {
		void Initialize() {
			MH_CreateHook((LPVOID)Offsets::absoluteMoveAddress, &hk_MoveHandler, (LPVOID*)&o_MoveHandler);
			MH_CreateHook((LPVOID)Offsets::absoluteScreenAddress, &hk_ScreenHandler, (LPVOID*)&o_ScreenHandler);
			MH_CreateHook((LPVOID)Offsets::absoluteGlBeginAddress, &hk_GlBeginHandler, (LPVOID*)&o_GlBeginHandler);
			MH_CreateHook((LPVOID)Offsets::absoluteGlVertex3F, &hk_GlVertex3F, (LPVOID*)&o_GlVertex3F);
			MH_CreateHook((LPVOID)Offsets::absoluteWglSwapBuffers, &hk_WglSwapBuffers, (LPVOID*)&o_WglSwapBuffers);

			MH_EnableHook(MH_ALL_HOOKS);
		}

		void ShutDown() {
			MH_DisableHook(MH_ALL_HOOKS);

			EventBus::moveList.clear();
			EventBus::screenList.clear();
			EventBus::glBeginList.clear();
			EventBus::glVertex3FList.clear();

			if (ImGui::GetCurrentContext() != nullptr) {
				ImGui_ImplOpenGL2_Shutdown();
				ImGui_ImplWin32_Shutdown();
				ImGui::DestroyContext();
			}
		}

		unsigned int __fastcall hk_MoveHandler(char param_1) {
			unsigned int value = o_MoveHandler(param_1);

			for (const auto& [token, callback] : EventBus::moveList) {
				value = callback(param_1, value);
			}
			return value;
		}

		unsigned int __cdecl hk_ScreenHandler(const char* param_1, int param_2, const unsigned char* param_3) {
			bool allowMessage = true;

			for (const auto& [token, callback] : EventBus::screenList) {
				if (!callback(param_1, param_2, param_3)) {
					allowMessage = false;
				}
			}

			if (!allowMessage) {
				return 1;
			}

			return o_ScreenHandler(param_1, param_2, param_3);
		}

		void APIENTRY hk_GlBeginHandler(unsigned int param_1) {
			bool shouldBlock = false;

			for (auto const& [token, callback] : EventBus::glBeginList) {
				if (callback) {
					if (callback(param_1)) {
						shouldBlock = true;
					}
				}
			}

			if (shouldBlock) { return; }

			o_GlBeginHandler(param_1);
		}

		void APIENTRY hk_GlVertex3F(float param_1, float param_2, float param_3) {
			bool shouldBlock = false;

			for (auto const& [token, callback] : EventBus::glVertex3FList) {
				if (callback) {
					if (callback(param_1, param_2, param_3)) {
						shouldBlock = true;
					}
				}
			}

			if (shouldBlock) { return; }

			o_GlVertex3F(param_1, param_2, param_3);
		}

		BOOL __stdcall hk_WglSwapBuffers(HDC hdc) {
			static bool imguiInit = false;

			if (!imguiInit) {
				HWND hwnd = WindowFromDC(hdc);
				ImGui::CreateContext();
				ImGui_ImplWin32_Init(hwnd);
				ImGui_ImplOpenGL2_Init();

				Gui::Menu::menuManager.AddTab(std::make_unique<Gui::Menu::Combat>());
				Gui::Menu::menuManager.AddTab(std::make_unique<Gui::Menu::Movement>());
				Gui::Menu::menuManager.AddTab(std::make_unique<Gui::Menu::Visuals>());
				Gui::Menu::menuManager.AddTab(std::make_unique<Gui::Menu::Misc>());

				imguiInit = true;
			}

			ImGui_ImplOpenGL2_NewFrame();
			ImGui_ImplWin32_NewFrame();
			ImGui::NewFrame();

			Gui::Menu::menuManager.DrawMainWindow();

			ImGui::Render();
			ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

			return o_WglSwapBuffers(hdc);
		}
	}
}

