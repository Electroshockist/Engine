#ifndef MODEL_H
#define MODEL_H

#include "Mesh.h"
#include "ModelLoader.h"
#include "../../GameObject/GameObject.h"
#include <glm/gtc/matrix_transform.hpp>

class Model : public GameObject{
	std::vector<Mesh*> meshes;
	Shader* shaderProgram;
	glm::vec3 position;
	float angle;
	glm::mat4 getTransform(glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale);
	void loadModel();
	std::vector<glm::mat4> modelInstances;
	ModelLoader* obj;

public:
	Model(const std::string& objPath, const std::string& matPath, Shader * shaderProgram);
	~Model();
	void addMesh(Mesh* mesh);
	void onDestroy();
	int createInstance(glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale);
	void updateInstance(int index, glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale);
	glm::mat4 getTransform(int index) const;

	std::vector<glm::mat4> getInstances() const;

	inline glm::vec3 GetPosition(){
		return position;
	}

	Shader * getShaderProgram() const;

	virtual void Render(ACamera * camera);
};
#endif // !MODEL_H