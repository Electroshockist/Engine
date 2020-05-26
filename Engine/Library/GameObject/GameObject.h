#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include "../Data Structures/Decorator.h"
#include "AComponent.h"

struct GameObject : public DataStructures::IDecoratable{
	GameObject();
	~GameObject();

	void Update(unsigned int deltaTime);
	void Render(class ACamera* camera);

	inline std::vector<AComponent*> getComponents() const{
		return components;
	}

	void addComponent(AComponent* component);

private:
	std::vector<AComponent*> components;
	std::vector<AUpdatable*> updatableComponents;
	std::vector<ARenderable*> renderableComponents;

	// Inherited via IDecoratable
	virtual void Update(IDecoratable * parent) override;
};

#endif // !GAMEOBJECT_H
