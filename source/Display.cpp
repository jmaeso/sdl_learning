#pragma once

#include <SDL2/SDL.h>
#include <string>
#include "constants.cpp"

struct Display {
	int width = 0;
	int height = 0;
	std::string title;
	bool fullScreen = false;

	SDL_Color backgroundColor = {0, 0, 0, 255};
	SDL_Window* window = 0;
	SDL_Renderer* renderer = 0;

	//METHODS
	static bool initializeDisplay(Display* handler, std::string _title, int _width, int _height) {
		bool success = true;

		handler->width = _width;
		handler->height = _height;
		handler->title = _title;
		handler->fullScreen = false;
		SDL_Color color;
		color.r = 255;
		color.g = 162;
		color.b = 0;
		color.a = 255;
		handler->backgroundColor = color;
    	handler->window = SDL_CreateWindow( "hello",//handler->title.c_str(), 
    										SDL_WINDOWPOS_CENTERED, 
    										SDL_WINDOWPOS_CENTERED, 
    										handler->width, 
    										handler->height, 
    										SDL_WINDOW_SHOWN );
    	if(handler->window == NULL){
    		printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
        	success = false;
    	}else{
    		handler->renderer = SDL_CreateRenderer(handler->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    		if( handler->renderer == NULL )
	        {
	            printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
	            success = false;
	        }else{
	        	SDL_RenderSetLogicalSize(handler->renderer, FIXED_WIDTH, FIXED_HEIGHT);
	        }
    	}
    	return success;
	}

	static void deleteDisplay(Display* display){
		if(display->renderer){
			SDL_DestroyRenderer(display->renderer);
			display->renderer = NULL;
		}
		if(display->window){
			SDL_DestroyWindow(display->window);
			display->window = NULL;
		}
	}

	static void fillDisplay(Display* handler, SDL_Color color){
		SDL_SetRenderDrawColor(handler->renderer, color.r, color.g, color.b, color.a);
		SDL_RenderClear(handler->renderer);
	}

	static void clearDisplay(Display* handler){
		fillDisplay(handler, handler->backgroundColor);
	}

	static void refreshWindow(Display* handler){
		SDL_RenderPresent(handler->renderer);
	}
};