#pragma once

#include "imgui.h"

namespace Gui {
	struct Palette {
		// Main theme colors
		static inline const ImVec4 Background = ImVec4(0.243f, 0.137f, 0.321f, 1.00f); // #3E2352 (Dart purple, main window background)
		static inline const ImVec4 Accent = ImVec4(0.694f, 0.549f, 0.803f, 1.00f); // #B18CCD (Light lavender, headers and borders)
		static inline const ImVec4 AccentHovered = ImVec4(0.694f, 0.549f, 0.803f, 0.50f); // #B18CCD with 50% alpha (Semi-transparent lavender)
		static inline const ImVec4 ChildBg = ImVec4(0.458f, 0.145f, 0.690f, 1.00f); // #7525B0 (Vibrant purple, child window background)
	
		// Text elements
		static inline const ImVec4 TextMain = ImVec4(1.00f, 1.00f, 1.00f, 1.00f); // #FFFFFF (Pure white, primary text)
		static inline const ImVec4 TextDark = ImVec4(0.243f, 0.137f, 0.321f, 1.00f); // #3E2352 (Dark purple, high contrast text for light headers)
		static inline const ImVec4 TextMuted = ImVec4(0.400f, 0.300f, 0.500f, 0.60f); // #664C80 with 60% alpha (Dimmed purple for inactive tabs)
		static inline const ImVec4 TextDisabled = ImVec4(0.800f, 0.800f, 0.800f, 0.60f); // #CCCCCC with 60% alpha (Grayed out text for disabled options)

		static inline const ImVec4 BtnTransperent = ImVec4(0.000f, 0.000f, 0.000f, 0.00f); // #000000 with 0% alpha (Fully transparent button background)
		static inline const ImVec4 BtnHovered = ImVec4(1.000f, 1.000f, 1.000f, 0.10f); // #FFFFFF with 10% alpha (White overlay on hover)
		static inline const ImVec4 BtnActive = ImVec4(1.000f, 1.000f, 1.000f, 0.20f); // #FFFFFF with 20% alpha (White overlay on click)

		static inline const ImVec4 ItemTabs = ImVec4(0.5255f, 0.0000f, 0.9137f, 1.0000f); // #8600E9 Light violet
	};
}