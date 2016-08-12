#pragma once

#include <SDL2/SDL.h>
#include <string>
#include "constants.cpp"

struct Display {
	int width = 0;
	int height = 0;
	std::string title;
	SDL_WindowFlags screenMode = SDL_WINDOW_SHOWN;

	SDL_Color backgroundColor = {0, 0, 0, 255};
	SDL_Window* window = 0;
	SDL_Renderer* renderer = 0;

	bool Init(std::string _title, int _width, int _height);
	void Delete();
	void Fill(SDL_Color color);
	void Clear();
	void Refresh();
	int getWidth() {return width;};
	int getHeight() {return height;};
};
