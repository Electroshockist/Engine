#pragma once
#include <iostream>
#include <string>

#include "Decorator.h"

using namespace std;


class Test : public Decorator {
public:
	string name;
	Test(string name_) {
		name = name_;
		cout << "test" << endl;
	}

	~Test() {
	}

private:

};
