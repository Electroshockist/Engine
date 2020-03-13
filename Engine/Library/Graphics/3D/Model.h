#ifndef MODEL_H
#define MODEL_H

#include "Mesh.h"
#include <glm/gtc/matrix_transform.hpp>

class Model{
	std::vector<Mesh *> subMeshes;
	GLuint shaderProgram;
	glm::vec3 position;
	float angle;
	glm::mat4 getTransform(glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale);
	void LoadModel();
	std::vector<glm::mat4> modelInstances;

public:
	Model(){};
	Model(const std::string &objPath, const std::string &matPath, GLuint shaderProgram);
	~Model();
	void AddMesh(Mesh *mesh);
	void Render(ACamera *camera);
	void OnDestroy();
	int CreateInstance(glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale);
	void UpdateInstance(int index, glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale);
	glm::mat4 getTransform(int index) const;

	inline glm::vec3 GetPosition(){
		return position;
	}

	GLuint GetShaderProgram() const;
};
#endif // !MODEL_H