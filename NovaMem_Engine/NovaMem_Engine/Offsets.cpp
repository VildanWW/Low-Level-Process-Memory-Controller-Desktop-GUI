#include "pch.h"

#include <Windows.h>
#include <cstdint>

#include "Offsets.h"

namespace Core {
	namespace Offsets {
		void InitializeOffsets() {
            clientBase = (uintptr_t)GetModuleHandleA("client.dll");
            hwBase = (uintptr_t)GetModuleHandleA("hw.dll");
            opengl32 = (intptr_t)GetModuleHandleA("opengl32.dll");
            absoluteMoveAddress = clientBase + GameFunctions::moveAddress;
            absoluteScreenAddress = hwBase + GameFunctions::screenFadeAddress;
            absoluteGlBeginAddress = opengl32 + GameFunctions::glBeginAddress;
            absoluteGlVertex3F = opengl32 + GameFunctions::glVertex3F;

            absoluteWglSwapBuffers = (uintptr_t)GetProcAddress((HMODULE)opengl32, "wglSwapBuffers");

            airAddress = (int*)(clientBase + jumpAddress);
		}
	}
}

