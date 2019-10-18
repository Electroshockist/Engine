#ifndef ASCENE_H
#define ASCENE_H

#include "MATH.h"
class AScene
{
public:
	explicit AScene() {}
	virtual ~AScene() {}

	virtual bool OnCreate() = 0;
	virtual void OnDestroy() = 0;
	virtual void Update(const float deltaTime_) = 0;
	virtual void Render() = 0;
};
#endif