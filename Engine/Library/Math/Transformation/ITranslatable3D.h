#ifndef ITRANSLATABLE_3D
#define ITRANSLATABLE_3D

#include "../MathPrimitives.h"

struct ITranslatable3D {
	MATH::Vector3 position;
	ITranslatable3D(MATH::Vector3 position);
};
#endif //!ITRANSLATABLE_3D
