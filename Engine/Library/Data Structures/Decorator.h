#ifndef DECORATOR_H
#define DECORATOR_H

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
namespace DataStructures{
	template<typename T>
	struct Decorator{
		//forward declare child class
		class Node;

		Decorator(){}
		~Decorator(){
			DeleteChildren(&root);
		}

		inline void printGraph() const{
			std::cout << "root" << std::endl;
			int depth = 0;
			PrintChildren(root, depth);
		}

		//test if addresses are the same
		bool operator== (const Decorator& rhs) const{
			return this == &rhs;
		}

	private:
		struct BaseNode{
			inline void AddChild(std::string name, Node* child_){
				child_->name = name;
				child_->parent = this;
				children.insert(std::pair<std::string, Node *>(name, child_));
			}

			inline std::map<std::string, Node*> GetChildren() const{
				return children;
			}

			inline std::string GetName() const{
				return name;
			}
		private:
			//allow Node to access these components
			friend Node;
			friend Decorator<T>;
			std::string name;
			std::map<std::string, Node*> children;
		};


		inline void DeleteChildren(BaseNode * node){
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

		inline void PrintChildren(BaseNode node, int& depth) const{

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

	public:

		struct Node : public BaseNode{
			T* data;

			inline void SetParent(std::string name, BaseNode* parent_){
				this->name = name;
				parent_->children.insert(std::pair<std::string, Node *>(name, this));
				parent = parent_;
			}

		private:
			//allow BaseNode to access these components
			friend BaseNode;
			friend Decorator<T>;
			//all Nodes inherit from BaseNode
			BaseNode* parent;
		};

		//root node that the scene starts on
		BaseNode root;

	};

}
#endif // !DECORATOR_H