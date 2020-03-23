#ifndef MODEL_H
#define MODEL_H

#include "Mesh.h"
#include <glm/gtc/matrix_transform.hpp>

class Model{
	std::vector<Mesh *> meshes;
	GLuint shaderProgram;
	glm::vec3 position;
	float angle;
	glm::mat4 getTransform(glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale);
	std::vector<glm::mat4> modelInstances;

public:
	Model() :angle(0), position(glm::vec3()), shaderProgram(0){};
	Model(GLuint shaderProgram);
	~Model();
	void AddMesh(Mesh *mesh);
	void Render(ACamera *camera);
	int CreateInstance(glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale);
	void UpdateInstance(int index, glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale);
	glm::mat4 getTransform(int index) const;

	inline glm::vec3 GetPosition(){
		return position;
	}

	GLuint GetShaderProgram() const;
};
#endif // !MODEL_H