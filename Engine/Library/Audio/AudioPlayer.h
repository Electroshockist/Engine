#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H
#include "AudioManager.h"
#include <string>
#include "../GameObject/AComponent.h"

class AudioPlayer: public AComponent {
	static AudioPlayer* managerInstance;

	AudioManager* mAssetMgr;

	AudioPlayer();
	~AudioPlayer();

public:

	static AudioPlayer* Instance();
	static void Release();

	void PlaySFX(std::string filename, int loops = 0, int channel = -1);

	void PlayMusic(std::string filename, int loops = -1);
	void MusicVolume(int volume);
	void SFXVolume(int volume, int channel);
	void PauseMusic();
	void ResumeMusic();
};
#endif // !AUDIO_H

