#include "Sprite.h"

Sprite::Sprite(){

}

Sprite::Sprite(Texture &source, Vec2 _position){
	texture = source.texture;
	position.x = _position.x;
	position.y = _position.y;
	scale = 1.0f;
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
		//destination.w *= scale;
		//destination.y *= scale;
	}
	destination.x = this->position.x;
	destination.y = this->position.y;
	printf("Destination x: %i\n", destination.x);
	printf("Destination y: %i\n", destination.y);
}