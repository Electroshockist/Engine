#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton {
private:
	/* Here will be the instance stored. */
	static Singleton* instance;

	/* Private constructor to prevent instancing. */
	Singleton(){}

public:
	/* Static access method. */
	inline static Singleton* getInstance(){
		if (instance == 0) {
			instance = new Singleton();
		}

		return instance;
	}
};

#endif // !SINGLETON_H

