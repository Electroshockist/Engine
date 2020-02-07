#ifndef ASCENE_H
#define AWORLD_H
#include <vector>

class AWorld{
public:
	explicit AWorld(){}
	virtual ~AWorld(){}

	virtual bool OnCreate() = 0;
	virtual void Update(const float deltaTime_) = 0;
	virtual void Render() = 0;
protected:
};
#endif