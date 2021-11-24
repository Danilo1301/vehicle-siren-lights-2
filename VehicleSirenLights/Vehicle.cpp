#include "Vehicle.h"

int Vehicle::GetVehicleId(CVehicle* veh) {
	return reinterpret_cast<int>(veh);
}

Vehicle::Vehicle(CVehicle* veh) {
	m_Vehicle = veh;

	m_LightData.color = CRGBA(0, 0, 255);
}

int Vehicle::GetId() {
	return Vehicle::GetVehicleId(m_Vehicle);
}

void Vehicle::RenderFlash() {
	LightData lightData = m_LightData;
	CVector flashPosition = m_Vehicle->TransformFromObjectSpace(lightData.offset);

	Command< 0x09E5 >(flashPosition.x, flashPosition.y, flashPosition.z + 0.01f, (int)lightData.color.r, (int)lightData.color.g, (int)lightData.color.b, 40.0f);
}

void Vehicle::RenderCoronas() {
	if (CTimer::m_snTimeInMilliseconds - m_nRenderTime > 200) return;
	
	LightData lightData = m_LightData;

	int id = GetId() + 1000;

	CCoronas::RegisterCorona(
		id,
		m_Vehicle,
		lightData.color.r,
		lightData.color.g,
		lightData.color.b,
		lightData.color.a,
		lightData.offset,
		lightData.radius,
		400.0f,
		eCoronaType::CORONATYPE_SHINYSTAR,
		eCoronaFlareType::FLARETYPE_NONE,
		false, false, 0, 0.0f, false, 0.0f, 0, 15.0f, false, false);
}

void Vehicle::DrawDebugText() {
	CVector& posn = m_Vehicle->GetPosition();
	RwV3d rwp = { posn.x, posn.y, posn.z + 1.0f };
	RwV3d screenCoors; float w, h;
	if (CSprite::CalcScreenCoors(rwp, &screenCoors, &w, &h, true, true)) {
		CFont::SetOrientation(ALIGN_CENTER);
		CFont::SetColor(CRGBA(0, 255, 0, 255));
		CFont::SetDropShadowPosition(1);
		CFont::SetBackground(false, false);
		CFont::SetWrapx(500.0);
		CFont::SetScale(0.5, 1.0);
		CFont::SetFontStyle(FONT_SUBTITLES);
		CFont::SetProportional(true);
		char text[16];
		sprintf(text, "%i", GetId());
		CFont::PrintString(screenCoors.x, screenCoors.y, text);
	}
}

void Vehicle::Destroy() {

}