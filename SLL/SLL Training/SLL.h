#pragma once
#include"Node.h"
#include<iostream>
using namespace std;
class SLL {
private:
	Node* h;
	Node* t;
	void addToHead(int data);
	void addToTail(int data);
public:
	SLL();
	bool isEmpty();
	void print();
	int getSum(int v);
	int getSize();
	int getSumOfEven();
	bool isInList(int x);
	//int lastIndexOf(int x);
	int getValueAtIndex(int index);
	
	int getHead();
	int getTail();
	Node* getHeadNode();
	Node* getTailNode();
	//int getMax();
	Node* getMax();
	void deleteFromHead();
	void deleteFromTail();
	bool deleteNode(int x);
	bool deleteFirstOcc(int x);
	
	//Reminder:deleteAll() and deleteLastOcc() do it later.
	bool deleteAll(int x);
	bool deleteLastOcc(int x);

	void insert(int v);
	void clearAll();
};
SLL::SLL() {
	h = t = nullptr;
}
bool SLL::isEmpty() {
	return (h == nullptr && t == nullptr);
}
void SLL::print() {
	if (isEmpty()) {
		cout << endl << "The list is Empty." << endl;
		return;
	}
	Node* p = h;
	while (p != nullptr) {
		cout << p->data << endl;
		p = p->next;
	}
	cout << "====\n";
}
int SLL::getSum(int v) {
	int sum = 0;
	Node* p = h;
	while (p != nullptr) {
		if (p->data >= v)
			sum += p->data;
		p = p->next;
			
	}
	return sum;
}
int SLL::getSize() {
	int count = 0;
	Node* p = h;
	while (p != nullptr) {
		count++;
		p = p->next;
	}
	return count;
}
int SLL::getSumOfEven() {
	int sum = 0;
	Node* p = h;
	while (p != nullptr) {
		if (p->data % 2 == 0)
			sum += p->data;
		p = p->next;
	}
	return sum;
}
bool SLL::isInList(int x) {	
	Node* p = h;	
	while (p != nullptr) {
		if (p->data == x)
			return true;
		p = p->next;
	}
	return false;
}
/*int SLL::lastIndexOf(int x) {
	int index = -1;
	int count = 0;
	Node* p = h;
	while (p != nullptr) {
		if (p->data == x)
			index = count;
		count++;
		p = p->next;
	}
	if (index == -1) {
		cout << endl << "Not Found!" << endl;
		return;
	}
	else
		return index;
}*/
int SLL::getValueAtIndex(int index) {
	/*if (index >= this->getSize() || index<0) {
		cout << "The index does not exist!" << endl;
		return;
	}*/
	if (index < 0)return -99;
	int count = 0;
	Node* p = h;

	while (p != nullptr) {
		if (count == index)
			return p->data;
		p = p->next;
		count++;
	}
	return -99;
	
}
void SLL::addToHead(int data) {
	Node* n = new Node(data, h);
	h = n;
	if (t == nullptr)
		t = n;
}
void SLL::addToTail(int data) {
	Node* n = new Node(data, nullptr);
	if (isEmpty()) {
		h = t = n;
		return;
	}
	t->next = n;
	t = n;
}
int SLL::getHead() {
	if (isEmpty())
	{
		cout << "Empty";
		return -99;
	}
	return h->data;
}
int SLL::getTail() {
	if (isEmpty())
		return -99;

	return t->data;
}
Node* SLL::getHeadNode() {
	return h;
}
Node* SLL::getTailNode() {
	return t;
}
/*int SLL::getMax() {
	if(!isEmpty()){
		int max = h->data;

		Node* p = h->next;
		while (p != nullptr) {
			if (p->data > max)
				max = p->data;
			p = p->next;
		}
		return max;
	}
	cout << "Empty list." << endl;
	return false;
}*/
Node* SLL::getMax() {
	if (isEmpty())
		return NULL;

	Node* maxPtr = h;
	int max = h->data;

	Node* p = h->next;
	while (p != nullptr) {
		if (p->data > max) {
			max = p->data;
			maxPtr = p;
		}
		p = p->next;
	}
	return maxPtr;

}
void SLL::deleteFromHead() {
	if (isEmpty())
		return;

	Node* p = h;
	if (h == t)
		h = t = nullptr;
	else
		h = h->next;
	delete p;
}
void SLL::deleteFromTail() {
	if (isEmpty())
		return;
	Node* k = t;

	if (h == t) {
		h = t = nullptr;
	}

	else {
		Node* p = h;
		while (p->next != t) {
			p = p->next;
		}
		p->next = nullptr;
		t = p;
	}
	delete k;
}
bool SLL::deleteNode(int x) {
	if (isEmpty())
		return false;
	
	if (h->data == x) {
		deleteFromHead();
		return true;
	}
	if (t->data == x) {
		deleteFromTail();
		return true;
	}

	Node* p = h->next;
	Node* c = h;
	while (p != nullptr) {
		if (p->data == x) {
			c->next = p->next;
			delete p;
			return true;
		}
		c = p;
		p = p->next;
	}
	return false;
}
bool SLL::deleteFirstOcc(int x) {
	if (isEmpty())
		return false;
	
	if (h->data == x) {
		deleteFromHead();
		return true;
	}

	Node* p = h->next;
	Node* c = h;
	while (p != t) {
		if (p->data == x) {
			c->next = p->next;
			delete p;
			return true;
		}
		c = p;
		p = p->next;
	}

	if (t->data == x) {
		deleteFromTail();
		return true;
	}
	return false;
}

/*bool SLL::deleteAll(int x) {
	if (h->data == x) {
		deleteFromHead();
	}
	
	Node* p = h;
	Node* c = nullptr;
	while (p != nullptr) {
		if (p->data == x) {
			c->next = p->next;
		}
	}
}*/
bool SLL::deleteLastOcc(int x) {
	if (isEmpty())
		return false;

	if (t->data == x) {
		deleteFromTail();
		return true;
	}

	//Node* 
}
void SLL::insert(int v) {
	if (isEmpty()) {
		addToHead(v);
		return;
	}
	if (h->data >= v) {
		addToHead(v);
		return;
	}
	
	if (t->data <= v) {
		addToTail(v);
		return;
	}

	Node* p = h->next;
	Node* c = h;
	while (p != nullptr) {
		if (p->data >= v) {
			Node* n = new Node(v, p);
			c->next = n;
			return;
		}
		c = p;
		p = p->next;
	}
}
void SLL::clearAll() {
	/*Node* p = h;
	while (p != nullptr) {
		h = h->next;
		delete p;
		p = h;
	}
	t = nullptr;*/
	Node* p;
	while (h != nullptr) {
		p = h;
		h = h->next;
		delete p;
	}
	t = nullptr;
	
	/*while (!isEmpty()) 
		deleteFromHead();*/

}