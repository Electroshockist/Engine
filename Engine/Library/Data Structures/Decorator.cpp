//#include "Decorator.h"
//
//#include "../Debugging/Debug.h"
//
//template<typename T>
//void DataStructures::Decorator<T>::AddSelfAsChild(T * parent_){
//	//if parent is being reassigned, remove self from old parent
//	if(parent != nullptr){
//		RemoveFromParent();
//	}
//
//	//set parent
//	this->parent = parent_;
//	parent->getChildren().insert(this);
//}
//
//template<typename T>
//void DataStructures::Decorator<T>::RemoveFromParent(){
//	//remove self from parent
//	parent->getChildren().erase(this);
//	//reset parent
//	parent = nullptr;
//}
//
//template<typename T>
//void DataStructures::Decorator<T>::RemoveFromChildren(){
//	CircularDynamicList<Decorator*>::Iterator iter;
//	Decorator* d;
//	for(iter = children.begin(); iter != children.end(); iter++){
//		d = *iter;
//		d->SetParent(nullptr);
//	}
//}
//
//template<typename T>
//T * DataStructures::Decorator<T>::GetData() const{
//	return data;
//}
//
//template<typename T>
//void DataStructures::Decorator<T>::SetData(T * data_){
//	data = data_;
//}
