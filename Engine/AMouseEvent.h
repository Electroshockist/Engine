#ifndef AMOUSEEVENT_H
#define AMOUSEEVENT_H

#include "AEvent.h"

#include <string>
using namespace std;

class AMouseEvent : public AEvent {
public:
	AMouseEvent() {
		_oldX = -1;
		_oldY = -1;
		_currX = -1;
		_currY = -1;
		_state = 0;
	}

	virtual void setState(int btn, int ste = 0) = 0;
	virtual void setNewPos(int x, int y) = 0;

	int isLeft() const {
		return (_state & buttonLeft);
	}

	int isRight() const {
		return (_state & buttonRight);
	}

	int isMiddle() const {
		return (_state & buttonMiddle);
	}

	void reset() {
		_state = 0;
	}

	int getOldX() const {
		return _oldX;
	}

	int getOldY() const {
		return _oldY;
	}

	int getX() const {
		return _currX;
	}

	int getY() const {
		return _currY;
	}

	int getDiffX(int x) const {
		return x - _oldX;
	}

	int getDiffY(int y) const {
		return y - _oldY;
	}

	int getDiffX() const {
		return _currX - _oldX;
	}

	int getDiffY() const {
		return _currY - _oldY;
	}

	void setOldPos(int x, int y) {
		_oldX = x;
		_oldY = y;
	}

	//virtual ~AMouseEvent();

protected:
	enum {
		buttonLeft = 1,
		buttonRight = 2,
		buttonMiddle = 4,
	};

	int _state;
	int _oldX;
	int _oldY;
	int _currX;
	int _currY;
};
#endif
