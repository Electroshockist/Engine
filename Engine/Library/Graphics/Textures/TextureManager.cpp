#include "TextureManager.h"
#include "ATexture.h"

std::unique_ptr<TextureManager> TextureManager::managerInstance = nullptr;

//get singleton instance
TextureManager * TextureManager::GetInstance(){
	if(managerInstance == nullptr){
		managerInstance.reset(new TextureManager());
	}
	return static_cast<TextureManager*>(managerInstance.get());
}

TextureManager::TextureManager() {}

TextureManager::~TextureManager() {}

