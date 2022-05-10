#pragma once
#include<iostream>
#include"DNode.h"
using namespace std;
template<class T>
class StackDLL;
template<class T>
class QueueDLL;
template <class T>
class DLL {
private:
	DNode<T>* h;
	DNode<T>* t;
	void addHead(T& x);
	void addTail(T& x);
	friend class QueueDLL<T>;
	friend class StackDLL<T>;
public:
	DLL();
	~DLL();
	bool isEmpty();
	void print();
	void printR();
	bool search(T& x);
	int getSize();
	int getLastOcc(T& x);
	DNode<T>* getHeadNode();
	DNode<T>* getTailNode();
	T getHead();
	T getTail();	
	void delHead();
	void delTail();
	bool delNode(T& x);
	void insert(T& x);
	void clearAll();
	void append(DLL<T>& otherlist);
	void append(DLL<T>& resultList, DLL<T>& otherlist);
	DLL<T>* append1(DLL<T>& otherlist);
	void insert_in_between(T& one, T& two, T& three);
	void merge(DLL<T>& l1);
	void deleteKLessN(T& k, T& n);
};
template <class T>
DLL<T>::DLL() {
	h = t = nullptr;
}
template <class T>
DLL<T>::~DLL() { clearAll(); }
template<class T>
bool DLL<T>::isEmpty() {
	return(h == nullptr && t == nullptr);
}
template<class T>
void DLL<T>::print() {
	//if (isEmpty()) { throw("The List is Empty."); }
	cout << "The List= ";
	DNode<T>* p = h;
	while (p != nullptr) {
		cout << p->data << ",";
		p = p->next;
	}
	cout << "." << endl;
}
template<class T>
void DLL<T>::printR() {
	//if (isEmpty())throw("The List is Empty.");
	cout << "The List Reversed: ";
	DNode<T>* p = t;
	while (p != nullptr) {
		cout << p->data << ",";
		p = p->prev;
	}
	cout << "." << endl;
}
template<class T>
bool DLL<T>::search(T& x) {
	DNode<T>* p = h;
	while (p != nullptr) {
		if (p->data == x)
			return true;
		p = p->next;
	}
	return false;
}
template<class T>
int DLL<T>::getSize() {
	int count = 0;
	DNode<T>* p = h;
	while (p != nullptr) {
		count++;
		p = p->next;
	}
	return count;
}
template <class T>
int DLL<T>::getLastOcc(T& x) {
	int count = getSize() - 1;
	DNode<T>* p = t;
	while (p != nullptr) {
		if (p->data == x)
			return count;
		p = p->prev;
		count--;
	}
	return -1;
}
template <class T>
DNode<T>* DLL<T>::getHeadNode() {
	return h;
}
template <class T>
DNode<T>* DLL<T>::getTailNode() {
	return t;
}
template <class T>
T DLL<T>::getHead() {
	if (isEmpty())
		throw("Empty");
		return h->data;
}
template<class T>
T DLL<T>::getTail() {
	if (isEmpty())
		throw("Empty");
		return t->data;
}
template <class T>
void DLL<T>::addHead(T& x) {
	/*DNode<T>* n = new DNode<T>(x, h, nullptr);
	if (isEmpty()) {
		h = t = n;
		return true;
	}
	else {
		h->prev = n;
		h = n;
		return true;
	}*/
	DNode<T>* n = new DNode<T>(x, h, nullptr);
	if (h != nullptr)
		h->prev = n;
	h = n;
	if (t == nullptr)
		t = n;
}
template <class T>
void DLL<T>::addTail(T& x) {
	/*DNode<T>* n = new DNode<T>(x, nullptr, t);
	if (isEmpty()) {
		h = t = n; 
		return true;
	}
	else {
		t->next = n;
		t = n;
		return true;
	}*/
	DNode<T>* n = new DNode <T>(x, nullptr, t);
	if (t != nullptr)
		t->next = n;
	t = n;
	if (h == nullptr)
		h = n;
}
template<class T>
void DLL<T>::delHead() {
	if (isEmpty())
		return;
	
	DNode<T>* p = h;
	if (h == t) {
		h = t = nullptr;
	}
	else {
		h = h->next;
		h->prev = nullptr;
	}
	delete p;
}
template <class T>
void DLL<T>::delTail() {
	if (isEmpty())
		return;
	
	DNode<T>* k = t;
	if (h == t) {
		h = t = nullptr;
	}
	else {
		t = t->prev; 
		t->next = nullptr;
	}
	delete k;
}
template<class T>
bool DLL<T>::delNode(T& x) {
	if (isEmpty())
		return false;

	if (h->data == x) {
		delHead();
		return true;
	}
	if (t->data == x) {
		delTail();
		return true;
	}
	DNode<T>* p = h->next;
	while (p != nullptr) {
		if (p->data == x) {
			/*DNode<T>* d = p;
			p = p->next;
			p->prev = d->prev;
			p = d;
			d = d->prev;
			d->next = p->next;
			delete p;
			return true;*/
			DNode<T>* after = p->next;
			DNode<T>* before = p->prev;
			before->next = after;
			after->prev = before;
			delete p;
			return true;
		}
		p = p->next;
	}
	return false;
}
template<class T>
void DLL<T>::insert(T& x) {
	if (isEmpty()) {
		addTail(x);
		return;
	}
	if (h->data >= x) {
		addHead(x);
		return;
	}
	if (t->data <= x) {
		addTail(x);
		return;
	}
	DNode<T>* p = h->next;
	while (p != nullptr) {
		if (p->data >= x) {
			DNode<T>* beforeP = p->prev;
			DNode<T>* n = new DNode<T>(x, p, beforeP);
			p->prev = n;
			beforeP->next = n;
			return;
		}
		p = p->next;
	}
}
template<class T>
void DLL<T>::clearAll() {
	DNode<T>* p;
	while (h != nullptr) {
		p = h;
		h = h->next;
		delete p;
	}
	t = nullptr;
}
template <class T>
void DLL<T>::append(DLL<T>& otherlist) {
	/*t->next = otherlist.h;
	otherlist.h->prev = t;
	t = otherlist.t;
	otherlist.h = otherlist.t = nullptr;*/
	
	DNode<T>* p = otherlist.h;
	while (p != nullptr) {
		addTail(p->data);
		p = p->next;
	}
}
template<class T>
void DLL<T>::append(DLL<T>& resultList, DLL<T>& otherlist) {
	DNode<T>* p = h;
	while (p != nullptr) {
		resultList.addTail(p->data);
		p = p->next;
	}

	p = otherlist.h;
	while (p != nullptr) {
		resultList.addTail(p->data);
		p = p->next;
	}
}
template<class T>
DLL<T>* DLL<T>::append1(DLL<T>& otherlist) {
	DLL<T>* resultList = new DLL<T>();

	DNode<T>* p = h;
	while (p != nullptr) {
		resultList->addTail(p->data);
		p = p->next;
	}

	p = otherlist.h;
	while (p != nullptr) {
		resultList->addTail(p->data);
		p = p->next;
	}
	return resultList;
}
template<class T>
void DLL<T>::insert_in_between(T& one, T& two, T& three) {
	if (isEmpty())
		return;
	if (one != two && one != three && two != three) {
		DNode<T>* onePtr = nullptr;
		DNode<T>* twoPtr = nullptr;
		
		DNode<T>* p = h;
		while (p != nullptr) {
			//*** onePtr = twoPtr = nullptr;
			if (p->data == one) {
				onePtr = p;
				twoPtr = p->next;
				if (twoPtr->data == two)
					break;
				else {//***
					onePtr = twoPtr = nullptr;
				}
			}
			p = p->next;
		}
		if (onePtr != nullptr && twoPtr != nullptr) {
			DNode<T>* n = new DNode<T>(three, twoPtr, onePtr);
			onePtr->next = n;
			twoPtr->prev = n;
		}
	}
}
template <class T>
void DLL<T>::merge(DLL<T>& l1) {
	//DNode<T>* cur = h;
	/*DNode<T>* othr = l1.h;
	while (othr != nullptr) {
		insert(othr->data);
		othr = othr->next;
	}
	l1.clearAll();
	*/
	DNode<T>* cur = h;
	DNode<T>* othr = l1.h;
	
	DLL<T>* l2 = new DLL<T>();
	while (cur != nullptr && othr != nullptr) {
		if (cur->data <= othr->data) {
			l2->addTail(cur->data);
			cur = cur->next;
		}
		else if (othr->data <= cur->data) {
			l2->addTail(othr->data);
			othr = othr->next;
		}

	}
	while (cur != nullptr) {
		l2->addTail(cur->data);
		cur = cur->next;
	}

	while (othr != nullptr) {
		l2->addTail(othr->data);
		othr = othr->next;
	}
	clearAll();
	append(l2);
}	
template<class T>
void DLL<T>::deleteKLessN(T& k, T& n) {
	if (isEmpty())
		return;
	int count = 0;
	if (t->data < n) {
		delTail();
		count++;
	}
	if (count == k) {
		return;
	}
	DNode<T>* p = t->prev; /*cout << "bitch";
	if (p->next == nullptr)
		cout << "bitch";*/
	while (p != nullptr) {
		//cout << endl << p->data;
		if (p->data < n) { 
			cout << count;
			DNode<T>* before = p->prev;
			DNode<T>* after = p->next;
			if (before != nullptr)
				before->next = after;
			if (after != nullptr)
				after->prev = before;
			delete p;
			count++;
			p = before;
		}
		else { p = p->prev; }
		if (count == k)
			return;
	}
	if (count == k)
		return;
	if (h->data < n) {
		delHead();
		count++;
	}
}