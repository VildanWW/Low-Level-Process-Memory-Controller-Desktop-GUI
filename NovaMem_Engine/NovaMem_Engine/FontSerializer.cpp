#include "pch.h"

#include <filesystem>
#include <spdlog/spdlog.h> 
#include <Windows.h>

#include "FontSerializer.h"
#include "imgui.h"
#include "IconsFontAwesome5.h"

namespace Gui {
	namespace Fonts {
		void FontInitialize() {
			ImGuiIO& io = ImGui::GetIO();

			float screenHeight = io.DisplaySize.y;

			float calculatedFontSize = screenHeight * 0.015f;

			const char* pathFont = "C:\\Windows\\Fonts\\Arial.ttf";

			if (std::filesystem::exists(pathFont)) {
				io.Fonts->AddFontFromFileTTF(pathFont, calculatedFontSize);
				spdlog::info("Arial.ttf successfully loaded. Size: {:.1f}px", calculatedFontSize);
			}
			else {
				io.Fonts->AddFontDefault();
				spdlog::warn("Arial.ttf not found! Fallback to ImGui default font");
			}

			char dllPath[MAX_PATH];
			HMODULE hModule = NULL;

			GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
							   GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
							   (LPCSTR)&FontInitialize, &hModule);
			GetModuleFileNameA(hModule, dllPath, MAX_PATH);

			std::filesystem::path p(dllPath);
			std::filesystem::path dllDir = p.parent_path();

			std::filesystem::path fullPathTTF = dllDir / "fa-solid-900.ttf";
			std::filesystem::path fullPathWeaponsTTF = dllDir / "csgo_icons.ttf";

			if (std::filesystem::exists(fullPathTTF)) {
				static const ImWchar iconsRanges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
				ImFontConfig iconsConfig;
				iconsConfig.MergeMode = true;
				iconsConfig.PixelSnapH = true;
				iconsConfig.GlyphMinAdvanceX = calculatedFontSize;
				
				io.Fonts->AddFontFromFileTTF(fullPathTTF.string().c_str(), calculatedFontSize, &iconsConfig, iconsRanges);
				spdlog::info("FontAwesome (fa-solid-900.ttf) successfully loaded.");
			}
			else {
				spdlog::warn("fa-solid-900.ttf is missing! Menu icons will not be rendered.");
			}

			if (std::filesystem::exists(fullPathWeaponsTTF)) {
				static const ImWchar iconsRanges[] = { 0x0020, 0x00FF, 0xE000, 0xE0FF, 0 };
				ImFontConfig iconsWeapons;
				
				iconsWeapons.PixelSnapH = true;

				io.Fonts->AddFontFromFileTTF(fullPathWeaponsTTF.string().c_str(), calculatedFontSize, &iconsWeapons, iconsRanges);
				spdlog::info("IconsWeapons (csgo_icons.ttf) successfully loaded.");
			}
			else {
				spdlog::warn("csgo_icons.ttf is missing! Weapons icons will not be rendered.");
			}
		}
	}
}