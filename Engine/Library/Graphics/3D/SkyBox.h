#ifndef SKYBOX_H
#define SKYBOX_H

#include <GLEW/glew.h>
#include <glm/glm.hpp>

#include "ModelLoader.h"

class SkyBox{
	void GenerateBuffers();
	void RenderMesh(Camera* camera);

	GLuint VAO, VBO;
	Shader* shaderProgram;
	SubMesh subMesh;

	glm::mat4 getTransform(float angle, glm::vec3 rotation);
	void loadModel();
	glm::mat4 modelInstance;

	glm::vec3 rotation; 
	float angle;

	ModelLoader* obj;
public:
	SkyBox() : modelInstance(glm::mat4(1)){}
	~SkyBox();
	bool onCreate();

	bool LoadTextures(const char * posX, const char * negX, const char * posY, const char * negY, const char * posZ, const char * negZ);

	void Render(Camera * camera);

	void createInstance(float angle, glm::vec3 rotation);
	inline Shader* getShaderProgram() const{ return shaderProgram; }

	void onMouseMove(int x, int y);

	SubMesh GetSubMesh()const;

};
#endif // !SKYBOX_H

