#pragma once
#include "CircularDynamicList.h"
class Decorator {
public:	
	inline ~Decorator() {
		delete parent;
	}

	const Decorator* getParent(){
		return parent;
	}

	const CircularDynamicList<Decorator> getChildren() {
		return children;
	}

	inline void setParent(Decorator* p){
		parent = p;
		CircularDynamicList<Decorator> gotChildren = p->getChildren();

		for (size_t i = 0; i < p->getChildren().size; i++) {
			if (!gotChildren.contains(*this)) {
				p->addChild(*this); 
			}
		}
	}

	inline void addChild(Decorator d) {
		children.push_back(d);
		if (d.getParent != this) {
			d.setParent(this);
		}
	}

private:
	Decorator* parent;
	CircularDynamicList<Decorator> children;
};
