#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

#include "ACamera3D.h"
#include "../../3D/UniformParameter.h"

//basic opengl perspective camera
class Camera : ACamera3D{
	float fieldOfView;
	Parameters parameters;

public:
	void SetupParameters();

	glm::mat4 GetProjection();
};

#endif // !CAMERA_H

