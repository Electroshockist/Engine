#include "File.h"

using namespace std;

File::File(string filePath) {
	SetFile(filePath);
}

File::~File() {}

void File::SetFile(const std::string filePath) {
	path = filePath;

	//find last instance of the character "/" in the filePath
	size_t fileNamePos = filePath.rfind("/");

	//find first instance of the character "." from the last "/"
	size_t extensionPos = filePath.find(".", fileNamePos);

	//the directory is everything up to the last "/"
	directory = filePath.substr(0, fileNamePos + 1);
	//the name is everything after the last "/" and before the first.
	name = filePath.substr(fileNamePos + 1, extensionPos - fileNamePos - 1);
	extension = filePath.substr(extensionPos);
}
