#include "AudioManager.h"

#include <SDL\SDL_filesystem.h>

#include "../Utility/FilePathParser.h"

AudioManager* AudioManager::mgrInstance = NULL;

Mix_Music* AudioManager::GetMusic(std::string filename){
	std::string fullpath = FilePathParser::GetResourcePath();
	fullpath.append(filename);

	if (mMusic[fullpath] == nullptr) {

		mMusic[fullpath] = Mix_LoadMUS(fullpath.c_str());
		if (mMusic[fullpath] == NULL) {
			printf("Music Loading Error: File-%s Error-%s", filename.c_str(), Mix_GetError());
		}
		return mMusic[fullpath];
	}
}

Mix_Chunk* AudioManager::GetSFX(std::string filename)
{
	std::string fullpath = SDL_GetBasePath();
	fullpath.append(filename);

	if (mSFX[fullpath] == nullptr) {

		mSFX[fullpath] = Mix_LoadWAV(fullpath.c_str());
		if (mSFX[fullpath] == NULL) {
			printf("SFX Loading Error: File-%s Error-%s", filename.c_str(), Mix_GetError());
		}
		return mSFX[fullpath];
	}
}

AudioManager* AudioManager::Instance(){
	if (mgrInstance == NULL) {
		mgrInstance = new AudioManager();
	}

	return mgrInstance;	
}
