#ifndef ATEXTURE_H
#define ATEXTURE_H

#include <glm/glm.hpp>

#include "../../Utility/File.h"

struct ATexture {
	ATexture();
	ATexture(const File textureFile);

	inline glm::vec2 GetSize() {
		return size;
	}

	inline float GetWidth() {
		return size.x;
	}

	inline float GetHeight() {
		return size.y;
	}

	virtual ~ATexture();

	inline File GetFile(){
		return file;
	}

	virtual bool LoadTexture(const File file) = 0;

protected:
	glm::vec2 size;

	File file;
};
#endif // !ATEXTURE_H

