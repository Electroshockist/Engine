#pragma once
#include "ITransformable2D.h"
#include "ITransformable3D.h"

///transformable factory struct
struct ITransformable {
	static ITransformable2D rotatableFactory(MATH::Vector2 position, float rotation, MATH::Vector2 anchorPoint) {
		return ITransformable2D(position, rotation, anchorPoint);
	}

	static ITransformable3D rotatableFactory(MATH::Vector3 position, MATH::Vector3 rotation, MATH::Vector3 anchorPoint) {
		return ITransformable3D(position, rotation, anchorPoint);
	}
};
