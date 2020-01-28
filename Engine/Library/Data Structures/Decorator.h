#ifndef DECORATOR_H
#define DECORATOR_H


#include "CircularDynamicList.h"

using namespace std;
namespace DataStructures {
	class Decorator {
		friend Decorator;
		Decorator* parent;
		CircularDynamicList<Decorator*> children;

		//adds self as child to other decorator
		inline void AddSelfAsChild(Decorator* parent) {
			parent->getChildren().push_back_unique(this);
		}

		//remove self from parent's children
		inline void RemoveFromParent() {
			CircularDynamicList<Decorator*> gotChildren = parent->getChildren();
			CircularDynamicList<Decorator*>::Iterator iter = gotChildren.find(this);
			gotChildren.erase(iter);
		}

		//remove self from children's parents
		inline void RemoveFromChildren() {
			CircularDynamicList<Decorator*>::Iterator iter;
			Decorator* d;
			for (iter = children.begin(); iter != children.end(); iter++) {
				d = *iter;
				d->SetParent(nullptr);
			}
		}

	public:
		virtual ~Decorator() {
			//remove self as parent's child
			RemoveFromParent();

			//remove self as children's parents
			RemoveFromChildren();
		}

		//parent getter
		Decorator* getParent() {
			return parent;
		}

		//child getter
		CircularDynamicList<Decorator*> getChildren() {
			return children;
		}

		//parent setter
		inline void SetParent(Decorator* parent_) {
			parent = parent_;

			AddSelfAsChild(parent_);
		}

		//parent
		inline void RemoveParent() {
			RemoveFromParent();
			parent = nullptr;
		}

		//TODO: prevent duplicates being added to children
		inline void AddChild(Decorator* d) {
			d->SetParent(this);
			children.push_back(d);
		}

		inline void RemoveChild(Decorator* child) {
			//cout << "set parent" << endl;
			child->SetParent(nullptr);
			CircularDynamicList<Decorator*>::Iterator iter = children.find(this);
			children.erase(iter);
		}

		//test if addresses are the same
		bool operator== (const Decorator& rhs) const {
			return this == &rhs;
		}
	};
}
#endif // !DECORATOR_H