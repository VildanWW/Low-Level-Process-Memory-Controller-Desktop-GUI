#pragma once
#include <vector>
#include <memory>

namespace Core {
	namespace Functionals {
		class BaseFunctional;
	}
}

namespace Core {
	namespace Functionals {
		class FunctionalsManager {
		private:
			std::vector<std::unique_ptr<BaseFunctional>> functionals;
		public:
			FunctionalsManager(); 
			~FunctionalsManager();

			void InitializeAddressesAndModules();
			void StartWorking();
			void Shutdown();
		};
	}
}


