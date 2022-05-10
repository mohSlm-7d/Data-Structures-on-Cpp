#pragma once                                                                                                                                       
#include"DLL.h"
template <class T>
class StackDLL {
private:
	DLL<T> list;
public:
	StackDLL();
	~StackDLL();
	void push(T& data);
	T pop();
	bool isEmpty() { return list.isEmpty(); }
	void clear();
	void print();
};
template<class T>
StackDLL<T>::StackDLL() {}
template<class T>
StackDLL<T>::~StackDLL() {}
template<class T>
void StackDLL<T>::push(T& data) {
	list.addTail(data);
}
template<class T>
T StackDLL<T>::pop() {
	T value = list.getTail();
	list.delTail();
	return value;
}
template<class T>
void StackDLL<T>::clear() {
	list.clearAll();
}
template<class T>
void StackDLL<T>::print() {
	list.print();
}