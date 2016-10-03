#pragma once

#include "Sprite.h"

class Button {
public:
	Sprite Sprite;

	bool isHover(int cursorX, int cursorY);
}