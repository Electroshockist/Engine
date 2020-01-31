#ifndef AMOUSEADAPTER_H
#define AMOUSEADAPTER_H

#include <type_traits>
#include <iostream>

#include "MouseEvent.h"

using namespace std;

class MouseAdapter {
public:

	inline static string MOUSE_PRESSED = "mousePressed";
	inline static string MOUSE_MOVED = "mouseMoved";

	inline static void MouseClicked(int button, int state, int x, int y) {

		//Set the mouse state to the button and state method parameters
		Input::Button tempButton = _mouse->GetState(button, state);

		//Set the mouse new position to the x and y coordinate parameters
		_mouse->SetNewPos(x, y);

		//Print output similar to mine!
		PrintOnButtonAction(tempButton.getName(), tempButton.state ? "Down" : "Up", glm::vec2(x, y));
	}

	//Mouse Move Adapter Method
	inline static void MouseMoved(int x, int y) {

		//Set the mouse old position to be the "new" position, which is stored in _mouse
		_mouse->setOldPos(_mouse->getX(), _mouse->getY());

		//Set the new mouse position to the x and y coodinate parameters
		_mouse->SetNewPos(x, y);

		//Print Mouse Drag Button

		//If _mouse button clicked is left
		if (_mouse->isLeft())

			//Print left
			PrintOnMove(Input::Mouse::Left.getName());

		//Else if _mouse button clicked is right
		else if (_mouse->isRight())

			//Print right
			PrintOnMove(Input::Mouse::Right.getName());

		//Else
		else
			//Print Middle
			PrintOnMove(Input::Mouse::Middle.getName());
	}

protected:
	inline static MouseEvent* _mouse = new MouseEvent();

	inline static void PrintOnButtonAction(string buttonName, string buttonState, glm::vec2 pos) {
		cout << buttonName << " " << buttonState << " at [" << pos.x << ", " << pos.y << "]" << endl;
	}

	inline static void PrintOnMove(string buttonName) {
		cout << buttonName << " dragged from\n\t\t[" << _mouse->getOldX() << ", " << _mouse->getOldY() << "]\n\t\t to\n\t\t[" << _mouse->getX() << ", " << _mouse->getY() << "]\n";
	}

};

#endif
