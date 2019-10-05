#include "IRotatable2D.h"

IRotatable2D::IRotatable2D(float rotation, MATH::Vector2  anchorPoint) {
	rotate(rotation);
}

void IRotatable2D::rotate(float rotation) {
	this->rotation += rotation;
}
