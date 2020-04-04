#ifndef ACAMERA3D_H
#define ACAMERA3D_H

#include <glm/glm.hpp>
#include "../ACamera.h"
struct ACamera3D : public ACamera{
	ACamera3D() : projection(glm::mat4()), view(glm::mat4()){}

	virtual ~ACamera3D(){}
private:
	glm::mat4 projection;
	glm::mat4 view;
};


#endif // !ACAMERA3D_H

