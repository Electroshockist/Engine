#include "MouseEventHandler.h"
#include "../../Engine/EngineMain.h"

int MouseEventHandler::mouseX = 0;
int MouseEventHandler::mouseY = 0;
int MouseEventHandler::previousMouseX = 0;
int MouseEventHandler::previousMouseY = 0;
bool MouseEventHandler::firstUpdate = true;

MouseEventHandler::MouseButtonEvent MouseEventHandler::mousePress = MouseEventHandler::MouseButtonEvent();
MouseEventHandler::MouseButtonEvent MouseEventHandler::mouseRelease = MouseEventHandler::MouseButtonEvent();
MouseEventHandler::MouseButtonEvent MouseEventHandler::mouseScroll = MouseEventHandler::MouseButtonEvent();
Event MouseEventHandler::mouseMove = Event();

void MouseEventHandler::Update(SDL_Event e_){
	switch(e_.type){
		case SDL_MOUSEBUTTONDOWN:
			UpdateMousePosition();
			mousePress.value = e_.button.button;
			mousePress.Notify();
			break;
		case SDL_MOUSEBUTTONUP:
			UpdateMousePosition();
			mouseRelease.value = e_.button.button;
			mouseRelease.Notify();
			break;
		case SDL_MOUSEMOTION:
			UpdateMousePosition();

			mouseMove.Notify();
			break;
		case SDL_MOUSEWHEEL:
			UpdateMousePosition();
			mouseScroll.value = e_.wheel.y;
			mouseScroll.Notify();
			break;
		default:
			break;
	}
}

glm::vec2 MouseEventHandler::GetPreviousMousePosition(){
	return glm::vec2(previousMouseX, previousMouseY);
}

glm::vec2 MouseEventHandler::GetMousePosition(){
	return glm::vec2(mouseX, mouseY);
}

glm::vec2 MouseEventHandler::GetMouseOffset(){
	return glm::vec2(mouseX - previousMouseX, previousMouseY - mouseY);
}

void MouseEventHandler::UpdateMousePosition(){
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