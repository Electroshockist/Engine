#ifndef SCENEGRAPH_H
#define SCENEGRAPH_H

#include "../Data Structures/Decorator.h"
#include "../"

class SceneGraph {
	struct Node{
		T data;
		Node* parent;
		set<Node*> children;
	};
public:
	SceneGraph();
	~SceneGraph();
};

#endif // !SCENEGRAPH_H

