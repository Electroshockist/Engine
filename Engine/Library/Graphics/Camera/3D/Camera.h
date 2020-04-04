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
//	void updateCameraVectors();
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
//	void setPosition(glm::vec3 position);
//	void setRotation(float yaw, float pitch);
//	glm::mat4 getView() const;
//	const glm::mat4 getPerspective();
//	const glm::mat4 getOrthographic();
//
//	void processMouseMovement(float xOffset, float yOffset);
//	void processMouseZoom(int y);
//
//
//	glm::vec3 getPosition() const;
//
//	glm::vec2 getClippingPlanes() const;
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

class Model;
class Frustum{
	friend class Camera;
	glm::vec4 planes[6];

	enum Halfspace{
		NEGATIVE = -1,
		ON_PLANE = 0,
		POSITIVE = 1
	};

	inline Halfspace classifyPoint(const glm::vec4 & plane, const glm::vec3 & point){
		float d;
		d = plane.x * point.x + plane.y * point.y + plane.z * point.z + plane.w;
		if(d < 0) return NEGATIVE;
		if(d > 0) return POSITIVE;
		return ON_PLANE;
	}

	void updateMatrix(glm::mat4 projMatrix, glm::mat4 viewMatrix);

	void normalizePlane(glm::vec4& plane){
		double magnitude = glm::sqrt(
			plane.x * plane.x +
			plane.y * plane.y +
			plane.z * plane.z
		);

		plane.x /= magnitude;
		plane.y /= magnitude;
		plane.z /= magnitude;
		plane.w /= magnitude;
	}

public:
	Frustum(){}
	~Frustum();

	enum PlaneName{
		Left,
		Right,
		Top,
		Bottom,
		Near,
		Far
	};

	bool isInView(const glm::vec3& point);
};

class Camera{
	glm::vec3 position;
	glm::mat4 perspective, orthographic;
	float fieldOfView;
	float yaw, pitch;
	float nearPlane, farPlane;
	glm::vec3 forwardVector, upVector, rightVector, worldUp;
	void updateCameraVectors();
	std::vector<LightSource*> lightSources;

	Frustum frustum;

public:
	Camera();
	~Camera();

	void setPosition(glm::vec3 position);
	void setRotation(float yaw, float pitch);
	glm::mat4 getView() const;
	const glm::mat4 getPerspective();
	const glm::mat4 getOrthographic();

	void processMouseMovement(float xOffset, float yOffset);
	void processMouseZoom(int y);

	Frustum getFrustum() const;

	void addLightSources(LightSource* light);
	std::vector<LightSource*> getLightSources();

	glm::vec3 getPosition() const;

	glm::vec2 getClippingPlanes() const;
};
#endif // !CAMERA_H

