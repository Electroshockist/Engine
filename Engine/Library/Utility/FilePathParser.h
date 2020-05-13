#ifndef FILEPATHPARSER_H
#define FILEPATHPARSER_H

#include <string>

struct FilePathParser{

	//delete constructors for static class
	FilePathParser() = delete;
	FilePathParser(const FilePathParser&) = delete;
	FilePathParser(FilePathParser&&) = delete;
	FilePathParser& operator=(const FilePathParser&) = delete;
	FilePathParser& operator=(FilePathParser&&) = delete;

	static std::string GetProjectPath();

	static std::string GetResourcePath();

private:

	static std::string ToLower(const std::string s);
	~FilePathParser();

};

#endif // !FILEPATHPARSER

