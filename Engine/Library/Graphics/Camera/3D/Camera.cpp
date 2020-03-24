#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include "../../../Debugging/Debug.h"
#include "../../../Window/AWindow.h"
#include "../../Shader/ShaderManager.h"

void Camera::SetupParameters(){
	if(parameters.empty()){
		Debug::warning("No material parameters exist.", __FILE__, __LINE__);
		return;
	}

	for(Parameters::iterator it = parameters.begin(); it != parameters.end(); it++){
		it->second.Setup(it->first);
	}
}

void Camera::updateCameraVectors(){
	forwardVector.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	forwardVector.y = sin(glm::radians(pitch));
	forwardVector.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	forwardVector = glm::normalize(forwardVector);

	rightVector = glm::normalize(glm::cross(forwardVector, worldUp));
	upVector = glm::normalize(glm::cross(rightVector, forwardVector));
}

Camera::Camera(AWindow* w) : position(glm::vec3()), pitch(0.0f){
	fieldOfView = 45.0f;
	forwardVector = glm::vec3(0.0f, 0.0f, -1.0f);
	upVector = glm::vec3(0.0f, 1.0f, 0.0f);
	worldUp = upVector;
	nearPlane = 2.0f;
	farPlane = 50.0f;
	yaw = -90.0f;

	this->w = w;

	getPerspective();
	getOrthographic();

	updateCameraVectors();

	parameters["cameraPos"] = UniformParameter(ShaderManager::getInstance()->getShader("basicShader"), "cameraPos", Parameter(getPosition()));
}

Camera::~Camera(){}

void Camera::setPosition(glm::vec3 position){
	this->position = position;
}

void Camera::setRotation(float yaw, float pitch){
	this->yaw = yaw;
	this->pitch = pitch;
	updateCameraVectors();
}

glm::mat4 Camera::getView() const{
	return glm::lookAt(position, position + forwardVector, upVector);
}

const glm::mat4 Camera::getPerspective(){
	perspective = glm::perspective(fieldOfView, w->getDimensions().x / w->getDimensions().y, nearPlane, farPlane);
	return perspective;
}

const glm::mat4 Camera::getOrthographic(){
	orthographic = glm::ortho(0.0f, w->getDimensions().x / w->getDimensions().y, -1.0f, 1.0f);
	return orthographic;
}

void Camera::processMouseMovement(float xOffset, float yOffset){
	xOffset *= 0.05f;
	yOffset *= 0.05f;

	yaw += xOffset;
	pitch += yOffset;

	if(pitch > 89.0f){
		pitch = 89.0f;
	}

	if(pitch < -89.0f){
		pitch = -89.0f;
	}

	if(yaw > 360){
		yaw -= 360;
	}
	if(yaw < 0){
		yaw += 360;
	}
	updateCameraVectors();
}

void Camera::processMouseZoom(int y){
	if(y < 0 || y>0){
		position += static_cast<float>(y) *(forwardVector * 2.0f);
	}
	updateCameraVectors();
}

glm::vec3 Camera::getPosition() const{
	return position;
}

glm::vec2 Camera::getClippingPlanes() const{
	return glm::vec2(nearPlane, farPlane);
}
