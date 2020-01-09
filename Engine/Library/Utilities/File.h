#ifndef FILE_H
#define FILE_H

#include <string>
struct File {
	std::string name;
	std::string extension;
	std::string directory;

	File() : name(""), extension(""), directory(""){}
	File(const std::string filePath);

	~File();

	std::string getFullPath() {
		return directory + name + extension;
	}
};


#endif // !FILE_H

