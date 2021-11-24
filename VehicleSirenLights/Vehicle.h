#pragma once

#include "pch.h"

#include "LightData.h"

class Vehicle {
public:
	static int GetVehicleId(CVehicle* veh);

	unsigned int m_nRenderTime = 0;
	LightData m_LightData;
	CVehicle* m_Vehicle;

	Vehicle(CVehicle* veh);

	int GetId();
	void RenderFlash();
	void RenderCoronas();
	void DrawDebugText();
	void Destroy();
};