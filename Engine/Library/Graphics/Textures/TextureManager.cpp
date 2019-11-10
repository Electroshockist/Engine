#include "TextureManager.h"
#include "ATexture.h"

std::unique_ptr<TextureManager> TextureManager::managerInstance = nullptr;

bool TextureManager::addUniqueTexture(ATexture * texture) {
	return false;
}

TextureManager * TextureManager::getInstance() {
	if(managerInstance == nullptr) {
		managerInstance.reset(new TextureManager);
	}
	return managerInstance.get();
}

TextureManager::TextureManager() {}

TextureManager::~TextureManager() {}