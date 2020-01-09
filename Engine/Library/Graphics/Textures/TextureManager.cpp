#include "TextureManager.h"
#include "ATexture.h"

std::unique_ptr<TextureManager> TextureManager::managerInstance = nullptr;
std::vector<ATexture*> TextureManager::textures = std::vector<ATexture*>();


bool TextureManager::addUniqueTexture(ATexture* texture) {
	for (int i = textures.size() - 1; i >= 0; i--) {
		if()
	}
	return true;
}

bool TextureManager::removeTexture(ATexture * texture) {
	return false;
}

ATexture * TextureManager::getTexture(const std::string & name) {
	if(textures.find(name) != textures.end()) {
		return textures[name];
	}
	return nullptr;
}

TextureManager * TextureManager::getInstance() {
	if(managerInstance == nullptr) {
		managerInstance.reset(new TextureManager);
	}
	return managerInstance.get();
}

TextureManager::TextureManager() {}

TextureManager::~TextureManager() {}