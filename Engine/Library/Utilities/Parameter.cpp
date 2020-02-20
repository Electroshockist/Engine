#include "Parameter.h"
#include "../Debugging/Debug.h"

Parameter::Type Parameter::getType(){
	return static_cast<Type>(data.index());
}
