#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H

#include <memory>
#include <vector>
#include <string>

struct ATexture;
struct TextureManager {
	//delete constructors for singleton
	TextureManager(const TextureManager&) = delete;
	TextureManager(TextureManager&&) = delete;
	TextureManager& operator=(const TextureManager&) = delete;
	TextureManager& operator=(TextureManager&&) = delete;

	//tries to add a unique texture, returns false if it already exists
	ATexture* addUniqueTexture(ATexture* Texture);
	bool removeTexture(ATexture* texture);

	bool getTexture(const std::string & name);

	//get singleton instance
	static TextureManager* getInstance();

private:
	//singleton instance pointer
	static std::unique_ptr<TextureManager> managerInstance;
	friend std::default_delete<TextureManager>;
	static std::vector<ATexture*> textures;

	TextureManager();
	~TextureManager();
};

#endif // !TEXTUREHANDLER_H
