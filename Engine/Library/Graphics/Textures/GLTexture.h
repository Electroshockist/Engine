#pragma once
#include "ATexture.h"
#include "GLEW\glew.h"
struct GLTexture : public ATexture {
	GLTexture();
	~GLTexture();

private:
	GLuint textureID;
};

