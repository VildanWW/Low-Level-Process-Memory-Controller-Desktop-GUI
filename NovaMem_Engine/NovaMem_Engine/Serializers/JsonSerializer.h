#pragma once

namespace Core {
	namespace Utils {
		class JsonSerializer {
		private:
			static void LoadFromFile();
		public:
			static void Initialize();
			static void LoadToFile();
		};
	}
}
