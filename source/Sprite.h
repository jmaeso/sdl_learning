#pragma once

#include <SDL2/SDL.h>
#include "Vec2.cpp"
#include "Texture.h"


class Sprite : public Texture {
public:
	SDL_Rect destination;

	float scale = 0.0f;
	float angle = 0.0f;
	Vec2 position;
	SDL_RendererFlip flip = SDL_FLIP_NONE;

	Sprite();
	Sprite(Texture &_texture, Vec2 _position);
	virtual ~Sprite();

	void draw();
	void changeAlpha(int alpha);
	void update();
};