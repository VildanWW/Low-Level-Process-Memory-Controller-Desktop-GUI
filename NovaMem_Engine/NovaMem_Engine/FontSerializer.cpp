#include "pch.h"

#include <filesystem>
#include <spdlog/spdlog.h> 

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

			const char* pathTTF = "fa-solid-900.ttf";

			if (std::filesystem::exists(pathTTF)) {
				static const ImWchar iconsRanges[] = { 0xE005, 0xF8FF, 0 };
				ImFontConfig iconsConfig;
				iconsConfig.MergeMode = true;
				iconsConfig.PixelSnapH = true;
				iconsConfig.GlyphMinAdvanceX = calculatedFontSize;
				
				io.Fonts->AddFontFromFileTTF(pathTTF, calculatedFontSize, &iconsConfig, iconsRanges);
				spdlog::info("FontAwesome (fa-solid-900.ttf) successfully loaded.");
			}
			else {
				spdlog::warn("fa-solid-900.ttf is missing! Menu icons will not be rendered.");
			}

			io.Fonts->Build();
		}
	}
}