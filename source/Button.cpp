#include "Button.h"

Button::Button(){
}

Button::Button(Display* display,Sprite sprite){

}

bool Button::isHover(Vec2 cursorPosition){

}

void Button::Draw(){
  SDL_SetRenderDrawColor(display->renderer, buttonColor.r, buttonColor.g, buttonColor.b, buttonColor.a);
  SDL_RenderFillRect(display->renderer, &rect);
}

void Button::Update(){
  rect = {position.x, position.y, width, height};
}
