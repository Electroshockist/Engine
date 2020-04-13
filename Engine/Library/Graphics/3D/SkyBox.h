#ifndef SKYBOX_H
#define SKYBOX_H

#include <GLEW/glew.h>
#include <glm/glm.hpp>

#include "ModelLoader.h"

class SkyBox {
	void GenerateBuffers();
	void RenderMesh(Camera* camera);

	GLuint VAO, VBO;
	GLuint shaderProgram;
	GLuint modelLoc, projLoc;
	SubMesh subMesh;

	glm::mat4 getTransform(float angle, glm::vec3 rotation);
	void loadModel();
	glm::mat4 modelInstance;

	float angle;

	ModelLoader* obj;
public:
	SkyBox(){}
	~SkyBox();
	bool onCreate();

	bool LoadTextures(const char * posX, const char * negX, const char * posY, const char * negY, const char * posZ, const char * negZ);

	void Render(Camera * camera);

	void createInstance(float angle, glm::vec3 rotation);
	inline GLuint getShaderProgram() const{ return shaderProgram; }

};
#endif // !SKYBOX_H

