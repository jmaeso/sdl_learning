#include "Display.h"

//METHODS
bool Display::Init(std::string _title, int _width, int _height) {
	bool success = true;
	SDL_DisplayMode current; 
	int should_be_zero = SDL_GetCurrentDisplayMode(0, &current); 
    if(should_be_zero != 0)
	    printf("Could not get display mode for video display #%d: %s", 0, SDL_GetError());
    else{
    	this->width = (DEFAULT_WIDTH == _width) ? current.w : _width;
    	this->height = (DEFAULT_HEIGHT == _height) ? current.h : _height;
    	this->screenMode = ((DEFAULT_WIDTH == _width) && (DEFAULT_HEIGHT == _height)) ? SDL_WINDOW_FULLSCREEN_DESKTOP : SDL_WINDOW_SHOWN;
    }
	this->title = _title;
	SDL_Color color = {255, 165, 0, 255};
	this->backgroundColor = color;
	this->window = SDL_CreateWindow( this->title.c_str(),
										SDL_WINDOWPOS_CENTERED, 
										SDL_WINDOWPOS_CENTERED, 
										this->width, 
										this->height, 
										this->screenMode );
	if(this->window == NULL){
		printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
    	success = false;
	}else{
		this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if( this->renderer == NULL )
        {
            printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }else{
        	SDL_RenderSetLogicalSize(this->renderer, this->width, this->height);
        	//SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        }
	}
	return success;
}

void Display::Delete(){
	if(this->renderer){
		SDL_DestroyRenderer(this->renderer);
		this->renderer = NULL;
	}
	if(this->window){
		SDL_DestroyWindow(this->window);
		this->window = NULL;
	}
}

void Display::Fill(SDL_Color color){
	SDL_SetRenderDrawColor(this->renderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(this->renderer);
}

void Display::Clear(){
	Fill(this->backgroundColor);
}

void Display::Refresh(){
	SDL_RenderPresent(this->renderer);
}
