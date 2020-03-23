#include "Camera.h"

#include "../../../Debugging/Debug.h"

void Camera::SetupParameters(){
	if(parameters.empty()){
		Debug::warning("No material parameters exist.", __FILE__, __LINE__);
		return;
	}

	for(Parameters::iterator it = parameters.begin(); it != parameters.end(); it++){
		it->second.Setup(it->first);
	}
}

glm::mat4 Camera::GetProjection(){
	return glm::mat4();
}

bool Camera::isImplemented(){
	return true;
}
