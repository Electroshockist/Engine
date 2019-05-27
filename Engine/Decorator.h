#pragma once
#include "CircularDynamicList.h"

using namespace DataStructures;
class Decorator {
	friend Decorator;
	Decorator* parent;
	CircularDynamicList<Decorator*> children;

	//adds self as child to other decorator
	inline void addSelfAsChild(Decorator* parent) { 
		parent->getChildren().push_back_unique(this);
	}

	//remove self from parent's children
	inline void removeFromParent() {
		CircularDynamicList<Decorator*> gotChildren = parent->getChildren();
		CircularDynamicList<Decorator*>::Iterator iter = gotChildren.find(this);
		gotChildren.erase(iter);
	}

	//remove self from children's parents
	inline void removeFromChildren() {
		CircularDynamicList<Decorator*>::Iterator iter;
		Decorator* d;
		for (iter = children.begin(); iter != children.end(); iter++) {
			d = *iter;
			d->setParent(nullptr);
		}
	}

public:	
	virtual ~Decorator() {
		//remove self as parent's child
		parent->removeFromParent();

		//remove self as children's parents
		removeFromChildren();
	}

	//parent getter
	Decorator* getParent(){
		return parent;
	}

	//child getter
	CircularDynamicList<Decorator*> getChildren() {
		return children;
	}

	//parent setter
	inline void setParent(Decorator* p){
		cout << "Set parent" << endl;
		parent = p;

		addSelfAsChild(p);
	}

	//parent
	inline void removeParent() {
		cout << "Removed parent" << endl;
		removeFromParent();
		parent = nullptr;
	}

	//TODO: prevent duplicates being added to children
	inline void addChild(Decorator* d) {
		cout << "Added child" << endl;
		children.push_back(d);
		d->setParent(this);
	}

	inline void removeChild(Decorator* d) {
		cout << "set parent" << endl;
		d->setParent(nullptr);
		CircularDynamicList<Decorator*>::Iterator iter = children.find(this);
		children.erase(iter);
	}

	//test if addresses are the same
	bool operator== (const Decorator& rhs) const {
		return this == &rhs;
	}
};
