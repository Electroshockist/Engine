#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H
#include "AudioManager.h"
#include <string>

class AudioPlayer {
	static AudioPlayer* managerInstance;

	AudioManager* mAssetMgr;

	AudioPlayer();
	~AudioPlayer();

public:

	static AudioPlayer* Instance();
	static void Release();

	void PlaySFX(std::string filename, int loops = 0, int channel = 0);

	void PlayMusic(std::string filename, int loops = -1);
	void PauseMusic();
	void ResumeMusic();

	Mix_Music* GetMusic(std::string filename);
	Mix_Chunk* GetSFX(std::string filename);
};
#endif // !AUDIO_H

