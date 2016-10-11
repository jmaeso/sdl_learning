#pragma once

#include <SDL2/SDL.h>
#include "Vec2.h"
#include <string>
#include "Display.h"


class Sprite{
public:
	SDL_Texture* texture = nullptr;
	Display* display = nullptr;
	SDL_Rect destination;
	SDL_RendererFlip flip = SDL_FLIP_NONE;

	int width = 0;
	int height = 0;
	float scale = 1.0f;
	float angle = 0.0f;

	Vec2 position = {0, 0};

	Sprite();
	Sprite(const Sprite &copy);
	Sprite(Display* _display, std::string path);
	~Sprite();
	void free();

	bool loadTexture(std::string path);
	void Draw();
	void Update();
	void SetTexture(std::string path);

	void Center();
	void CenterX();
	void CenterY();
	void SnapRight();
	void SnapLeft();
	void changeAlpha(int alpha);
};
