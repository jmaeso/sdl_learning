#pragma once

#include <string>
#include "Sprite.h"
#include "SDL2/SDL_TTF.h"

class Button {
public:
	Sprite sprite;
	SDL_Rect rect;
	SDL_Color buttonColor;
	SDL_Color textColor;
	std::string text;

	Button();
	Button(int x, int y, int width, int height, SDL_Color color);
	Button(int x, int y, Sprite sprite);


	bool isHover(int cursorX, int cursorY);
}
