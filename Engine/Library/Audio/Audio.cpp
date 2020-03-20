#include "Audio.h"
#include <SDL\SDL_filesystem.h>

Mix_Music* Audio::GetMusic(std::string filename){


	std::string fullpath = SDL_GetBasePath();
	fullpath.append("Assets/" + filename);

	if (mMusic[fullpath] == nullptr) {

		mMusic[fullpath] = Mix_LoadMUS(fullpath.c_str());
		if (mMusic[fullpath] == NULL) {
			printf("Music Loading Error: File-%s Error-%s", filename.c_str(), Mix_GetError());
		}
		return mMusic[fullpath];
	}
}

Mix_Chunk* Audio::GetSFX(std::string filename)
{
	std::string fullpath = SDL_GetBasePath();
	fullpath.append("Assets/" + filename);

	if (mSFX[fullpath] == nullptr) {

		mSFX[fullpath] = Mix_LoadWAV(fullpath.c_str());
		if (mSFX[fullpath] == NULL) {
			printf("SFX Loading Error: File-%s Error-%s", filename.c_str(), Mix_GetError());
		}
		return mSFX[fullpath];
	}
}
