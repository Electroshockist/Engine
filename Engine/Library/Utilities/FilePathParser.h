#ifndef FILEPATHPARSER
#define FILEPATHPARSER

#include <string>


struct FilePathParser {
	struct File {
		std::string name;
		std::string extension;
		std::string path;
		std::string relativePath;

		File() : name(""), extension(""), path(""), relativePath("") {}
		File(std::string path, std::string name, std::string extension);

	};

	//only supply with main's argv[0]
	static void setProjectPath(const std::string argv0);

	//get singleton instance
	static FilePathParser* getInstance();

	std::string getRelativePath(std::string path);

	//delete constructors for singleton
	FilePathParser(const FilePathParser&) = delete;
	FilePathParser(FilePathParser&&) = delete;
	FilePathParser& operator=(const FilePathParser&) = delete;
	FilePathParser& operator=(FilePathParser&&) = delete;

private:
	static std::string projectPath;

	std::string toLower(const std::string s);

	FilePathParser();
	~FilePathParser();

	//singleton instance pointer
	static std::unique_ptr<FilePathParser> instance;
	friend std::default_delete<FilePathParser>;

};

#endif // !FILEPATHPARSER

