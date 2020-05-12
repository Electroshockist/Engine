#ifndef SCENEGRAPH_H
#define SCENEGRAPH_H

#include <map>

#include "../Data Structures/Decorator.h"
#include "../GameObject/GameObject.h"

class SceneGraph {
	//forward declare child class
	class Node;
	struct BaseNode{
		void AddChild(std::string name, Node* child);
		std::string GetName() const;
	private:
		//allow Node to access these components
		friend Node;
		friend SceneGraph;
		std::string name;
		std::map<std::string, Node*> children;
	};

	const void printChildren(BaseNode node, int& depth) const;

public:


	struct Node : public BaseNode{
		GameObject* gameObject;

		void SetParent(std::string name, BaseNode* parent);

	private:
		//allow BaseNode to access these components
		friend BaseNode;
		friend SceneGraph;
		//all Nodes inherit from BaseNode
		BaseNode* parent;
	};

	//root node that the scene starts on
	BaseNode root;

	const void printGraph() const;

	SceneGraph();
	~SceneGraph();
};

#endif // !SCENEGRAPH_H

