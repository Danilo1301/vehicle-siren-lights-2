#include "GUI.h"

CRGBA COLOR_GUI_TITLE_BACKGROUND(0, 0, 0, 200);
CRGBA COLOR_WHITE(255, 255, 255);
CRGBA COLOR_BLACK(0, 0, 0);
CRGBA COLOR_GUI_BACKGROUND(0, 0, 0, 120);

float ScreenX(float x) { return (x * (SCREEN_COORD_CENTER_X * 2)) / 1024.0f; }
float ScreenY(float y) { return (y * (SCREEN_COORD_CENTER_Y * 2)) / 768.0f; }

float GUI::m_fGuiWidth = 500.0f;
float GUI::m_fBtnHeight = 30.0f;

CVector2D GUI::m_drawGuiStartPosition(10, 10);
CVector2D GUI::m_drawGuiCurrentPosition(0, 0);

int GUI::m_nSelectedIndex = 0;
int GUI::m_nCurrentItemIndex = 0;
int GUI::m_nTotalItems = 0;
bool GUI::m_bBtnCanSelect = false;

void GUI::Update() {
	
	if (KeyListener::GetKeyDown(VK_UP)) {
		m_nSelectedIndex--;
		//CMessages::AddMessageJumpQ("DOWN", 300, 0, false);
	}

	if (KeyListener::GetKeyDown(VK_DOWN)) {
		m_nSelectedIndex++;
		//CMessages::AddMessageJumpQ("DOWN", 300, 0, false);
	}
	

	if (m_nSelectedIndex < 0) m_nSelectedIndex = 0;
	if (m_nSelectedIndex > m_nTotalItems - 1) m_nSelectedIndex = m_nTotalItems - 1;

	if (!KeyPressed(VK_SPACE)) m_bBtnCanSelect = true;
}

void GUI::Begin(const char* title) {
	m_drawGuiCurrentPosition.x = m_drawGuiStartPosition.x;
	m_drawGuiCurrentPosition.y = m_drawGuiStartPosition.y;

	m_nCurrentItemIndex = -1;
	m_nTotalItems = 0;

	//

	CFont::SetOrientation(eFontAlignment::ALIGN_LEFT);
	CFont::SetDropShadowPosition(0);
	CFont::SetBackground(false, false);
	CFont::SetFontStyle(FONT_SUBTITLES);
	CFont::SetProportional(true);
	CFont::SetColor(CRGBA(0, 0, 0));
	

	//

	float height = 25.0f;
	float s = 0.7f;

	CFont::SetScale(ScreenX(0.7 * s), ScreenY(1.4 * s));
	CSprite2d::DrawRect(CRect(ScreenX(m_drawGuiCurrentPosition.x), ScreenY(m_drawGuiCurrentPosition.y), ScreenX(m_drawGuiCurrentPosition.x + m_fGuiWidth), ScreenY(m_drawGuiCurrentPosition.y + height)), COLOR_GUI_TITLE_BACKGROUND);

	char str[256];
	snprintf(str, 256, "%s", title);
	CFont::SetColor(COLOR_WHITE);
	CFont::PrintString(ScreenX(m_drawGuiCurrentPosition.x + 4), ScreenY(m_drawGuiCurrentPosition.y + 3), str);

	CFont::SetScale(ScreenX(0.7), ScreenY(1.4));
	m_drawGuiCurrentPosition.y += height;
}

void GUI::BeginDrawItem() {
	m_nCurrentItemIndex++;
	m_nTotalItems++;
}

void GUI::DrawGUIItemBackground() {
	float width = m_fGuiWidth;
	float height = m_fBtnHeight;
	CRGBA bgColor = m_nCurrentItemIndex == m_nSelectedIndex ? COLOR_WHITE : COLOR_GUI_BACKGROUND;

	CSprite2d::DrawRect(CRect(ScreenX(m_drawGuiCurrentPosition.x), ScreenY(m_drawGuiCurrentPosition.y), ScreenX(m_drawGuiCurrentPosition.x + width), ScreenY(m_drawGuiCurrentPosition.y + height)), bgColor);
}

bool GUI::Button(const char* text) {
	BeginDrawItem();
	DrawGUIItemBackground();

	bool isHovering = m_nCurrentItemIndex == m_nSelectedIndex;
	int guiItemIndex = m_nCurrentItemIndex;
	bool returnResult = false;

	if (isHovering && KeyPressed(VK_SPACE) && m_bBtnCanSelect) {
		m_bBtnCanSelect = false;
		returnResult = true;
	}
	else {
		
		CFont::SetColor(isHovering ? COLOR_BLACK : COLOR_WHITE);
		
		char str[256];
		snprintf(str, 256, "%s", text);
		CFont::PrintString(ScreenX(m_drawGuiCurrentPosition.x), ScreenY(m_drawGuiCurrentPosition.y), str);
	}

	m_drawGuiCurrentPosition.y += m_fBtnHeight;

	return returnResult;
};