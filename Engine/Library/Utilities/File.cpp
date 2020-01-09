#include "File.h"

using namespace std;

File::File(string filePath) {
	//find last instance of the character "/" in the filePath
	size_t fileNamePos = filePath.rfind("/");
	//TODO: find last period from end(for multiple extensions)
	//find last instance of the character "." in the filePath
	size_t extensionPos = filePath.rfind(".");

	//cut at position	
	directory = filePath.substr(0, fileNamePos + 1);
	name = filePath.substr(fileNamePos + 1, extensionPos - fileNamePos - 1);
	extension = filePath.substr(extensionPos);
}

File::~File() {}
