#include "pch.h"

#include <fstream>
#include <nlohmann/json.hpp>

#include "JsonSerializer.h"
#include "Config.h"

using json = nlohmann::json;

namespace Core {
	namespace Utils {
		void JsonSerializer::LoadFromFile() {
			std::string path = Settings::configSettings.pathJson;

			std::ifstream ifst(path);

			if (!ifst.is_open()) {

				LoadToFile();

				return;
			}

			json jsonData;
			ifst >> jsonData;
			ifst.close();

			try {
				Settings::configSettings = jsonData.get<Settings::ConfigSettings>();
			}
			catch (const json::exception& ex) {
				LoadToFile();
			}
		}
		void JsonSerializer::LoadToFile() {
			std::string path = Settings::configSettings.pathJson;

			std::ofstream ofst(path);

			if (!ofst.is_open()) {
				return;
			}

			json jsonData = Settings::configSettings;

			ofst << jsonData.dump(4); // 4 this is standard size for space in json file

			ofst.close();
		}
	}
}