#pragma once

#include <SDL2/SDL.h>
#include "Vec2.h"
#include <string>
#include "Display.h"


class Sprite{
public:
	SDL_Texture* texture;
	Display* display;
	SDL_Rect destination;
	SDL_RendererFlip flip = SDL_FLIP_NONE;

	int width;
	int height;
	float scale;
	float angle;

	Vec2 position;

	Sprite();
	Sprite(const Sprite &copy);
	Sprite(std::string path, Display* _display);
	~Sprite();
	void free();

	bool loadTexture(std::string path);
	void Draw();
	void Update();

	void Center();
	void CenterX();
	void CenterY();
	void SnapRight();
	void SnapLeft();
	void changeAlpha(int alpha);
};