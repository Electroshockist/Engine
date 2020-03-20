#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H
#include "Audio.h"
#include <string>

class AudioManager {
	static AudioManager* sInstance;

	Audio* mAssetMgr;

	AudioManager();
	~AudioManager();

public:

	static AudioManager* Instance();
	static void Release();

	void PlayMusic(std::string filename, int loops = -1);

	void PauseMusic();
	void ResumeMusic();

	void PlaySFX(std::string filename, int loops = 0, int channel = 0);
};
#endif // !AUDIO_H

