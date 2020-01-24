#ifndef ACAMERA_H
#define ACAMERA_H

#include<glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct ACamera{

	inline void SetPosition(glm::vec3 position){
		this->position = position;
	}

	inline void SetRotation(float yaw, float pitch){
		this->yaw = yaw;
		this->pitch = pitch;
		UpdateVectors();
	}

	inline glm::mat4 GetView() const{
		return glm::lookAt(position, position + forwardVector, upVector);
	}

	virtual glm::mat4 GetProjection() = 0;

protected:
	virtual void OnUpdateVectors(){}

private:
	glm::vec3 position;
	float yaw, pitch, roll;
	glm::vec3 forwardVector, upVector, rightVector, worldUp;
	glm::mat4 projection;

	inline void UpdateVectors(){
		forwardVector.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		forwardVector.y = sin(glm::radians(pitch));
		forwardVector.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

		forwardVector = glm::normalize(forwardVector);

		rightVector = glm::normalize(glm::cross(forwardVector, worldUp));
		upVector = glm::normalize(glm::cross(rightVector, forwardVector));

		OnUpdateVectors();
	}
};
#endif // !ACAMERA_H
