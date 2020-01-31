#ifndef ATEXTURE_H
#define ATEXTURE_H

#include <glm/glm.hpp>

#include "../../Utilities/File.h"

struct ATexture {
	ATexture();
	ATexture(const std::string& textureFileName);

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

protected:
	glm::vec2 size;

	File file;
};
#endif // !ATEXTURE_H

