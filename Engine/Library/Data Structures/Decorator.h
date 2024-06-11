#ifndef DECORATOR_H
#define DECORATOR_H

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
namespace DataStructures{
	template <typename T>
	struct Decorator{
		//forward declare child class
		template <typename T>
		struct Node;

		Decorator(){}
		~Decorator(){
			DeleteChildren(&root);
		}
	private:
		template <typename T>
		struct BaseNode{
			inline void AddChild(std::string name, Node<T>* child_){
				child_->name = name;
				child_->parent = this;
				children.insert(std::pair<std::string, Node *>(name, child_));
			}

			inline std::map<std::string, Node<T>*> GetChildren() const{
				return children;
			}

			inline std::string GetName() const{
				return name;
			}

			virtual ~BaseNode(){};
		private:
			//allow Node to access these components
			friend Node<T>;
			friend Decorator;
			std::string name;
			std::map<std::string, Node<T>*> children;
		};

		inline void DeleteChildren(BaseNode<T> * node){
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

		#ifdef _DEBUG
		inline void PrintChildren(BaseNode<T> node, int& depth) const{
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
		#endif // DEBUG

	public:
		template <typename T>
		struct Node : public BaseNode<T>{
			T* data;

			inline void SetParent(std::string name, BaseNode<T>* parent_){
				this->name = name;
				parent_->children.insert(std::pair<std::string, Node<T> *>(name, this));
				parent = parent_;
			}

			virtual ~Node(){
				delete data;
				data = nullptr;
			}

		private:
			//allow BaseNode to access these components
			friend BaseNode;
			friend Decorator;

			//all Nodes inherit from BaseNode
			BaseNode<T>* parent;
		};

		#ifdef _DEBUG
		inline void PrintGraph() const{
			std::cout << "root" << std::endl;
			int depth = 0;
			PrintChildren(root, depth);
		}
		#endif // _DEBUG

		//root node that the scene starts on
		BaseNode<T> root;
	};
}
#endif // !DECORATOR_H