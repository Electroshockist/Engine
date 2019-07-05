#pragma once
#include "IRotatable2D.h"
#include "IRotatable3D.h"

///rotatable factory struct
struct IRotatable {
	static IRotatable2D rotatableFactory(float rotation, MATH::Vector2 anchorPoint) {
		return IRotatable2D(rotation, anchorPoint);
	}

	static IRotatable3D rotatableFactory(MATH::Vector3 rotation, MATH::Vector3 anchorPoint) {
		return IRotatable3D(rotation, anchorPoint);
	}
};
