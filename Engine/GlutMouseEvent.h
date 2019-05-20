#ifndef GLUTMOUSEEVENT_H
#define GLUTMOUSEEVENT_H

#include "AMouseEvent.h"
#include <stdlib.h>
#include <Dependancies\include\glut.h>

class GlutMouseEvent : public AMouseEvent {
public:
	static string MOUSE_PRESSED;
	static string MOUSE_MOVED;

protected:
	void setState(int btn, int ste) override;

	void setNewPos(int x, int y) override;
};


//GlutMouseEvent::~GlutMouseEvent()
//{
//}
#endif