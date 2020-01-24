#include "FilePathParser.h"
#include "../Debugging/Debug.h"
#include <algorithm>

using namespace std;

string FilePathParser::projectPath = "";

void FilePathParser::SetProjectPath(const string argv0) {
	//find position of the word "Debug" in path
	size_t pos = argv0.rfind("Debug");

	//truncate at position
	projectPath = argv0.substr(0, pos);
}

std::string FilePathParser::getProjectPath() {
	return projectPath;
}

string FilePathParser::ToLower(const string s) {
	string temp = s;
	// convert string to lower case
	for_each(temp.begin(), temp.end(), [](char & c) {
		c = ::tolower(c);
	});
	return temp;
}

FilePathParser::~FilePathParser() {}