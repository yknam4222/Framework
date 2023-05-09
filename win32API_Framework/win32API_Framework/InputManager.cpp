#include "InputManager.h"

InputManager* InputManager::Instance = nullptr;

InputManager::InputManager() : inputKey(0)
{
}

InputManager::~InputManager()
{
}

void InputManager::CheckKey()
{
	inputKey = 0;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		inputKey |= KEYID_UP;

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		inputKey |= KEYID_DOWN;

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		inputKey |= KEYID_LEFT;

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		inputKey |= KEYID_RIGHT;

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		inputKey |= KEYID_RETURN;

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		inputKey |= KEYID_SPACE;

	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		inputKey |= KEYID_ESCAPE;

	if (GetAsyncKeyState(VK_CONTROL) & 0x8000)
		inputKey |= KEYID_CONTROL;
}