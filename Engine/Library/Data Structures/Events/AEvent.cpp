#include "AEvent.h"

void AEvent::notify() {
	for (size_t i = 0; i < listeners.size(); i++) {
		listeners.at(i)->onNotify();
	}
}
