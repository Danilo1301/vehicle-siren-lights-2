#pragma once

#include "plugin.h"

class LightData {
public:
	CVector offset = CVector(0, 0, 2.5f);
	CRGBA color = CRGBA(0, 0, 255, 255);
	float radius = 0.1f;
	float flashDistance = 10.0f;

	LightData() {}
};