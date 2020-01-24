#ifndef ATEXTURE_H
#define ATEXTURE_H

#include "../../Math/MathPrimitives.h"
#include "../../Utilities/File.h"

struct ATexture {
	ATexture();
	ATexture(const std::string& textureFileName);

	inline MATH::Vector2 GetSize() {
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
	MATH::Vector2 size;

	File file;
};
#endif // !ATEXTURE_H

