#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

#include "ACamera3D.h"
#include "../../3D/UniformParameter.h"

//basic opengl perspective camera
struct Camera : ACamera3D{
	void SetupParameters();
	glm::mat4 GetProjection();

	bool isImplemented() override;
private:
	float fieldOfView;
	Parameters parameters;
};

#endif // !CAMERA_H

