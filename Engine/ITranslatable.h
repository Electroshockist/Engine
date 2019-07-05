#pragma once
#include "ITranslatable2D.h"
#include "ITranslatable3D.h"

///translatable factory struct
struct ITranslatable {
	static ITranslatable2D rotatableFactory(MATH::Vector2 position) {
		return ITranslatable2D(position);
	}

	static ITranslatable3D rotatableFactory(MATH::Vector3 position) {
		return ITranslatable3D(position);
	}
};