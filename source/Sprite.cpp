#include "Sprite.h"

Sprite::Sprite(){

}

Sprite::Sprite(Texture &source, Vec2 _position){
	texture = source;
}

Sprite::~Sprite(){
	//free();
}

void Sprite::draw(){
	SDL_RenderCopyEx(renderer, texture, NULL, &destination, angle, NULL, flip);
}

void Sprite::changeAlpha(int alpha){
	SDL_SetTextureAlphaMod(texture, alpha);
}

void Sprite::update(){
	destination.w = width;
	destination.h = height;
	if(scale){
		destination.w *= scale;
		destination.y *= scale;
	}
	destination.x = position.x;
	destination.y = position.y;
}