#ifdef _WIN32
	#pragma comment(lib,"SDL2.lib")
	#pragma comment(lib,"SDL2_image.lib")
	#pragma comment(lib,"SDL2_ttf.lib")
	#pragma comment(lib,"SDL2_mixer.lib")
	#pragma comment(lib,"SDL2main.lib")
#endif // _WIN32

#include <stdio.h>
#include <SDL2/SDL.h>
#include <string>
#include "App.cpp"
#include "Display.cpp"
#include "constants.cpp"
#include "Texture.h"
#include "Sprite.h"
#include "Vec2.cpp"


int main( int argc, char* args[] ){
	App app;
	app.initializeApp();

	Display display;
	Display::initializeDisplay(&display, std::string("Hello SDL!"), DEFAULT_WIDTH, DEFAULT_HEIGHT);

	bool quit = false;

	Texture t(std::string("../resources/image.bmp"), display.renderer);
	Vec2 position;
	Sprite bg(t, position);

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
        bg.update();
        if(&display){
        	Display::clearDisplay(&display);
        	bg.draw();
        	Display::refreshWindow(&display);
    	}
    }


	Display::deleteDisplay(&display);

	app.closeApp();

	return 0;
}
