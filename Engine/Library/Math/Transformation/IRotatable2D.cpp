#include "IRotatable2D.h"

IRotatable2D::IRotatable2D(float rotation, glm::vec2 anchorPoint) {
	Rotate(rotation);
}

void IRotatable2D::Rotate(float rotation) {
	this->rotation += rotation;
}
