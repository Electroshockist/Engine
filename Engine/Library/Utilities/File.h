#ifndef FILE_H
#define FILE_H

#include <string>
struct File{

	File() : name(""), extension(""), directory(""), path(""){}
	File(const std::string filePath);

	~File();

	void setFile(const std::string filePath);

	std::string getFullPath() const{
		return path;
	}

	std::string getName() const{
		return name;
	}

	std::string getExtension() const{
		return extension;
	}

	std::string getDirectory() const{
		return directory;
	}

private:
	std::string path;
	std::string name;
	std::string extension;
	std::string directory;
};


#endif // !FILE_H

