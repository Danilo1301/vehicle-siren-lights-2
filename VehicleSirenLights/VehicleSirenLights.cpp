#include "VehicleSirenLights.h"

void DisableOriginalLights()
{
	//https://gtaforums.com/topic/757430-block-siren-lights-memory-address-for-it/

	//0A8C: write_memory 0x70026C size 4 value 0x90909090 virtual_protect 0
	//plugin::patch::SetUInt(0x70026C, 0x90909090);

	//0A8C : write_memory 0x700270 size 1 value 0x90 virtual_protect 0
	//plugin::patch::SetUChar(0x700270, 0x90);

	//0A8C : write_memory 0x700271 size 1 value 0x90 virtual_protect 0
	//plugin::patch::SetUChar(0x700271, 0x90);

	//0A8C : write_memory 0x700261 size 4 value 0x90909090 virtual_protect 0
	//plugin::patch::SetUInt(0x700261, 0x90909090);

	//0A8C : write_memory 0x700265 size 1 value 0x90 virtual_protect 0
	//plugin::patch::SetUChar(0x700265, 0x90);

	//0A8C : write_memory 0x700266 size 1 value 0x90 virtual_protect 0
	//plugin::patch::SetUChar(0x700266, 0x90);

	//0A8C : write_memory 0x700257 size 4 value 0x90909090 virtual_protect 0
	//plugin::patch::SetUInt(0x700257, 0x90909090);

	//0A8C : write_memory 0x70025B size 1 value 0x90 virtual_protect 0
	//plugin::patch::SetUChar(0x70025B, 0x90);

	//0A8C : write_memory 0x70025C size 1 value 0x90 virtual_protect 0
	//plugin::patch::SetUChar(0x70025C, 0x90);

	//--

	//0@ = 0xC3F12C //CPointLight => RGB
	//int pointLight = 0xC3F12C;

	//0A8C: write_memory 0@ size 4 value 0.0 virtual_protect 0 // R
	//plugin::patch::SetUInt(pointLight, 0);

	//0@ += 4
	//pointLight += 4;

	//0A8C: write_memory 0@ size 4 value 0.0 virtual_protect 0  // G
	//plugin::patch::SetUInt(pointLight, 0);

	//0@ += 4
	//pointLight += 4;

	//0A8C: write_memory 2@ size 4 value 0.0 virtual_protect 0 
	//plugin::patch::SetUInt(pointLight, 0);

	//--

	//NOPs the function that draws the coronnas
	//0A8C: write_memory 0x6ABA60 size 4 value 0x90909090 virtual_protect 0
	plugin::patch::SetUInt(0x6ABA60, 0x90909090);

	//0A8C: write_memory 0x6ABA64 size 1 value 0x90 virtual_protect 0
	plugin::patch::SetUChar(0x6ABA64, 0x90);

	//--

	//NOPs the function that checks wether the siren was activated or not
	//0A8C: write_memory 0x6FFDFC size 1 value 0x90 virtual_protect 0
	//plugin::patch::SetUChar(0x6FFDFC, 0x90);

	//0A8C: write_memory 0x6FFDFD size 1 value 0x90 virtual_protect 0
	//plugin::patch::SetUChar(0x6FFDFD, 0x90);

	//0A8C: write_memory 0x6FFDFE size 1 value 0x90 virtual_protect 0
	//plugin::patch::SetUChar(0x6FFDFE, 0x90);

	//--



	//not using
	//NOPs the function that activates the shadow drawing under the vehicle
	//0A8C: write_memory 0x70802D size 4 value 0x90909090 virtual_protect 0
	plugin::patch::SetUInt(0x70802D, 0x90909090);
}

void VehicleSirenLights::Initialize() {
	DisableOriginalLights();
};

void VehicleSirenLights::Draw() {
	GUI::Begin("Thats the title");

	if (GUI::Button("Sirene 1")) {
		CMessages::AddMessageJumpQ("text pressed", 1000, 0, false);
	}

	if (GUI::Button("Adicionar nova sirene")) {
		CMessages::AddMessageJumpQ("somet else pressed", 1000, 0, false);
	}

	Vehicles::Draw();
};

void VehicleSirenLights::TestRenderVehicle() {
	/*
	CVehicle* veh = FindPlayerVehicle(0, false);
	if (!(veh > 0))
	{
		CMessages::AddMessageJumpQ("Voce precisa estar em um veiculo!", 1000, 0, false);
		return;
	}
	
	int id = reinterpret_cast<int>(veh) + 1000;

	LightData light();
	light.vehicle = veh;

	RenderLight(light);
	*/
}

void VehicleSirenLights::ProcessScripts() {
	GUI::Update();
	Vehicles::Update();

	TestRenderVehicle();

	static char str[256];
	snprintf(str, 256, "vehicles: %d", Vehicles::m_Vehicles.size());
	CMessages::AddMessageJumpQ(str, 1000, 0, false);
};

void VehicleSirenLights::RenderVehicle(CVehicle* vehicle) {
	Vehicles::RenderVehicle(vehicle);
};

VehicleSirenLights::VehicleSirenLights() {
	Events::initGameEvent += Initialize;
	Events::drawHudEvent.before += Draw;
	Events::processScriptsEvent.before += ProcessScripts;
	Events::vehicleRenderEvent += RenderVehicle;

	MessageBox(HWND_DESKTOP, "Loaded", "Error", MB_ICONERROR);
};