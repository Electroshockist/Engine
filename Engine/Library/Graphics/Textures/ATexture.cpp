#include "ATexture.h"
#include "TextureManager.h"

ATexture::ATexture() : size(glm::vec2()) {}

ATexture::ATexture(const File textureFile) {}

ATexture::~ATexture() {
	//TextureManager::GetInstance()->Remove(this);
}
