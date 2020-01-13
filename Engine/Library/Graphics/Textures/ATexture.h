#ifndef ATEXTURE_H
#define ATEXTURE_H

#include "../../Math/MathPrimitives.h"
#include "../../Utilities/File.h"

struct ATexture {
	ATexture();
	ATexture(const std::string& textureFileName);

	inline MATH::Vector2 getSize() {
		return size;
	}

	inline float getWidth() {
		return size.x;
	}

	inline float getHeight() {
		return size.y;
	}

	virtual ~ATexture();

	inline File getFile(){
		return file;
	}

protected:
	MATH::Vector2 size;

	File file;
};
#endif // !ATEXTURE_H

