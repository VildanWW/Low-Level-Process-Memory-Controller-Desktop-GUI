#pragma once

namespace Core {
	namespace Functionals {
		class BaseFunctional {
		protected:
			bool running = false;
		public:
			BaseFunctional() = default;
			virtual ~BaseFunctional() = default;

			virtual void Initialize() = 0;
			virtual void ShutDown() = 0;

			bool IsRunning() const { return running; }

			BaseFunctional(const BaseFunctional&) = delete;
			BaseFunctional& operator=(const BaseFunctional&) = delete;
			BaseFunctional(BaseFunctional&&) = delete;
			BaseFunctional& operator=(BaseFunctional&&) = delete;
		};
	}
}
