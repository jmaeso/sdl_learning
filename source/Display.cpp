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

	//METHODS
	static bool initializeDisplay(Display* handler, std::string _title, int _width, int _height) {
		bool success = true;
		SDL_DisplayMode current;
		int should_be_zero = SDL_GetCurrentDisplayMode(0, &current);
	    if(should_be_zero != 0)
		    printf("Could not get display mode for video display #%d: %s", 0, SDL_GetError());
	    else{
	    	handler->width = (DEFAULT_WIDTH == _width) ? current.w : _width;
	    	handler->height = (DEFAULT_HEIGHT == _height) ? current.h : _height;
	    	handler->screenMode = ((DEFAULT_WIDTH == _width) && (DEFAULT_HEIGHT == _height)) ? SDL_WINDOW_FULLSCREEN_DESKTOP : SDL_WINDOW_SHOWN;
	    }
		handler->title = _title;
		SDL_Color color = {.r = 255, .g = 162, .b = 0, .a = 255};
		handler->backgroundColor = color;
    	handler->window = SDL_CreateWindow( handler->title.c_str(), 
    										SDL_WINDOWPOS_CENTERED, 
    										SDL_WINDOWPOS_CENTERED, 
    										handler->width, 
    										handler->height, 
    										handler->screenMode );
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