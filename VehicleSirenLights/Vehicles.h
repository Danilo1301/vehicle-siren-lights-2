#pragma once

#include "pch.h"

#include <map>
#include <string>
#include "Vehicle.h"

using namespace std;

class Vehicles {
public:
	static map<int, Vehicle*> m_Vehicles;

	static void Update();
	static void Draw();
	static void CheckIfVehiclesStillExists();
	static bool HasVehicle(CVehicle* veh);
	static Vehicle* AddVehicle(CVehicle* veh);
	static void RemoveVehicle(CVehicle* veh);
	static void RenderVehicle(CVehicle* vehicle);
};