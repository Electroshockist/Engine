#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include "AComponent.h"

class GameObject{

public:
	std::vector<AComponent> components;
	GameObject();
	~GameObject();
};

#endif // !GAMEOBJECT_H
