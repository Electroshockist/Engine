#include "FilePathParser.h"
#include "../Debugging/Debug.h"
#include <algorithm>

using namespace std;

string FilePathParser::projectPath = "";

unique_ptr<FilePathParser> FilePathParser::instance = nullptr;

void FilePathParser::setProjectPath(const string argv0) {
	//find position of the word "Debug" in path
	size_t pos = argv0.rfind("Debug");

	//truncate at position
	projectPath = argv0.substr(0, pos);


}

FilePathParser * FilePathParser::getInstance() {
	if(instance == nullptr) {
		instance.reset(new FilePathParser);
	}
	return instance.get();
}

//to implement
std::string FilePathParser::getRelativePath(std::string path) {
	std::string tempFullPath = toLower(path);
	std::string tempProjectPath = projectPath;


	bool match = false;
	if(!match) {

	}

	return std::string();
}

string FilePathParser::toLower(const string s) {
	string temp = s;
	// convert string to lower case
	for_each(temp.begin(), temp.end(), [](char & c) {
		c = ::tolower(c);
	});
	return temp;
}

FilePathParser::FilePathParser() {}

FilePathParser::~FilePathParser() {}

FilePathParser::File::File(string relativePath, string name, string extension) {
	this->name = name;
	this->relativePath = relativePath;
}
