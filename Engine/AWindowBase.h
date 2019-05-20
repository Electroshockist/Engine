
#include <string>
#include "MathPrimitives.h"

using namespace std;

class AWindowBase
{
public:

	//Title
	virtual void setTitle(string n) = 0;
	virtual string getTitle() = 0;

	////Position
	/////position can only be set initially, therefore there are no setters for position
	//virtual MATH::Vector2<int> getPosition() = 0;

	virtual int getX() = 0;
	virtual int getY() = 0;

	////Size
	/////Size can only be set initially, therefore there are no setters for Size
	//virtual MATH::Vector2<int> getDimensions() = 0;

	virtual int getWidth() = 0;
	virtual int getHeight() = 0;

	virtual ~AWindowBase() {};

};