#pragma once
#include "../Font/FontManager.h"
#include "SDL/SDL_ttf.h"
#include <string>
class UILabel : public FontManager
{
public:
	UILabel(int xpos, int ypos, std::string text, std::string font, SDL_Color& colour) :
		labelText(text), labelFont(font), textColour(colour)
	{
		position.x = xpos;
		position.y = ypos;

	}
	~UILabel()
	{}

	void SetLabelText()
	{
		SDL_Surface* surf = TTF_RenderText_Blended(//Game::assets->GetFont(labelFont),labelText.c_str(),textColour);
			labelTexture = SDL_CreateTextureFromSurface(//Game::renderer, surf);
				SDL_FreeSurface(surf);

		SDL_QueryTexture(labelTexture, nullptr, nullptr, &position.w, &position.h);
	
	
	
	
	}

	void draw() override
	{
		SDL_RenderCopy(//Game::rendere, labelTexture, nullptr, &position);
	
	
	}

private:

	SDL_Rect position;
	std::string labelText;
	std::string labelFont;
	SDL_Color textColour;
	SDL_Texture* labelTexture;
};