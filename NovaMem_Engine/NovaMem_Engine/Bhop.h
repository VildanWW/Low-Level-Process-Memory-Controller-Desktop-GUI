#pragma once
#include "BaseFunctional.h"
#include "EventBus.h"

namespace Core {
	namespace Functionals {
		class Bhop : public BaseFunctional {
		private:
			EventToken moveToken = 0;
		public:
			void Initialize() override;
			void ShutDown() override;

			unsigned int HandleBhopMove(char param_1, unsigned int value);
		};
	}
}
