#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include "AComponent.h"

struct GameObject{
	GameObject();
	~GameObject();

	void Update(const float deltaTime);
	void Render(class ACamera* camera);

	inline std::vector<AComponent*> getComponents() const{
		return components;
	}

	void addComponent(AComponent* component);

private:
	std::vector<AComponent*> components;
	std::vector<AUpdatable*> updatableComponents;
	std::vector<ARenderable*> renderableComponents;
	
	void Update(GameObject * parent, const float deltaTime, ACamera * camera);
};

#endif // !GAMEOBJECT_H
