#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


struct Texture {
	SDL_Texture* texture = 0;
	int width = 0;
	int height = 0;

	static void deleteTexture(Texture* texture){
		if(texture->texture != 0){
			SDL_DestroyTexture(texture->texture);
			texture->width = 0;
			texture->height = 0;
		}
	}

	static void renderTexture(SDL_Renderer* renderer, Texture* texture, int x, int y, double angle = 0.0f){
		SDL_Rect destination = {x, y, texture->width, texture->height};
		SDL_RenderCopyEx(renderer, texture->texture, 0, &destination, angle, 0, SDL_FLIP_NONE);
	}
};