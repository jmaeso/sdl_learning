#pragma once

#include "constants.cpp"
#include "Display.h"
#include "Sprite.h"
#include "Button.h"


class MenuScene{
public:
	SceneCode name = MENU;
	Display* display = nullptr;
	Sprite background;
	Button button;

	MenuScene(Display* _display);
	~MenuScene();
	void Draw();
	void Update();
};
