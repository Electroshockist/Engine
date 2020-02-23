#ifndef CAMERA_H
#define CAMERA_H

#include "ACamera.h"
//basic perspective camera
class Camera : ACamera{
	float fieldOfView;
public:
	glm::mat4 GetProjection(){
		return glm::mat4(0);
	}
};

#endif // !CAMERA_H

