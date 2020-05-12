//#ifndef DECORATOR_H
//#define DECORATOR_H
//
//#include <set>
//#include <algorithm>
//
//using namespace std;
//namespace DataStructures{
//	template<typename T>
//	class Decorator{
//
//
//		friend Decorator<T>;
//		Decorator<T>* parent;
//		set<Decorator<T>*> children;
//
//		//adds self as child to other decorator
//		void AddSelfAsChild(Decorator<T>* parent);
//
//		//remove self from parent's children
//		void RemoveFromParent();
//
//		//remove self from children's parents
//		void RemoveFromChildren();
//
//		T* data;
//
//	public:
//
//		T* GetData() const;
//		void SetData(T* data);
//
//		//////////////////////////////////////////////
//		//					TODO					//
//		//////////////////////////////////////////////
//
//
//
//		Decorator() : parent(nullptr), children(set<Decorator*>()){}
//		virtual ~Decorator(){
//			//remove self as parent's child
//			RemoveFromParent();
//
//			//remove self as children's parent
//			RemoveFromChildren();
//		}
//
//		//parent getter
//		inline Decorator* getParent() const{
//			return parent;
//		}
//
//		//child getter
//		inline set<Decorator*> getChildren() const{
//			return children;
//		}
//
//		//parent setter
//		inline void SetParent(Decorator* parent_){
//			//parent->AddChild(this);
//		}
//
//		//parent
//		inline void RemoveParent(){
//			RemoveFromParent();
//			parent = nullptr;
//		}
//
//		//TODO: prevent duplicates being added to children
//		inline void AddChild(Decorator* child){
//			//child->SetParent(this);
//			children.insert(child);
//		}
//
//		inline void RemoveChild(Decorator* child){
//			auto r = remove(children.begin(), children.end(), child);
//			children.erase(r, children.end());
//		}
//
//		//test if addresses are the same
//		bool operator== (const Decorator& rhs) const{
//			return this == &rhs;
//		}
//	};
//}
//#endif // !DECORATOR_H