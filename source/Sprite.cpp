#include "Sprite.h"

Sprite::Sprite(){

}

Sprite::Sprite(Texture &source, Vec2 _position){
	texture = source.texture;
	width = source.width;
	height = source.height;
	this->position.x = _position.x;
	this->position.y = _position.y;
	scale = 1.0f;
}

Sprite::~Sprite(){
	//free();
	printf("Sprite Destructor called\n");
}

void Sprite::draw(){
	//SDL_RenderCopyEx(renderer, texture, NULL, &destination, angle, NULL, flip);
	SDL_RenderCopy(renderer, texture, NULL, &destination);
}

void Sprite::changeAlpha(int alpha){
	SDL_SetTextureAlphaMod(texture, alpha);
}

void Sprite::update(){
	this->destination.w = width;
	this->destination.h = height;
	if(scale != 1.0f){
		destination.w *= scale;
		destination.y *= scale;
	}
	this->destination.x = this->position.x;
	this->destination.y = this->position.y;
	/*printf("Destination x: %i\n", destination.x);
	printf("Destination y: %i\n", destination.y);
	printf("Destination width: %i\n", destination.w);
	printf("Destination height: %i\n", destination.h);*/
}