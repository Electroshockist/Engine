#ifndef LIBRARYMAIN_H
#define LIBRARYMAIN_H

#include <memory>

struct LibraryMain{
	//delete constructors for singleton
	LibraryMain(const LibraryMain&) = delete;
	LibraryMain(LibraryMain&&) = delete;
	LibraryMain& operator=(const LibraryMain&) = delete;
	LibraryMain& operator=(LibraryMain&&) = delete;

	static LibraryMain* GetInstance();

	bool OnCreate(int argc, char *argv[]);

	bool Run();

private:
	static std::unique_ptr<LibraryMain> instance;
	friend std::default_delete<LibraryMain>;

	LibraryMain();
	~LibraryMain();
};
#endif //LIBRARYMAIN_H