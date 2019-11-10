#ifndef ATEXTURE_H
#define ATEXTURE_H

#include "TextureManager.h"
#include "../../Math/MathPrimitives.h"
struct ATexture {
	ATexture();

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

protected:
	MATH::Vector2 size;

};
#endif // !ATEXTURE_H

