#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include "ACamera3D.h"
//basic perspective camera
class Camera : ACamera3D{
	float fieldOfView;
public:
	glm::mat4 GetProjection(){
		return glm::mat4(0);
	}
};

#endif // !CAMERA_H

