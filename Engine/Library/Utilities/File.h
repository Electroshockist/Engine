#ifndef FILE_H
#define FILE_H

#include <string>
struct File{

	File() : name(""), extension(""), directory(""), path(""){}
	File(const std::string filePath);

	~File();

	void SetFile(const std::string filePath);

	std::string GetFullPath() const{
		return path;
	}

	std::string GetName() const{
		return name;
	}

	std::string GetExtension() const{
		return extension;
	}

	std::string GetDirectory() const{
		return directory;
	}

private:
	std::string path;
	std::string name;
	std::string extension;
	std::string directory;
};


#endif // !FILE_H

