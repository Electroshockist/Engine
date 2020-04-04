#include "MouseEventListener.h"
#include "../../Engine/EngineMain.h"

int MouseEventListener::mouseX = 0;
int MouseEventListener::mouseY = 0;
int MouseEventListener::previousMouseX = 0;
int MouseEventListener::previousMouseY = 0;
bool MouseEventListener::firstUpdate = true;

void MouseEventListener::Update(SDL_Event e_){
	switch(e_.type){
		case SDL_MOUSEBUTTONDOWN:
			UpdateMousePosition();
			NotifyOfMousePressed(e_.button.button);
			break;
		case SDL_MOUSEBUTTONUP:
			UpdateMousePosition();
			NotifyOfMouseReleased(e_.button.button);
			break;
		case SDL_MOUSEMOTION:
			UpdateMousePosition();
			NotifyOfMouseMove();
			break;
		case SDL_MOUSEWHEEL:
			UpdateMousePosition();
			NotifyOfMouseScroll(e_.wheel.y);
			break;
		default:
			break;
	}
}

void MouseEventListener::NotifyOfMousePressed(int buttonType_){
	EngineMain::GetInstance()->notifyMousePressed(mouseX, mouseY);
}

void MouseEventListener::NotifyOfMouseReleased(int buttonType){
	EngineMain::GetInstance()->notifyMouseReleased(mouseX, mouseY, buttonType);

}

void MouseEventListener::NotifyOfMouseMove(){

	EngineMain::GetInstance()->notifyMouseMove(mouseX, mouseY);

}

void MouseEventListener::NotifyOfMouseScroll(int y){

	EngineMain::GetInstance()->notifyMouseScroll(y);

}

glm::vec2 MouseEventListener::GetPreviousMousePosition(){
	return glm::vec2(previousMouseX, previousMouseY);
}

glm::vec2 MouseEventListener::GetMousePosition(){
	return glm::vec2(mouseX, mouseY);
}

glm::vec2 MouseEventListener::GetMouseOffset(){
	return glm::vec2(mouseX - previousMouseX, previousMouseY - mouseY);
}

void MouseEventListener::UpdateMousePosition(){
	int tmpX, tmpY;
	SDL_GetMouseState(&tmpX, &tmpY);
	tmpY = EngineMain::GetInstance()->w->GetY() - tmpY;
	if(firstUpdate){
		previousMouseX = mouseX = tmpX;
		previousMouseY = mouseY = tmpY;
		firstUpdate = false;
	} else if(tmpX != mouseX || tmpY != mouseY){
		previousMouseX = mouseX;
		previousMouseY = mouseY;
		mouseX = tmpX;
		mouseY = tmpY;
	}
}