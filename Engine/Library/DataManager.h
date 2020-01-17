#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <vector>
#include <string>
#include <map>
#include <memory>

struct DataManager {
	//delete constructors for singleton
	DataManager(const DataManager&) = delete;
	DataManager(DataManager&&) = delete;
	DataManager& operator=(const DataManager&) = delete;
	DataManager& operator=(DataManager&&) = delete;

	static DataManager* getInstance() {
		if(instance == nullptr) {
			instance.reset(new DataManager);
		}
		return instance.get();
	}

	const std::map<std::string, std::vector<void*>> getDataMap() {
		return dataMap;
	}

private:
	DataManager();
	~DataManager() {}

	static std::unique_ptr<DataManager> instance;
	friend std::default_delete<DataManager>;

	
	std::map<std::string, std::vector<void*>> dataMap;
};

#endif // !DATAMANAGER_H

