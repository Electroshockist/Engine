#ifndef AMANAGER_H
#define AMANAGER_H

#include <string>
#include <vector>

template <typename T>
struct AManager{
	//delete constructors for singleton
	AManager(const AManager&) = delete;
	AManager(AManager&&) = delete;
	AManager& operator=(const AManager&) = delete;
	AManager& operator=(AManager&&) = delete;

	//tries to add a unique item, returns false if it already exists
	virtual bool Add(T* item) = 0;

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

	//get singleton instance
	static AManager* GetInstance(){
		if(managerInstance == nullptr){
			managerInstance.reset(new AManager<T>);
		}
		return managerInstance.get();
	}

protected:
	//singleton instance pointer
	static std::unique_ptr<AManager> managerInstance;
	friend std::default_delete<AManager>;

	std::vector<T*> items;

	virtual bool IsImplemented() = 0;

	AManager(){};
	virtual ~AManager(){};
};

#endif // AMANAGER_H
