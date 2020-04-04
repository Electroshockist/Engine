#ifndef GLTEXTURE_H
#define GLTEXTURE_H

#include "ATexture.h"
#include "GLEW\glew.h"

struct GLTexture : public ATexture {
	GLTexture();
	~GLTexture();

	//bool LoadTexture(const File file) override;

private:
	GLuint textureID;
};

#endif // !GLTEXTURE_H