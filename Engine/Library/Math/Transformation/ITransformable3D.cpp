#include "ITransformable3D.h"

ITransformable3D::ITransformable3D(glm::vec3 position, glm::vec3 rotation, glm::vec3 anchorPoint) :
	ITranslatable3D(position),
	IRotatable3D(rotation, anchorPoint) {}
