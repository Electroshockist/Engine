#include "Frustum.h"

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

	//Right clipping plane
	planes[Right].x = matrix[0][3] - matrix[0][0];
	planes[Right].y = matrix[1][3] - matrix[1][0];
	planes[Right].z = matrix[2][3] - matrix[2][0];
	planes[Right].w = matrix[3][3] - matrix[3][0];

	//Left clipping plane
	planes[Left].x = matrix[0][3] + matrix[0][0];
	planes[Left].y = matrix[1][3] + matrix[1][0];
	planes[Left].z = matrix[2][3] + matrix[2][0];
	planes[Left].w = matrix[3][3] + matrix[3][0];

	//Bottom clipping plane
	planes[Bottom].x = matrix[0][3] + matrix[0][1];
	planes[Bottom].y = matrix[1][3] + matrix[1][1];
	planes[Bottom].z = matrix[2][3] + matrix[2][1];
	planes[Bottom].w = matrix[3][3] + matrix[3][1];

	//Top clipping plane
	planes[Top].x = matrix[0][3] - matrix[0][1];
	planes[Top].y = matrix[1][3] - matrix[1][1];
	planes[Top].z = matrix[2][3] - matrix[2][1];
	planes[Top].w = matrix[3][3] - matrix[3][1];

	//Near clipping plane
	planes[Near].x = matrix[0][3] - matrix[0][2];
	planes[Near].y = matrix[1][3] - matrix[1][2];
	planes[Near].z = matrix[2][3] - matrix[2][2];
	planes[Near].w = matrix[3][3] - matrix[3][2];

	//Far clipping plane
	planes[Far].x = matrix[0][3] + matrix[0][2];
	planes[Far].y = matrix[1][3] + matrix[1][2];
	planes[Far].z = matrix[2][3] + matrix[2][2];
	planes[Far].w = matrix[3][3] + matrix[3][2];

	//Normalize planes
	normalizePlane(planes[Left]);
	normalizePlane(planes[Right]);
	normalizePlane(planes[Top]);
	normalizePlane(planes[Bottom]);
	normalizePlane(planes[Near]);
	normalizePlane(planes[Far]);
}