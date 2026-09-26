#include "pch.h"
#include "AntiSmoke.h"
#include <gl/GL.h>

void AntiSmoke::Initialize() {
	running = true;

	glBeginToken = EventBus::SubscribeGlBegin([this](unsigned int mode) {
		return HandleGlBeginAntiSmoke(mode);
	});

	vertexToken = EventBus::SubscribeGlVertex3F([this](float x, float y, float z) {
		return HandleGlVertexAntiSmoke(x, y, z);
	});
}

void AntiSmoke::ShutDown() {
	running = false;

	EventBus::UnsubscribeGlBegin(glBeginToken);
	EventBus::UnsubscribeGlVertex3F(vertexToken);
}

bool AntiSmoke::HandleGlBeginAntiSmoke(unsigned int mode) {
	if (running && mode == GL_QUADS) {
		float curcol[4];;
		glGetFloatv(GL_CURRENT_COLOR, curcol);

		if (curcol[0] == curcol[1] && curcol[1] == curcol[2] && curcol[0] > 0.01f && curcol[0] < 0.99f) {
			bIsSmokeCurrentQuad = true;
			return true;
		}
	}
	bIsSmokeCurrentQuad = false;
	return false;
}

bool AntiSmoke::HandleGlVertexAntiSmoke(float x, float y, float z) {
	if (running && bIsSmokeCurrentQuad) { return true; }
	return false;
}

