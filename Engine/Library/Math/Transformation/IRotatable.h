#ifndef IROTATABLE_H
#define IROTATABLE_H

#include "IRotatable2D.h"
#include "IRotatable3D.h"

///rotatable factory struct
struct IRotatable {
	static IRotatable2D rotatableFactory(float rotation, glm::vec2 anchorPoint) {
		return IRotatable2D(rotation, anchorPoint);
	}

	static IRotatable3D rotatableFactory(glm::vec3 rotation, glm::vec3 anchorPoint) {
		return IRotatable3D(rotation, anchorPoint);
	}
};
#endif // !IROTATABLE_H
