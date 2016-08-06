
#include <SDL2/SDL2.h>
#include <string.h>

struct Display {
	int width = 0;
	int height = 0;
	const char *title = NULL;
	bool fullScreen = false;

	SDL_Color backgroundColor = {0, 0, 0, 255};
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	bool initializeDisplay(std::string _title, int _width, int _height) {
		bool success = true;
    	window = SDL_CreateWindow( _title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_SHOWN );
    	if(window = NULL){
    		printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
        	success = false;
    	}else{
    		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PREVENTVSYNC);
    		if( renderer == NULL )
	        {
	            printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
	            success = false;
	        }else{
	        	
	        }
    	}
	}
}