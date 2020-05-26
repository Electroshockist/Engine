#include "Decorator.h"

#include <iostream>

using namespace DataStructures;

DataStructures::Decorator::~Decorator(){
	DeleteChildren(&root);
}

void DataStructures::Decorator::PrintGraph() const{
	std::cout << "root" << std::endl;
	int depth = 0;
	PrintChildren(root, depth);
}

void DataStructures::Decorator::DeleteChildren(BaseNode * node){
	//depth-first deletion of all children
	for(auto it = node->children.begin(); it != node->children.end(); it++){
		if(node->children.size() > 0){
			DeleteChildren(it->second);
		}
		delete it->second;
		it->second = nullptr;
	}
	//after all children are deleted, clear list
	node->children.clear();
}

void DataStructures::Decorator::PrintChildren(BaseNode node, int & depth) const{

	depth++;

	for(auto const&[key, val] : node.children){
		//make tabs for every child down you are
		for(size_t i = 0; i < depth; i++){
			std::cout << "\t";
		}
		std::cout << key.c_str() << " has " << val->children.size() << " children." << std::endl;
		if(node.children.size() > 0){
			PrintChildren(*val, depth);
		}
	}

	depth--;
}

void DataStructures::Decorator::BaseNode::AddChild(std::string name, Node * child_){
	child_->name = name;
	child_->parent = this;
	children.insert(std::pair<std::string, Node *>(name, child_));
}

void DataStructures::Decorator::BaseNode::Update(){
	//convert this to node from base node
	Node* self = dynamic_cast<Node*>(this);

	//if this is a node
	if(self != nullptr){
		//convert parent to node from base node
		Node* p = dynamic_cast<Node*>(self->parent);
		//if parent is a node
		if(p != nullptr){
			self->data->Update(p->data);
		}
	}

	//breath first update children
	for(auto it = children.begin(); it != children.end(); it++){
		//convert child to node from base node
		Node* n = dynamic_cast<Node*>(it->second);
		//recurse per child
		it->second->Update();
	}
}

void DataStructures::Decorator::Node::SetParent(std::string name, BaseNode * parent_){
	this->name = name;
	parent_->children.insert(std::pair<std::string, Node *>(name, this));
	parent = parent_;
}
