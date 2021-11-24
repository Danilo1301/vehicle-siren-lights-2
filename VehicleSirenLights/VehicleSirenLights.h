#pragma once

#include "pch.h"
#include "GUI.h"
#include "Vehicles.h"
#include "LightData.h"


class VehicleSirenLights {
private:
	static void Initialize();
	static void Draw();
	static void ProcessScripts();
	static void RenderVehicle(CVehicle* vehicle);
	static void TestRenderVehicle();
public:
	VehicleSirenLights();

} vehicleSirenLights;

/*
#include "pch.h"

class VehicleSirenLights
{
private:
	static void Initialize();
	static void Draw();
	static void ProcessScripts();
	static void RenderVehicle(CVehicle* vehicle);
public:
	VehicleSirenLights();
};

*/