#pragma once

#include "string"

namespace Core {
	namespace Settings {
		class ConfigSettings;
	}
}

namespace Core {
	namespace Utils {
		class JsonSerializer {
		public:
			static void LoadFromFile();
			static void LoadToFile();
		};
	}
}
