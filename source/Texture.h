#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Texture {
public:
	SDL_Texture* texture;
	SDL_Renderer* renderer;
	int width;
	int height;

	Texture();
	Texture(const Texture &copy);
	Texture(std::string path, SDL_Renderer* _renderer); 
	~Texture();
	void free();
	bool loadFromFile( std::string path, SDL_Renderer* renderer );
};