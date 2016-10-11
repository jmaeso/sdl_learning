#include "MenuScene.h"
#include <string>
#include "Vec2.h"

MenuScene::MenuScene(Display* _display){
	display = _display;
	background.display = _display;
	background.SetTexture(std::string("../resources/image.png"));
	background.Center();

	button.display = _display;
	button.position = {200, 200};
	button.width = 100;
	button.height = 25;
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
