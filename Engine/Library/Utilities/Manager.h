#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <vector>

template <typename T>
struct Manager{
	//tries to add a unique item, returns false if it already exists
	bool Add(T* item){

	};
	bool Add(T* item, bool isUnique){
		if(isUnique){
			return Add(item);
		}

	};

	bool Remove(const std::string & name){
		items.erase(name);
	}

	bool Remove(T* item){

		auto it = items.begin();
		while(it != items.end){

		}
		items.erase(item);
	}

	T* GetItem(const std::string & name){
		if(items.find(name) != items.end()){
			return items[name];
		}
		return nullptr;
	}

protected:
	std::vector<T*> items;

	Manager(){};
	virtual ~Manager(){}
};

#endif // MANAGER_H
