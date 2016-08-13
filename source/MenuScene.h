#pragma once

#include "constants.cpp"
#include "Sprite.h"
#include "Display.h"

class MenuScene{
public:
	SceneCode name = MENU;
	Display* display = nullptr;
	Sprite background;

	MenuScene(Display* _display);
	~MenuScene();
	void Draw();
	void Update();
};