#ifndef ACAMERA3D_H
#define ACAMERA3D_H

#include "../ACamera.h"
#include "../../../Math/Transformation/ITransformable3D.h"
class ACamera3D : public ACamera, public ITransformable3D{
	glm::mat4 projection;
	glm::mat4 view;
public:
	ACamera3D() : projection(glm::mat4()), view(glm::mat4()){}

	~ACamera3D(){}
};


#endif // !ACAMERA3D_H

