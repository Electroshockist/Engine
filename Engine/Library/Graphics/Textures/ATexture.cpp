#include "ATexture.h"
#include "TextureManager.h"

ATexture::ATexture() : size(glm::vec2()) {}

ATexture::ATexture(const std::string & textureFileName) {

}

ATexture::~ATexture() {
	TextureManager::GetInstance()->Remove(this);
}
