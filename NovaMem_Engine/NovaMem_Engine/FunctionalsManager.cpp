#include "pch.h"

#include "FunctionalsManager.h"
#include "BaseFunctional.h"
#include "Bhop.h"
#include "AntiFlash.h"
#include "AntiSmoke.h"

namespace Core {
	namespace Functionals {
        FunctionalsManager::FunctionalsManager() = default;

        FunctionalsManager::~FunctionalsManager() = default;

        void FunctionalsManager::InitializeAddressesAndModules() {
            functionals.push_back(std::make_unique<Bhop>());
            functionals.push_back(std::make_unique<AntiFlash>());
            functionals.push_back(std::make_unique<AntiSmoke>());
        }

        void FunctionalsManager::StartWorking() {
            for (int i = 0; i < functionals.size(); i++) {
                functionals[i]->Initialize();
            }
        }

        void FunctionalsManager::Shutdown() {
            for (int i = 0; i < functionals.size(); i++) {
                functionals[i]->ShutDown();
            }
        }
	}
}