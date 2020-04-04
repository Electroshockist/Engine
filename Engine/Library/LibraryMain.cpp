#include "LibraryMain.h"
std::unique_ptr<LibraryMain> LibraryMain::instance = nullptr;

LibraryMain::LibraryMain(){}

LibraryMain::~LibraryMain(){}

LibraryMain * LibraryMain::GetInstance(){
	if(instance == nullptr){
		instance.reset(new LibraryMain);
	}
	return nullptr;
}
