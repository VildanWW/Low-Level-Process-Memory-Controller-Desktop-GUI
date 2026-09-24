#pragma once
#include "BaseFunctional.h"
#include "EventBus.h"

class AntiFlash : public BaseFunctional {
private:
	EventToken screenToken = 0;
public:
	void Initialize() override;
	void ShutDown() override;

	bool HandleAntiFlashScreen(const char* param_1, int param_2, const unsigned char* param_3);
};

