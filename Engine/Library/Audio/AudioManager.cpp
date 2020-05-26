#include "AudioManager.h"

#include <SDL\SDL_filesystem.h>

#include "../Utility/FilePathParser.h"
#include "../Debugging/Debug.h"

AudioManager* AudioManager::mgrInstance = NULL;

Mix_Music* AudioManager::GetMusic(std::string filename){
	std::string fullpath = FilePathParser::GetResourcePath();
	fullpath.append(filename);

	if (mMusic[fullpath] == nullptr) {

		mMusic[fullpath] = Mix_LoadMUS(fullpath.c_str());
		if (mMusic[fullpath] == NULL) {
			Debug::error("Music Loading Error: File-" + filename + " Error-%s" + Mix_GetError(), __FILE__, __LINE__);
		}
		
	}
	return mMusic[fullpath];
}

Mix_Chunk* AudioManager::GetSFX(std::string filename)
{
	std::string fullpath = FilePathParser::GetResourcePath();
	fullpath.append(filename);

	if (mSFX[fullpath] == nullptr) {

		mSFX[fullpath] = Mix_LoadWAV(fullpath.c_str());
		if (mSFX[fullpath] == NULL) {
			Debug::error("SFX Loading Error : File-" + filename + " Error-%s" + Mix_GetError(), __FILE__, __LINE__);
		}
		
	}
	return mSFX[fullpath];
}

AudioManager* AudioManager::Instance(){
	if (mgrInstance == NULL) {
		mgrInstance = new AudioManager();
	}

	return mgrInstance;	
}
