#ifndef ITRANSFORMABLE3D_H
#define ITRANSFORMABLE3D_H

#include "ITranslatable3D.h"
#include "IRotatable3D.h"

struct ITransformable3D : public ITranslatable3D, public IRotatable3D {
	ITransformable3D(MATH::Vector3 position, MATH::Vector3 rotation, MATH::Vector3 anchorPoint);
};
#endif // !ITRANSFORMABLE3D_H
