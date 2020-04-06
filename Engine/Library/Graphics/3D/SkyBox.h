#ifndef SKYBOX_H
#define SKYBOX_H

#include <GLEW/glew.h>
#include <glm/glm.hpp>

#include "Mesh.h"

class SkyBox : private Mesh{
	GLuint textureID, VAO, modelMatrixID;
	int shaderID;

	glm::mat4 modelMatrix;

	std::vector<glm::vec3*> vertices;

public:
	SkyBox();
	~SkyBox();
	bool onCreate();
	void onDestroy();
	void Render() const;
	inline GLuint getTextureID() const{ return textureID; }

	bool LoadTextures(const char * posX, const char * negX, const char * posY, const char * negY, const char * posZ, const char * negZ);

};
#endif // !SKYBOX_H

