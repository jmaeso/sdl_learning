
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <cstdio>

struct App {
	bool initializeApp() {
		bool success = true;

		if(SDL_Init(0) != 0){
			printf("Couldn't start SDL. Error: %s\n", SDL_GetError());
			success = false;
		}else{
			int flags = (SDL_INIT_VIDEO | SDL_INIT_TIMER);
			if(SDL_InitSubSystem(flags) != 0){
				printf("SDL could not initialize subsystems. Error: %s\n", SDL_GetError());
				success = false;
			}

			int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) )
            {
                printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                success = false;
            }

            if(TTF_Init() == -1){
            	printf("SDL_TTF could not initialize. SDL_TTF Error: %s\n", TTF_GetError());
            	success = false;
            }
            if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ){
    			printf("SDL_mixer could not initialize. SDL_mixer Error: %s\n", Mix_GetError());
    			success = false;
    		}
		}
		return success;
	}

	void closeApp() {
		Mix_Quit();
		TTF_Quit();
		IMG_Quit();
		SDL_Quit();
	}
};
