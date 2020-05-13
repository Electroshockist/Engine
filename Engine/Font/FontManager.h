#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include "SDL/SDL_ttf.h"
#include <string>
#include <map>
class FontManager
{
private:
	static FontManager* mgrInstance;
	std::map<std::string, TTF_Font*> fonts;

	FontManager() {}
	~FontManager() {};

public:
	static FontManager* Instance();
	void AddFont(std::string id, std::string path, int fontSize);
	TTF_Font* GetFont(std::string id);

};

#endif