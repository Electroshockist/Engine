#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H

#include <vector>
#include <memory>
#include <string>

struct ATexture;
struct TextureManager {
	//delete constructors for singleton
	TextureManager(const TextureManager&) = delete;
	TextureManager(TextureManager&&) = delete;
	TextureManager& operator=(const TextureManager&) = delete;
	TextureManager& operator=(TextureManager&&) = delete;

	//tries to add a unique texture, returns false if it already exists
	bool AddUniqueTexture(ATexture* Texture);
	bool RemoveTexture(ATexture* texture);

	bool GetTexture(const std::string & name);

	//get singleton instance
	static TextureManager* GetInstance();

private:
	//singleton instance pointer
	static std::unique_ptr<TextureManager> managerInstance;
	friend std::default_delete<TextureManager>;

	static std::vector<ATexture*> textures;

	bool CompareTexture(ATexture* texture1, ATexture* texture2);

	TextureManager();
	~TextureManager();
};

#endif // !TEXTUREHANDLER_H
