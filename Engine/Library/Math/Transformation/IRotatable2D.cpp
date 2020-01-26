#include "IRotatable2D.h"

IRotatable2D::IRotatable2D(float rotation, glm::vec2 anchorPoint) {
	rotate(rotation);
}

void IRotatable2D::Rotate(float rotation) {
	this->rotation += rotation;
}
