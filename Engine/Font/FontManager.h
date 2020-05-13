#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include "SDL/SDL_ttf.h"
class FontManager
{
private:
	static FontManager* mgrInstance;

	FontManager() {}
	~FontManager() {};

public:
	static FontManager* Instance();


};

#endif