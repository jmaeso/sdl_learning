#include "MenuScene.h"
#include "Vec2.h"

MenuScene::MenuScene(Display* _display) : background(std::string("../resources/image.png"), _display){
	display = _display;
	//Vec2 position{0, 0};
	//background(std::string("../resources/image.png"), &display, position);
	background.Center();
}

MenuScene::~MenuScene(){

}

void MenuScene::Update(){
	background.Update();
}

void MenuScene::Draw(){
	background.Draw();

}