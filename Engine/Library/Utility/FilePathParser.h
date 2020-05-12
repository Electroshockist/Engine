#ifndef FILEPATHPARSER_H
#define FILEPATHPARSER_H

#include <glm/glm.hpp>
#include <string>

struct FilePathParser {
	//only supply with main's argv[0]
	static void SetProjectPath(const std::string argv0);

	static std::string getProjectPath();

	//delete constructors for static class
	FilePathParser() = delete;
	FilePathParser(const FilePathParser&) = delete;
	FilePathParser(FilePathParser&&) = delete;
	FilePathParser& operator=(const FilePathParser&) = delete;
	FilePathParser& operator=(FilePathParser&&) = delete;

private:
	static std::string projectPath;

	static std::string ToLower(const std::string s);
	~FilePathParser();

};

#endif // !FILEPATHPARSER

