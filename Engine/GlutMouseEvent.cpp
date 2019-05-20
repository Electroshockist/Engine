#include "pch.h"
#include "GlutMouseEvent.h"

string GlutMouseEvent::MOUSE_PRESSED = "mousePressed";
string GlutMouseEvent::MOUSE_MOVED = "mouseMoved";

void GlutMouseEvent::setState(int btn, int ste) {
	if (ste == GLUT_DOWN) {
		switch (btn) {
		case GLUT_LEFT_BUTTON:
			_state |= buttonLeft;
			break;
		case GLUT_RIGHT_BUTTON:
			_state |= buttonRight;
			break;
		case GLUT_MIDDLE_BUTTON:
			_state |= buttonMiddle;
			break;
		}
	}
	else if (ste == GLUT_UP) {
		switch (btn) {
		case GLUT_LEFT_BUTTON:
			_state &= ~buttonLeft;
			break;
		case GLUT_RIGHT_BUTTON:
			_state &= ~buttonRight;
			break;
		case GLUT_MIDDLE_BUTTON:
			_state &= ~buttonMiddle;
			break;
		}
	}
}

void GlutMouseEvent::setNewPos(int x, int y) {
	_currX = x;
	_currY = y;
}