#pragma once
#include"DLL.h"
template <class T>
class QueueDLL {
private:
	DLL<T> list;
public:
	void enq(T& data);
	T deq();
	T getFirst();
	T getLast();
	bool isEmpty();
	void print();
	void clear();
};
template<class T>
void QueueDLL<T>::enq(T& data) {
	list.addTail(data);
}
template<class T>
T QueueDLL<T>::deq() {
	T value = list.getHead();
	list.delHead();
	return value;
}
template<class T>
T QueueDLL<T>::getFirst() {
	return list.getHead();
}
template<class T>
T QueueDLL<T>::getLast() {
	return list.getTail();
}
template<class T>
bool QueueDLL<T>::isEmpty() {
	return list.isEmpty();
}
template<class T>
void QueueDLL<T>::print() {
	list.print();
}
template<class T>
void QueueDLL<T>::clear(){
	list.clearAll();
}