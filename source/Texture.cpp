#include "Texture.h"

Texture::Texture(){
	texture = 0;
	width = 0;
	height = 0;
}

Texture::Texture(const Texture &copy){
	texture = copy.texture;
	renderer = copy.renderer;
	width = copy.width;
	height = copy.height;
}
	
Texture::Texture(std::string path, SDL_Renderer* _renderer){
	if(!loadFromFile(path, _renderer)){
		printf("Texture could not be created.\n");
	}
}

Texture::~Texture(){
	free();
	printf("Texture Destructor called\n");
}

void Texture::free(){
	if(texture != 0){
		SDL_DestroyTexture(texture);
		texture = 0;
	}
}

bool Texture::loadFromFile( std::string path, SDL_Renderer* renderer ){
	free();
	SDL_Texture* newTexture = 0;

	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if(loadedSurface == NULL ){
		printf("Unable to load image: %s. SDL_Image error: %s\n. ", path.c_str(), IMG_GetError());
	}else{
		//Color key image
		//SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) ); //SDL_MapRGB(format,R,G,B)
		newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
		if(newTexture == NULL){
			printf("Unable to create texture from: %s. SDL_Error: %s.\n", path.c_str(), SDL_GetError());
		}else{
			width = loadedSurface->w;
			height = loadedSurface->h;
		}
		SDL_FreeSurface( loadedSurface );
	}
	texture = newTexture;
	SDL_DestroyTexture(newTexture);
	newTexture = 0;
	return texture != NULL;
}
