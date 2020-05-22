#include "FilePathParser.h"

#include <algorithm>
#include <iostream>

#include <SDL/SDL.h>

#include "../Debugging/Debug.h"


using namespace std;

std::string FilePathParser::GetProjectPath(){
	string path = SDL_GetBasePath();
	//find position of the word "Debug" in path
	size_t pos = path.rfind("Debug");

	//truncate at position
	path = path.substr(0, pos);

	return path;
}

string FilePathParser::GetResourcePath(){
	std::string path = GetProjectPath();

	path.append("Engine/Resources/");

	return path;
}

string FilePathParser::ToLower(const string s) {
	string temp = s;
	// convert string to lower case
	for_each(temp.begin(), temp.end(), [](char & character) {
		character = ::tolower(character);
	});
	return temp;
}

FilePathParser::~FilePathParser() {}
