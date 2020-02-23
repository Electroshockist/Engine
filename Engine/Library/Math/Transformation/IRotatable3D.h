#ifndef IROTATABLE_3D
#define IROTATABLE_3D

#include <glm/glm.hpp>
struct IRotatable3D {
	IRotatable3D():rotationQuaternion(glm::vec4()){}
	IRotatable3D(glm::vec3 rotation, glm::vec3 anchorPoint);
	~IRotatable3D();

private:
	glm::vec4 rotationQuaternion;
};
#endif //!IROTATABLE_3D

