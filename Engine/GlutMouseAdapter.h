#ifndef GLUTMOUSEADAPTER_H
#define GLUTMOUSEADAPTER_H

#include "GlutMouseEvent.h"
#include "AMouseAdapter.h"
#include "MathPrimitives.h"

#include <string>

using namespace MATH;

class GlutMouseAdapter : public AMouseAdapter {
public:
	inline static void mouseClicked(int button, int state, int x, int y) {
		//Declare a string button state
		string buttonState;

		//Set the mouse state to the button and state method parameters
		_mouse->setState(button, state);

		//Set the mouse new position to the x and y coordinate parameters
		_mouse->setNewPos(x, y);

		//If state is equal to GLUT_DOWN
		if (state == GLUT_DOWN)
			//Set the button state to Down
			buttonState = ButtonStates::Down;

		//Else
		else
			//Set the button state to Up
			buttonState = ButtonStates::Up;

		//Print output similar to mine!
		printOnButtonAction(buttonState, Vector2(x, y));
	}

	//Mouse Move Adapter Method
	inline static void mouseMoved(int x, int y)
	{
		//Set the mouse old position to be the "new" position, which is stored in _mouse
		_mouse->setOldPos(_mouse->getX(), _mouse->getY());

		//Set the new mouse position to the x and y coodinate parameters
		_mouse->setNewPos(x, y);

		//Print Mouse Drag Button

		//If _mouse button clicked is left
		if (_mouse->isLeft())

			//Print left
			printOnMove(ButtonNames::Left);

		//Else if _mouse button clicked is right
		else if (_mouse->isRight())

			//Print right
			printOnMove(ButtonNames::Right);

		//Else
		else
			//Print Middle
			printOnMove(ButtonNames::Middle);
	}
protected:
	inline static AMouseEvent* _mouse = new GlutMouseEvent();

private:
	inline static void printOnButtonAction(string buttonState,Vector2 pos) {
		cout << "Mouse button " << buttonState << " at [" << pos.x << ", " << pos.y << "]" << endl;
	}

	inline static void printOnMove(string buttonName) {
		cout << buttonName << " dragged from\n\t\t[" << _mouse->getOldX() << ", " << _mouse->getOldY() << "]\n\t\t to\n\t\t[" << _mouse->getX() << ", " << _mouse->getY() << "]\n";
	}

};
#endif
