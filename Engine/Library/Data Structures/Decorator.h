#ifndef DECORATOR_H
#define DECORATOR_H

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
namespace DataStructures{

	struct Decorator{
		//forward declare child class
		class Node;

		Decorator(){}
		~Decorator();

		//test if addresses are the same
		bool operator== (const Decorator& rhs) const{
			return this == &rhs;
		}

	private:
		struct BaseNode{
			void AddChild(std::string name, Node* child_);

			inline std::map<std::string, Node*> GetChildren() const{
				return children;
			}

			inline std::string GetName() const{
				return name;
			}

			virtual ~BaseNode(){};
		private:
			//allow Node to access these components
			friend Node;
			friend Decorator;
			std::string name;
			std::map<std::string, Node*> children;
		};


		void DeleteChildren(BaseNode * node);


		void PrintChildren(BaseNode node, int& depth) const;

	public:
		struct Node : public BaseNode{
			//class GameObject* data;

			void SetParent(std::string name, BaseNode* parent_);

			virtual ~Node(){}

		private:
			//allow BaseNode to access these components
			friend BaseNode;
			friend Decorator;

			//all Nodes inherit from BaseNode
			BaseNode* parent;
		};

		void PrintGraph() const;

		//root node that the scene starts on
		BaseNode root;
	};

}
#endif // !DECORATOR_H