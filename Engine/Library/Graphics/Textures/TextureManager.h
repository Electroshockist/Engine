#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H

#include <memory>
#include <map>

struct ATexture;
struct TextureManager {
	//delete constructors for singleton
	TextureManager(const TextureManager&) = delete;
	TextureManager(TextureManager&&) = delete;
	TextureManager& operator=(const TextureManager&) = delete;
	TextureManager& operator=(TextureManager&&) = delete;

	//tries to add a unique texture, returns false if it already exists
	bool addUniqueTexture(ATexture* texture);
	bool removeTexture(ATexture* texture);

	ATexture* getTexture(std::string name);
	std::string getTextureName(ATexture* texture);

	//get singleton instance
	static TextureManager* getInstance();

private:
	//singleton instance pointer
	static std::unique_ptr<TextureManager> managerInstance;
	friend std::default_delete<TextureManager>;
	static std::map<std::string, ATexture*> textures;

	TextureManager();
	~TextureManager();
};

#endif // !TEXTUREHANDLER_H
