#ifndef AUDIO_H
#define AUDIO_H
#include <SDL/SDL_mixer.h>
#include <map>
#include <string>
class AudioManager{
	std::map<std::string, Mix_Music*> mMusic;
	std::map<std::string, Mix_Chunk*> mSFX;

	static AudioManager* mgrInstance;

	AudioManager(){}
	~AudioManager(){};

public:
	Mix_Music* GetMusic(std::string filename);
	Mix_Chunk* GetSFX(std::string filename);

	static AudioManager* Instance();
};
#endif

