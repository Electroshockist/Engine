#include "TextureManager.h"

#include "SDL/SDL_image.h"
#include "GLEW/glew.h"
#include "../../Debugging/Debug.h"

std::unique_ptr<TextureManager> TextureManager::managerInstance = nullptr;

//get singleton instance
TextureManager * TextureManager::GetInstance(){
	if(managerInstance == nullptr){
		managerInstance.reset(new TextureManager);
	}
	return managerInstance.get();
}

unsigned int TextureManager::LoadTexture(std::string file){
	unsigned int currentTexture = GetTexture(file);
	if(currentTexture == 0){
		CreateTexture(file, "Resources/Textures/" + file + ".jpg");
		currentTexture = GetTexture(file);
	}
	return currentTexture;
}

void TextureManager::CreateTexture(const std::string &name, const std::string &file){
	TempTexture t = TempTexture();
	SDL_Surface *surface = nullptr;

	try{
		surface = IMG_Load(file.c_str());
	} catch(const std::exception e){
		Debug::error("Failed to load texture " + file, __FILE__, __LINE__);
		return;
	}
	t.size.x = static_cast<float>(surface->w);
	t.size.y = static_cast<float>(surface->h);

	glGenTextures(1, &t.id);
	glBindTexture(GL_TEXTURE_2D, t.id);
	int mode = surface->format->BytesPerPixel == 4 ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);

	//texture wrapping
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//mipmapping
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);
	textures[name] = t;
	SDL_FreeSurface(surface);
	surface = nullptr;
}

const unsigned int TextureManager::GetTexture(const std::string &textureName){
	if(textures.find(textureName) != textures.end()){
		return textures[textureName].id;
	}
	return 0;
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

