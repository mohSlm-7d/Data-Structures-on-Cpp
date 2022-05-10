#pragma once
template<class T>
class DLL;
template <class T>
class DNode {
private:
	T data;
	DNode<T>* next;
	DNode<T>* prev;
	friend class DLL<T>;
public:
	DNode(T& data, DNode<T>* next, DNode<T>* prev);
	~DNode();
	T getData();
	DNode<T>* getNext();
	DNode<T>* getPrev();
};
template<class T>
DNode<T>::DNode(T& data, DNode<T>* next, DNode<T>* prev) {
	this->data = data;
	this->next = next;
	this->prev = prev;
}
template <class T>
DNode<T>::~DNode(){}

template<class T>
T DNode<T>::getData() {
	return data;
}

template <class T>
DNode<T>* DNode<T>::getNext() {
	return next;
}

template<class T>
DNode<T>* DNode<T>::getPrev() {
	return prev;
}
