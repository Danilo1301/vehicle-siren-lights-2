#pragma once

#include <map>
#include <string>

using namespace std;

class KeyListener {
private:
	static map<int, bool> m_KeysPressed;
public:
	static void Update();
	static bool GetKeyDown(int key);
};