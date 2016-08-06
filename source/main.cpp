
#include <stdio.h>
#include <SDL2/SDL.h>
#include <string>
#include "App.cpp"
#include "Display.cpp"
#include "constants.cpp"


int main( int argc, char* args[] ){
	App app;
	app.initializeApp();

	Display display;
	Display::initializeDisplay(&display, std::string("Hello SDL!"), FIXED_WIDTH, FIXED_HEIGHT);

	bool quit = false;
    SDL_Event e;
    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
            else if( e.type == SDL_KEYDOWN )
            {
                //Increase alpha on w
                if( e.key.keysym.sym == SDLK_ESCAPE )
                {
                    quit = true;
                }
            }
        }
        if(&display){
        	Display::clearDisplay(&display);
        	Display::refreshWindow(&display);
    	}
    }


	Display::deleteDisplay(&display);

	app.closeApp();

	return 0;
}