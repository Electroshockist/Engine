#include "AudioManager.h"

AudioManager* AudioManager::managerInstance = nullptr;

AudioManager* AudioManager::Instance(){

	if(managerInstance == NULL)
		managerInstance = new AudioManager();

	return managerInstance;
}

void AudioManager::Release(){

	delete managerInstance;
	managerInstance = NULL;

}



AudioManager::AudioManager(){

	mAssetMgr = AudioManager::Instance();

	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0){

		printf("Mixer Initialization Error: %s\n", Mix_GetError());
	}
}

AudioManager::~AudioManager(){

	mAssetMgr = NULL;
	Mix_Quit();
}


void AudioManager::PlayMusic(std::string filename, int loops){

	Mix_PlayChannel(mAssetMgr->GetMusic(filename), loops);
}

void AudioManager::PauseMusic(){
	if(Mix_PlayChannel() != 0)
		Mix_PauseMusic();
}

void AudioManager::ResumeMusic(){
	if(Mix_PausedMusic() != 0)
		Mix_ResumeMusic();
}

void AudioManager::PlaySFX(std::string filename, int loops, int channel){
	Mix_PlayChannel(channel, mAssetMgr->GetSFX(filename), loops);
}
