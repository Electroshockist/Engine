#ifndef IROTATABLE_3D
#define IROTATABLE_3D

#include "../MathPrimitives.h"
struct IRotatable3D {
	IRotatable3D(MATH::Vector3 rotation, MATH::Vector3 anchorPoint);
	~IRotatable3D();

private:
	MATH::Quaternion rotationQuaternion;
};
#endif //!IROTATABLE_3D
