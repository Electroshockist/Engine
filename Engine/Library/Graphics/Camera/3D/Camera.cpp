//#include "Camera.h"
//
//#include <glm/gtc/matrix_transform.hpp>
//#include "../../../Debugging/Debug.h"
//#include "../../../Window/AWindow.h"
//#include "../../Shader/ShaderManager.h"
//
//void Camera::SetupParameters(){
//	if(parameters.empty()){
//		Debug::warning("No material parameters exist.", __FILE__, __LINE__);
//		return;
//	}
//
//	for(Parameters::iterator it = parameters.begin(); it != parameters.end(); it++){
//		it->second.Setup(it->first);
//	}
//}
//
//void Camera::updateCameraVectors(){
//	forwardVector.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
//	forwardVector.y = sin(glm::radians(pitch));
//	forwardVector.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
//
//	forwardVector = glm::normalize(forwardVector);
//
//	rightVector = glm::normalize(glm::cross(forwardVector, worldUp));
//	upVector = glm::normalize(glm::cross(rightVector, forwardVector));
//}
//
//Camera::Camera(AWindow* w) : position(glm::vec3()), pitch(0.0f){
//	fieldOfView = 45.0f;
//	forwardVector = glm::vec3(0.0f, 0.0f, -1.0f);
//	upVector = glm::vec3(0.0f, 1.0f, 0.0f);
//	worldUp = upVector;
//	nearPlane = 2.0f;
//	farPlane = 50.0f;
//	yaw = -90.0f;
//
//	this->w = w;
//
//	getPerspective();
//	getOrthographic();
//
//	updateCameraVectors();
//
//	parameters["cameraPos"] = UniformParameter(ShaderManager::GetInstance()->getShader("basicShader"), "cameraPos", Parameter(getPosition()));
//}
//
//Camera::~Camera(){}
//
//void Camera::setPosition(glm::vec3 position){
//	this->position = position;
//}
//
//void Camera::setRotation(float yaw, float pitch){
//	this->yaw = yaw;
//	this->pitch = pitch;
//	updateCameraVectors();
//}
//
//glm::mat4 Camera::getView() const{
//	return glm::lookAt(position, position + forwardVector, upVector);
//}
//
//const glm::mat4 Camera::getPerspective(){
//	perspective = glm::perspective(fieldOfView, w->getDimensions().x / w->getDimensions().y, nearPlane, farPlane);
//	return perspective;
//}
//
//const glm::mat4 Camera::getOrthographic(){
//	orthographic = glm::ortho(0.0f, w->getDimensions().x / w->getDimensions().y, -1.0f, 1.0f);
//	return orthographic;
//}
//
//void Camera::processMouseMovement(float xOffset, float yOffset){
//	xOffset *= 0.05f;
//	yOffset *= 0.05f;
//
//	yaw += xOffset;
//	pitch += yOffset;
//
//	if(pitch > 89.0f){
//		pitch = 89.0f;
//	}
//
//	if(pitch < -89.0f){
//		pitch = -89.0f;
//	}
//
//	if(yaw > 360){
//		yaw -= 360;
//	}
//	if(yaw < 0){
//		yaw += 360;
//	}
//	updateCameraVectors();
//}
//
//void Camera::processMouseZoom(int y){
//	if(y < 0 || y>0){
//		position += static_cast<float>(y) *(forwardVector * 2.0f);
//	}
//	updateCameraVectors();
//}
//
//glm::vec3 Camera::getPosition() const{
//	return position;
//}
//
//glm::vec2 Camera::getClippingPlanes() const{
//	return glm::vec2(nearPlane, farPlane);
//}
#include "Camera.h"
#include "../../Engine/EngineMain.h"
#include "../../../Graphics/3D/Model.h"

void Camera::updateCameraVectors(){
	forwardVector.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	forwardVector.y = sin(glm::radians(pitch));
	forwardVector.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	forwardVector = glm::normalize(forwardVector);

	rightVector = glm::normalize(glm::cross(forwardVector, worldUp));
	upVector = glm::normalize(glm::cross(rightVector, forwardVector));

	frustum.updateMatrix(getPerspective(), getView());
}

Camera::Camera() : position(glm::vec3()), pitch(0.0f){
	fieldOfView = 45.0f;
	forwardVector = glm::vec3(0.0f, 0.0f, -1.0f);
	upVector = glm::vec3(0.0f, 1.0f, 0.0f);
	worldUp = upVector;
	nearPlane = 2.0f;
	farPlane = 50.0f;
	yaw = -90.0f;

	getPerspective();
	getOrthographic();

	updateCameraVectors();
}

Camera::~Camera(){}

void Camera::setPosition(glm::vec3 position){
	this->position = position;
	updateCameraVectors();
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
	perspective = glm::perspective(fieldOfView, EngineMain::GetInstance()->w->getDimensions().x / EngineMain::GetInstance()->w->getDimensions().y, nearPlane, farPlane);
	return perspective;
}

const glm::mat4 Camera::getOrthographic(){
	orthographic = glm::ortho(0.0f, EngineMain::GetInstance()->w->getDimensions().x, 0.0f, EngineMain::GetInstance()->w->getDimensions().y, -1.0f, 1.0f);
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
		position += static_cast<float>(y) * (forwardVector * 2.0f);
	}
	updateCameraVectors();
}

Frustum Camera::getFrustum() const{
	return frustum;
}

void Camera::addLightSources(LightSource * light){
	lightSources.push_back(light);
}

std::vector<LightSource*> Camera::getLightSources(){
	return lightSources;
}

glm::vec3 Camera::getPosition() const{
	return position;
}

glm::vec2 Camera::getClippingPlanes() const{
	return glm::vec2(nearPlane, farPlane);
}

Frustum::~Frustum(){}

bool Frustum::isInView(const glm::vec3& point){
	int sum = 0;
	for(auto plane : planes){
		sum += (int)classifyPoint(plane, point);
	}

	return sum == 6;
}


void Frustum::updateMatrix(glm::mat4 projMatrix, glm::mat4 viewMatrix){

	glm::mat4 matrix = projMatrix * viewMatrix;

	// Right clipping plane
	planes[Right].x = matrix[0][3] - matrix[0][0];
	planes[Right].y = matrix[1][3] - matrix[1][0];
	planes[Right].z = matrix[2][3] - matrix[2][0];
	planes[Right].w = matrix[3][3] - matrix[3][0];

	// Left clipping plane
	planes[Left].x = matrix[0][3] + matrix[0][0];
	planes[Left].y = matrix[1][3] + matrix[1][0];
	planes[Left].z = matrix[2][3] + matrix[2][0];
	planes[Left].w = matrix[3][3] + matrix[3][0];

	// Bottom clipping plane
	planes[Bottom].x = matrix[0][3] + matrix[0][1];
	planes[Bottom].y = matrix[1][3] + matrix[1][1];
	planes[Bottom].z = matrix[2][3] + matrix[2][1];
	planes[Bottom].w = matrix[3][3] + matrix[3][1];

	// Top clipping plane
	planes[Top].x = matrix[0][3] - matrix[0][1];
	planes[Top].y = matrix[1][3] - matrix[1][1];
	planes[Top].z = matrix[2][3] - matrix[2][1];
	planes[Top].w = matrix[3][3] - matrix[3][1];

	// Near clipping plane
	planes[Near].x = matrix[0][3] - matrix[0][2];
	planes[Near].y = matrix[1][3] - matrix[1][2];
	planes[Near].z = matrix[2][3] - matrix[2][2];
	planes[Near].w = matrix[3][3] - matrix[3][2];

	// Far clipping plane
	planes[Far].x = matrix[0][3] + matrix[0][2];
	planes[Far].y = matrix[1][3] + matrix[1][2];
	planes[Far].z = matrix[2][3] + matrix[2][2];
	planes[Far].w = matrix[3][3] + matrix[3][2];

	//normalize planes
	normalizePlane(planes[Left]);
	normalizePlane(planes[Right]);
	normalizePlane(planes[Top]);
	normalizePlane(planes[Bottom]);
	normalizePlane(planes[Near]);
	normalizePlane(planes[Far]);
}