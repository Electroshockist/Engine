#ifndef ITRANSFORMABLE3D_H
#define ITRANSFORMABLE3D_H

#include "ITranslatable3D.h"
#include "IRotatable3D.h"

struct ITransformable3D : public ITranslatable3D, public IRotatable3D {
	ITransformable3D(){}
	ITransformable3D(glm::vec3 position, glm::vec3 rotation, glm::vec3 anchorPoint);
};
#endif // !ITRANSFORMABLE3D_H

