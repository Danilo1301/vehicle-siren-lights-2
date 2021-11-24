#include "Vehicles.h"

map<int, Vehicle*> Vehicles::m_Vehicles;

void Vehicles::Update() {
	for (CVehicle* veh : CPools::ms_pVehiclePool)
	{
		if (!HasVehicle(veh)) AddVehicle(veh);
	}

	CheckIfVehiclesStillExists();

	for (auto p : m_Vehicles) {
		Vehicle* vehicle = p.second;

		vehicle->RenderFlash();
		vehicle->RenderCoronas();
	}
}

void Vehicles::Draw() {
	for (auto p : m_Vehicles) {
		Vehicle* vehicle = p.second;

		vehicle->DrawDebugText();
	}
}

void Vehicles::CheckIfVehiclesStillExists() {
	for (auto p : m_Vehicles)
	{
		Vehicle* vehicle = p.second;
		bool found = false;

		for (CVehicle* veh : CPools::ms_pVehiclePool)
		{
			if (veh == vehicle->m_Vehicle)
			{
				found = true;
				break;
			}
		}

		if (!found) RemoveVehicle(vehicle->m_Vehicle);
	}
}

bool Vehicles::HasVehicle(CVehicle* veh) {
	return m_Vehicles.count(Vehicle::GetVehicleId(veh));
}

Vehicle* Vehicles::AddVehicle(CVehicle* veh) {
	Vehicle* vehicle = new Vehicle(veh);
	m_Vehicles.insert(std::pair<int, Vehicle*>(vehicle->GetId(), vehicle));
	return vehicle;
}

void Vehicles::RemoveVehicle(CVehicle* veh) {
	map<int, Vehicle*>::iterator iter = m_Vehicles.find(Vehicle::GetVehicleId(veh));
	m_Vehicles.erase(iter);

	Vehicle* vehicle = (*iter).second;
	vehicle->Destroy();
}

void Vehicles::RenderVehicle(CVehicle* veh) {
	if (HasVehicle(veh)) {
		Vehicle* vehicle = m_Vehicles.at(Vehicle::GetVehicleId(veh));

		vehicle->m_nRenderTime = CTimer::m_snTimeInMilliseconds;
	}
};