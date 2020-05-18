#ifndef ASCENE_H
#define AWORLD_H

#include <vector>

#include "../Data Structures/Decorator.h"
#include "../GameObject/GameObject.h"

struct AWorld{
	explicit AWorld(){}
	virtual ~AWorld(){}

	virtual bool OnCreate() = 0;
	virtual bool Update(const float deltaTime_) = 0;
	virtual bool Render() = 0;

protected:
	DataStructures::Decorator<GameObject> sceneGraph;
};
#endif