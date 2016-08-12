#pragma once

#include <SDL2/SDL.h>
#include "Vec2.cpp"
#include <string>


class Sprite{
public:
	SDL_Texture* texture;
	SDL_Renderer* renderer;
	SDL_Rect destination;
	SDL_RendererFlip flip = SDL_FLIP_NONE;

	int width;
	int height;
	float scale;
	float angle;

	Vec2 position;

	Sprite();
	Sprite(const Sprite &copy);
	Sprite(std::string path, SDL_Renderer* _renderer, Vec2 _position);
	~Sprite();
	void free();

	bool loadTexture(std::string path);
	void draw();
	void update();

	void Center();
	void changeAlpha(int alpha);
};