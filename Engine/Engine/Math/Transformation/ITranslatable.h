#ifndef ITRANSLATABLE_H
#define ITRANSLATABLE_H

#include "ITranslatable2D.h"
#include "ITranslatable3D.h"

//translatable factory struct
struct ITranslatable {
	static ITranslatable2D rotatable(MATH::Vector2 position) {
		return ITranslatable2D(position);
	}

	static ITranslatable3D rotatable(MATH::Vector3 position) {
		return ITranslatable3D(position);
	}
};
#endif // !ITRANSLATABLE_H