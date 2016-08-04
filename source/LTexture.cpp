#include "LTexture.h"

LTexture::LTexture(){
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture(){
	//Deallocate
	free();
}

bool LTexture::loadFromFile( std::string path, SDL_Renderer* renderer ){
	free();
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if(loadedSurface == NULL ){
		printf("Unable to load image: %s. SDL_Image error: %s\n. ", path.c_str(), IMG_GetError());
	}else{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) ); //SDL_MapRGB(format,R,G,B)
		newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
		if(newTexture == NULL){
			printf("Unable to create texture from: %s. SDL_Error: %s.\n", path.c_str(), SDL_GetError());
		}else{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		SDL_FreeSurface( loadedSurface );
	}
	mTexture = newTexture;
	return mTexture != NULL;
}

void LTexture::free(){
	if(mTexture != NULL){
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::render(int x, int y,SDL_Renderer* renderer){
	SDL_Rect renderQuad = {x, y, mWidth, mHeight};
	SDL_RenderCopy( renderer, mTexture, NULL, &renderQuad );
}

int LTexture::getWidth(){
	return mWidth;
}

int LTexture::getHeight(){
	return mHeight;
}



