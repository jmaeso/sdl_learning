#include "MenuScene.h"
#include <string>
#include "Vec2.h"

MenuScene::MenuScene(Display* _display){
	display = _display;
	background.display = _display;
	background.SetTexture(std::string("../resources/image.png"));
	background.Center();

	button.display = _display;
	button.width = 400;
	button.height = 75;
	button.position = {(_display->width/2) - (button.width/2), (int)(_display->height * 0.85f)};
}

MenuScene::~MenuScene(){

}

void MenuScene::Update(){
	background.Update();
	button.Update();
}

void MenuScene::Draw(){
	background.Draw();
	button.Draw();
}
