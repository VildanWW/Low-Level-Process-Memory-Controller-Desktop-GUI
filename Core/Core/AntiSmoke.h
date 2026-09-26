#pragma once
#include "BaseFunctional.h"
#include "EventBus.h"

class AntiSmoke : public BaseFunctional {
private:
	EventToken glBeginToken = 0;
	EventToken vertexToken = 0;
	bool bIsSmokeCurrentQuad = false;
public:
	void Initialize() override;
	void ShutDown() override;

	bool HandleGlBeginAntiSmoke(unsigned int mode);
	bool HandleGlVertexAntiSmoke(float x, float y, float z);
};

