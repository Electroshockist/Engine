#include "TextureManager.h"

std::unique_ptr<TextureManager> TextureManager::managerInstance = nullptr;

//get singleton instance
TextureManager * TextureManager::GetInstance(){
	if(managerInstance == nullptr){
		managerInstance.reset(new TextureManager);
	}
	return managerInstance.get();
}



//ATexture *TextureManager::GetTexture(const File file){
//	return nullptr;
//}
//
//void TextureManager::Remove(ATexture *texture){
//	textures.erase(texture->GetFile());
//}

TextureManager::TextureManager() {}

TextureManager::~TextureManager() {}

