#ifndef AMOUSEEVENT_H
#define AMOUSEEVENT_H

#include "../Data Structures/Events/Event.h"
#include "Input.h"
#include "../Math/MathPrimitives.h"

#include <string>

using namespace MATH;

class MouseEvent  {
protected:
	Vector2 oldPos;

public:
	inline static string MOUSE_PRESSED = "mousePressed";
	inline static string MOUSE_MOVED = "mouseMoved";

	MouseEvent() {
		setOldPos(-1, -1);
		Input::Mouse::PosX.value = -1;
		Input::Mouse::PosY.value = -1;
	}

	inline static Input::Button getState(int button, int glutState) {
		bool state = (glutState == GLUT_DOWN ? true : false);

		switch (button) {
			case GLUT_LEFT_BUTTON:
				Input::Mouse::Left.state = state;
				return Input::Mouse::Left;
				break;
			case GLUT_RIGHT_BUTTON:
				Input::Mouse::Right.state = state;
				return Input::Mouse::Right;
				break;
			case GLUT_MIDDLE_BUTTON:
				Input::Mouse::Middle.state = state;
				return Input::Mouse::Middle;
				break;
		}
	}

	inline void setNewPos(int x, int y) {
		Input::Mouse::PosX.value = x;
		Input::Mouse::PosY.value = y;
	}

	bool isLeft() const {
		return Input::Mouse::Left.state;
	}

	bool isRight() const {
		return Input::Mouse::Right.state;
	}

	bool isMiddle() const {
		return Input::Mouse::Middle.state;
	}

	void reset() {
		Input::Mouse::Left.state = false;
		Input::Mouse::Right.state = false;
		Input::Mouse::Middle.state = false;
	}

	int getOldX() const {
		return oldPos.x;
	}

	int getOldY() const {
		return oldPos.y;
	}

	int getX() const {
		return Input::Mouse::PosX.value;
	}

	int getY() const {
		return Input::Mouse::PosY.value;
	}

	int getDiffX(int x) const {
		return x - oldPos.x;
	}

	int getDiffY(int y) const {
		return y - oldPos.y;
	}

	int getDiffX() const {
		return Input::Mouse::PosX.value - oldPos.x;
	}

	int getDiffY() const {
		return Input::Mouse::PosY.value - oldPos.y;
	}

	void setOldPos(int x, int y) {
		oldPos = Vector2(x, y);
	}

	~MouseEvent() {}
};
#endif
