#ifndef AMOUSEADAPTER_H
#define AMOUSEADAPTER_H

#include <iostream>

using namespace std;
class AMouseAdapter {
protected:
	struct ButtonNames {
		inline static const string Left = "Left Button";
		inline static const string Right = "Right Button";
		inline static const string Middle = "Middle Button";
	};
	struct ButtonStates {
		inline static const string Down = "Down";
		inline static const string Up = "Up";
	};

};

#endif
