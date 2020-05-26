#ifndef ACOMPONENT_H
#define ACOMPONENT_H
struct AComponent{
	virtual ~AComponent(){};
};

struct AUpdatable : public AComponent{
	virtual void Update(unsigned int deltaTime) = 0;
};

struct ARenderable : public AComponent{
	virtual void Render(class ACamera* camera) = 0;
};
#endif // !ACOMPONENT_H
