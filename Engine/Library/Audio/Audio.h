#ifndef AUDIO_H
#define AUDIO_H
#include <SDL/SDL_mixer.h>
#include <map>
#include <string>
class Audio{

private:
	std::map<std::string, Mix_Music*> mMusic;
	std::map<std::string, Mix_Chunk*> mSFX;

public:
	Mix_Music* GetMusic(std::string filename);
	Mix_Chunk* GetSFX(std::string filename);

private:
	Audio();
	~Audio(){};

};


#endif

