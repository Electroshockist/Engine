//#ifndef CAMERA_H
//#define CAMERA_H
//
//#include <glm/glm.hpp>
//
//#include "ACamera3D.h"
//#include "../../3D/UniformParameter.h"
//
////basic opengl perspective camera
//struct Camera : ACamera3D{
//	glm::vec3 position;
//	glm::mat4 perspective, orthographic;
//	float fieldOfView;
//	float yaw, pitch;
//	float nearPlane, farPlane;
//	glm::vec3 forwardVector, upVector, rightVector, worldUp;
//	void UpdateCameraVectors();
//	void SetupParameters();
//
//	class AWindow *w;
//
//public:
//	Camera(AWindow* w);
//	~Camera();
//
//	Parameters parameters;
//
//	void SetPosition(glm::vec3 position);
//	void SetRotation(float yaw, float pitch);
//	glm::mat4 GetView() const;
//	const glm::mat4 GetPerspective();
//	const glm::mat4 GetOrthographic();
//
//	void ProcessMouseMovement(float xOffset, float yOffset);
//	void ProcessMouseZoom(int y);
//
//
//	glm::vec3 GetPosition() const;
//
//	glm::vec2 GetClippingPlanes() const;
//};
//
//#endif // !CAMERA_H
//
#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

#include "../../../Effects/LightSource.h"
#include "Frustum.h"
#include "../../../GameObject/AComponent.h"

class Model;

class Camera: public AComponent{
	friend class SkyBox;
	glm::vec3 position;
	glm::mat4 perspective, orthographic;
	glm::mat4 translation, rotation;

	float fieldOfView;
	float yaw, pitch;
	float nearPlane, farPlane;
	//glm::vec3 forwardVector, upVector, rightVector, worldUp;
	std::vector<LightSource*> lightSources;

	Frustum frustum;
public:
	Camera();
	~Camera();

	glm::vec2 sensitivity;

	//void SetPosition(glm::vec3 position);
	void SetRotation(float yaw, float pitch);
	glm::mat4 GetView();
	const glm::mat4 GetPerspective();
	const glm::mat4 GetOrthographic();

	void Translate(glm::vec3 translate);

	glm::vec3 GetForwardVector();

	//void Rotate(float angle, glm::vec3 axis);

	glm::mat4 GetRotationmatrix() const;
	glm::mat4 GetTranslationmatrix() const;

	void ProcessMouseMovement(float xOffset, float yOffset);
	void ProcessMouseZoom(int y);

	Frustum GetFrustum() const;

	void AddLightSources(LightSource* light);
	std::vector<LightSource*> GetLightSources();

	glm::vec3 GetPosition() const;

	glm::vec2 GetClippingPlanes() const;
};
#endif // !CAMERA_H

