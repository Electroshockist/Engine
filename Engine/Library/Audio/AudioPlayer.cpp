#include "AudioPlayer.h"


AudioPlayer* AudioPlayer::managerInstance = nullptr;

AudioPlayer* AudioPlayer::Instance(){
	if(managerInstance == NULL)
		managerInstance = new AudioPlayer();

	return managerInstance;
}

void AudioPlayer::Release(){
	delete managerInstance;
	managerInstance = NULL;
}

AudioPlayer::AudioPlayer(){
	mAssetMgr = AudioManager::Instance();

	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0){
		printf("Mixer Initialization Error: %s\n", Mix_GetError());
	}
}

AudioPlayer::~AudioPlayer(){
	mAssetMgr = NULL;
	Mix_Quit();
}

void AudioPlayer::PlayMusic(std::string filename, int loops){
	Mix_PlayMusic(mAssetMgr->GetMusic(filename), loops);
}

void AudioPlayer::MusicVolume(int volume){

	Mix_VolumeMusic(volume);

}

void AudioPlayer::SFXVolume(int volume, int channel) {
	Mix_Volume(channel, volume);

}

void AudioPlayer::PauseMusic(){
	if(Mix_PlayingMusic() != 0)
		Mix_PauseMusic();
}

void AudioPlayer::ResumeMusic(){
	if(Mix_PausedMusic() != 0)
		Mix_ResumeMusic();
}

void AudioPlayer::PlaySFX(std::string filename, int loops, int channel){
	Mix_PlayChannel(channel, mAssetMgr->GetSFX(filename), loops);
}
