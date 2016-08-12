#ifdef _WIN32
	#pragma comment(lib,"SDL2.lib")
	#pragma comment(lib,"SDL2_image.lib")
	#pragma comment(lib,"SDL2_ttf.lib")
	#pragma comment(lib,"SDL2_mixer.lib")
	#pragma comment(lib,"SDL2main.lib")
#endif // _WIN32

#include <stdio.h>
#include <string>
#include "App.h"
#include "Display.h"
#include "constants.cpp"
#include "Sprite.h"
#include "Vec2.cpp"


int main( int argc, char* args[] ){

	initializeApp();

	Display display;
	display.Init(std::string("Hello SDL!"), 400, 400); 

	bool quit = false;

	//Texture texture(std::string("../resources/image.bmp"), display.renderer);
	Vec2 position{0, 0};

	Sprite bg(std::string("../resources/image.png"), &display, position);
    bg.Center(); 
    

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
    	bg.update(); //Sprite update
        if(&display){
        	display.Clear();
        	bg.draw(); //Sprite render
        	display.Refresh();
    	}
    }

	display.Delete();

	closeApp();

	return 0;
}
