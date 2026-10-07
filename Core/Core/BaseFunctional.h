#pragma once

namespace Core {
	namespace Functionals {
		class BaseFunctional {
		protected:
			bool running = false;
		public:
			virtual ~BaseFunctional() = default;

			virtual void Initialize() = 0;
			virtual void ShutDown() = 0;

			bool IsRunning() const { return running; }
		};
	}
}
