#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H

#include <vector>
#include <memory>
#include <string>
#include <map>
#include <glm/glm.hpp>

//#include "ATexture.h"

struct TempTexture{
	unsigned int id;
	glm::vec2 size;
};

struct TextureManager{
	//delete copy constructors for singleton
	TextureManager(const TextureManager&) = delete;
	TextureManager(TextureManager&&) = delete;
	TextureManager& operator=(const TextureManager&) = delete;
	TextureManager& operator=(TextureManager&&) = delete;

	static TextureManager* GetInstance();

	unsigned int GetTexture();


	//ATexture* GetTexture(const File file);
	//void Remove(ATexture *Texture);

private:
	//singleton instance pointer
	static std::unique_ptr<TextureManager> managerInstance;
	friend std::default_delete<TextureManager>;

	std::map<std::string, TempTexture> textures;
	//std::map<File, ATexture> textures;

	TextureManager();
	~TextureManager();
};

#endif // !TEXTUREHANDLER_H
