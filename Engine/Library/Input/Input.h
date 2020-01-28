#ifndef INPUT_H
#define INPUT_H

#include <glut.h>
#include <string>

using namespace std;

struct Input {
	struct Button {
		bool state = false;

		string getName() {
			return name;
		}

		Button(string _name) {
			name = _name;
		}

	private:
		string name;
	};

	//figure out why templates never work
	//template<
	//	typename T //real type
	//	//typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
	//>
	struct Axis {
		float value;

		string GetName() {
			return name;
		}

		Axis(string _name) {
			name = _name;
		}

	private:
		string name;
	};

	struct Mouse {
		inline static Button Left = Button("Left Mouse Button");
		inline static Button Right = Button("Right Mouse Button");
		inline static Button Middle = Button("Middle Mouse Button");

		inline static Axis PosX = Axis("X Mouse Position");
		inline static Axis PosY = Axis("Y Mouse Position");
	};

	struct Keyboard {
	};

	struct Controllers {
	};
};
#endif
