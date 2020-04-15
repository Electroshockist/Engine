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
//void Camera::UpdateCameraVectors(){
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
//	GetPerspective();
//	GetOrthographic();
//
//	UpdateCameraVectors();
//
//	parameters["cameraPos"] = UniformParameter(ShaderManager::GetInstance()->getShader("basicShader"), "cameraPos", Parameter(GetPosition()));
//}
//
//Camera::~Camera(){}
//
//void Camera::SetPosition(glm::vec3 position){
//	this->position = position;
//}
//
//void Camera::SetRotation(float yaw, float pitch){
//	this->yaw = yaw;
//	this->pitch = pitch;
//	UpdateCameraVectors();
//}
//
//glm::mat4 Camera::GetView() const{
//	return glm::lookAt(position, position + forwardVector, upVector);
//}
//
//const glm::mat4 Camera::GetPerspective(){
//	perspective = glm::perspective(fieldOfView, w->getDimensions().x / w->getDimensions().y, nearPlane, farPlane);
//	return perspective;
//}
//
//const glm::mat4 Camera::GetOrthographic(){
//	orthographic = glm::ortho(0.0f, w->getDimensions().x / w->getDimensions().y, -1.0f, 1.0f);
//	return orthographic;
//}
//
//void Camera::ProcessMouseMovement(float xOffset, float yOffset){
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
//	UpdateCameraVectors();
//}
//
//void Camera::ProcessMouseZoom(int y){
//	if(y < 0 || y>0){
//		position += static_cast<float>(y) *(forwardVector * 2.0f);
//	}
//	UpdateCameraVectors();
//}
//
//glm::vec3 Camera::GetPosition() const{
//	return position;
//}
//
//glm::vec2 Camera::GetClippingPlanes() const{
//	return glm::vec2(nearPlane, farPlane);
//}


#include "Camera.h"
#include "../../Engine/EngineMain.h"
#include "../../../Graphics/3D/Model.h"

void Camera::UpdateCameraVectors(){
	forwardVector.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	forwardVector.y = sin(glm::radians(pitch));
	forwardVector.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	forwardVector = glm::normalize(forwardVector);

	rightVector = glm::normalize(glm::cross(forwardVector, worldUp));
	upVector = glm::normalize(glm::cross(rightVector, forwardVector));


	//Rotate(yaw, glm::vec3(0, 1, 0));
	//Rotate(pitch, glm::vec3(1, 0, 0));
	//Rotate(yaw, glm::vec3(0, 1, 0));

	frustum.updateMatrix(GetPerspective(), GetView());
}

Camera::Camera() : perspective(glm::mat4(1)), position(glm::vec3()), pitch(0.0f), fieldOfView(45.0f), forwardVector(glm::vec3(0.0f, 0.0f, -1.0f)), upVector(glm::vec3(0.0f, 1.0f, 0.0f)), nearPlane(0.5f), farPlane(50.0f), yaw(-90.0f){
	worldUp = upVector;

	GetPerspective();
	GetOrthographic();

	UpdateCameraVectors();
}

Camera::~Camera(){}

void Camera::SetPosition(glm::vec3 position){
	this->position = position;
	UpdateCameraVectors();
}

void Camera::SetRotation(float yaw, float pitch){
	this->yaw = yaw;
	this->pitch = pitch;
	UpdateCameraVectors();
}

glm::mat4 Camera::GetView(){
	auto view =/* GetTranslationmatrix() * GetRotationmatrix();*/glm::lookAt(position, position + forwardVector, upVector);
	return view;
}

const glm::mat4 Camera::GetPerspective(){
	const glm::vec2 & d = EngineMain::GetInstance()->w->getDimensions();
	perspective = glm::perspective(fieldOfView, d.x / d.y, nearPlane, farPlane);

	return perspective;
}

const glm::mat4 Camera::GetOrthographic(){
	const glm::vec2 & d = EngineMain::GetInstance()->w->getDimensions();
	orthographic = glm::ortho(0.0f, d.x, 0.0f, d.y, -1.0f, 1.0f);
	return orthographic;
}

void Camera::Translate(glm::vec3 translate){
	translation = glm::translate(translation, translate);
	frustum.updateMatrix(GetPerspective(), GetView());
}

void Camera::Rotate(float angle, glm::vec3 axis){
	rotation = glm::rotate(rotation, angle, axis);
	frustum.updateMatrix(GetPerspective(), GetView());
}

glm::mat4 Camera::GetRotationmatrix() const{
	return rotation;
}

glm::mat4 Camera::GetTranslationmatrix() const{
	return translation;
}

void Camera::ProcessMouseMovement(float xOffset, float yOffset){
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
	UpdateCameraVectors();
}

void Camera::ProcessMouseZoom(int y){
	if(y < 0 || y>0){
		position += static_cast<float>(y) * (forwardVector * 2.0f);
	}
	UpdateCameraVectors();
}

Frustum Camera::GetFrustum() const{
	return frustum;
}

void Camera::AddLightSources(LightSource * light){
	lightSources.push_back(light);
}

std::vector<LightSource*> Camera::GetLightSources(){
	return lightSources;
}

glm::vec3 Camera::GetPosition() const{
	return position;
}

glm::vec2 Camera::GetClippingPlanes() const{
	return glm::vec2(nearPlane, farPlane);
}