#include "KeyListener.h"
#include "plugin.h"

map<int, bool> KeyListener::m_KeysPressed;

void KeyListener::Update() {

}

bool KeyListener::GetKeyDown(int key) {
	if (plugin::KeyPressed(key)) {
		if (m_KeysPressed.count(key)) return false;
		m_KeysPressed.insert(std::pair<int, bool>(key, true));
		return true;
	}

	if (m_KeysPressed.count(key)) {
		map<int, bool>::iterator iter = m_KeysPressed.find(key);
		m_KeysPressed.erase(iter);
	}

	return false;
}