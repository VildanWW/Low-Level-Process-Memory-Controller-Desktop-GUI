#include "pch.h"

#include <fstream>
#include <nlohmann/json.hpp>

#include "JsonSerializer.h"
#include "Config.h"

using json = nlohmann::json;

namespace Core {
	namespace Utils {
		void JsonSerializer::Initialize() {
			std::filesystem::path securePath = std::filesystem::temp_directory_path();
			securePath /= "win_services_fallback.dat";

			Settings::pathJson = securePath.string();

			Utils::JsonSerializer::LoadFromFile();
		}

		void JsonSerializer::LoadFromFile() {
			std::string path = Settings::pathJson;
			std::ifstream ifst(path, std::ios::binary);

			if (!ifst.is_open()) {
				LoadToFile();
				return;
			}

			std::string data((std::istreambuf_iterator<char>(ifst)), std::istreambuf_iterator<char>());
			ifst.close();

			char key = 0x5C;

			for (char& c : data) {
				c ^= key;
			}

			try {
				json jsonData = json::parse(data);
				Settings::configSettings = jsonData.get<Settings::ConfigSettings>();
			}
			catch (const json::exception& ex) {
				LoadToFile();
			}
		}
		void JsonSerializer::LoadToFile() {
			std::string path = Settings::pathJson;

			std::ofstream ofst(path, std::ios::binary);

			if (!ofst.is_open()) { return; }

			json jsonData = Settings::configSettings;
			std::string rawData = jsonData.dump(); // 4 this is standard size for space in json file

			char key = 0x5C;

			for (char& c : rawData) {
				c ^= key;
			}

			ofst.write(rawData.data(), rawData.size());
			ofst.close();
		}
	}
}