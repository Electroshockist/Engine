#include "SceneGraph.h"

#include <iostream>


const void SceneGraph::printChildren(BaseNode node, int& depth) const{
	//std::cout << "Depth: " << depth << std::endl;

	depth++;

	for(auto const&[key, val] : node.children){
		//make tabs for every child down you are
		for(size_t i = 0; i < depth; i++){
			std::cout << "\t";
		}

		std::cout << key.c_str() << " has " << val->children.size() << " children." << std::endl;
		if(node.children.size() > 0){			
			printChildren(*val, depth);
		}
	}

	depth--;
}

const void SceneGraph::printGraph() const{
	std::cout << "root" << std::endl;
	int depth = 0;
	printChildren(root, depth);

}

SceneGraph::SceneGraph(){}


SceneGraph::~SceneGraph(){
}

void SceneGraph::BaseNode::AddChild(std::string name, Node * child_){
	child_->name = name;
	child_->parent = (this);
	children.insert(std::pair<std::string, Node *>(name, child_));
}

std::string SceneGraph::BaseNode::GetName() const{
	return name;
}

void SceneGraph::Node::SetParent(std::string name, BaseNode * parent_){
	this->name = name;
	parent_->children.insert(std::pair<std::string, Node *>(name, this));
	parent = parent_;

}
