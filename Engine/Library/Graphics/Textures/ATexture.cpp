#include "ATexture.h"
#include "TextureManager.h"

using namespace MATH;

ATexture::ATexture() : size(Vector2()) {}

ATexture::ATexture(const std::string & textureFileName) {

}

ATexture::~ATexture() {
	TextureManager::getInstance()->removeTexture(this);
}
