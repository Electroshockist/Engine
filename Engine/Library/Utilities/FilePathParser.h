#ifndef FILEPATHPARSER
#define FILEPATHPARSER

#include <string>

struct FilePathParser {
	//only supply with main's argv[0]
	static void setProjectPath(const std::string argv0);

	static std::string getProjectPath();

	//delete constructors for static class
	FilePathParser() = delete;
	FilePathParser(const FilePathParser&) = delete;
	FilePathParser(FilePathParser&&) = delete;
	FilePathParser& operator=(const FilePathParser&) = delete;
	FilePathParser& operator=(FilePathParser&&) = delete;

private:
	static std::string projectPath;

	static std::string toLower(const std::string s);
	~FilePathParser();

};

#endif // !FILEPATHPARSER

