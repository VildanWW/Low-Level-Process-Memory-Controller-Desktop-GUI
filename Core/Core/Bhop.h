#pragma once
#include "BaseFunctional.h"
#include "EventBus.h"

class Bhop : public BaseFunctional {
private:
	EventToken moveToken = 0;
public:
	void Initialize() override;
	void ShutDown() override;

	unsigned int HandleBhopMove(char param_1, unsigned int value);
};