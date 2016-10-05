#pragma once

#include <string>
#include "Sprite.h"
#include "SDL2/SDL_ttf.h"
#include "Vec2.h"

class Button {
public:
	Display* display = nullptr;
	Sprite* sprite = nullptr;
	SDL_Rect rect;
	SDL_Color buttonColor = {255, 255, 255, 255};
	SDL_Color textColor = {0, 0, 0, 255};
	std::string text;
	Vec2 position = {0, 0};
	int width = 10;
	int height = 10;

	Button();
	Button(Display* display, Sprite sprite);

	bool isHover(Vec2 cursorPosition);
	void Draw();
	void Update();
};
