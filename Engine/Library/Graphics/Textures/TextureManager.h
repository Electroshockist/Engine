#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H

#include <vector>
#include <memory>
#include <string>
#include <map>

struct ATexture;
struct TextureManager{
	//delete copy constructors for singleton
	TextureManager(const TextureManager&) = delete;
	TextureManager(TextureManager&&) = delete;
	TextureManager& operator=(const TextureManager&) = delete;
	TextureManager& operator=(TextureManager&&) = delete;

	static TextureManager* GetInstance();

private:
	//singleton instance pointer
	static std::unique_ptr<TextureManager> managerInstance;
	friend std::default_delete<TextureManager>;


	std::map<std::string, ATexture> textures;

	TextureManager();
	~TextureManager();
};

#endif // !TEXTUREHANDLER_H
