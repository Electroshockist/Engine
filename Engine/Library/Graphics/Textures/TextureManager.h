#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H

#include <vector>
#include <memory>
#include <string>
#include "../../Utilities/AManager.h"

struct ATexture;
struct TextureManager : public AManager<ATexture>{
	//delete copy constructors for singleton
	TextureManager(const TextureManager&) = delete;
	TextureManager(TextureManager&&) = delete;
	TextureManager& operator=(const TextureManager&) = delete;
	TextureManager& operator=(TextureManager&&) = delete;

private:
	TextureManager();
	~TextureManager();
};

#endif // !TEXTUREHANDLER_H
