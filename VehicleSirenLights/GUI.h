#pragma once

#include "pch.h"

class GUI {
private: 
	static float m_fGuiWidth;
	static float m_fBtnHeight;
	static int m_nSelectedIndex;
	static bool m_bBtnCanSelect;
	static int m_nTotalItems;
	static int m_nCurrentItemIndex;
	static CVector2D m_drawGuiCurrentPosition;
	static CVector2D m_drawGuiStartPosition;

	static void DrawGUIItemBackground();
	static void BeginDrawItem();
public:
	



	static void Update();
	static void Begin(const char* title);
	static bool Button(const char* text);
};
