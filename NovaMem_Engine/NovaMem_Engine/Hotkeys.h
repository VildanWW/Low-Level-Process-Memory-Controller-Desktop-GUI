#pragma once

namespace Core {
	enum struct Hotkeys {
		Bhop = 0x20,
		AutoDuck = 0xA4
	};

	enum struct GoldSrcButtons {
		IN_JUMP = (1 << 1)
	};

	enum IdFunction {
		Bhop = 0,
		NoFlash = 1,
		NoSmoke = 2,
		EndProgram = 255
	};

	enum State {
		Off = 0,
		On = 1
	};
}
