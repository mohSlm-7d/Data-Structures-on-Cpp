#pragma once
#include"Node.h"
#include"SLL.h"
#include<iostream>
using namespace std;
void main() {
	SLL SLL1, SLL2, SLL3;
	/*cout << SLL1.isEmpty();
	SLL1.print(); 
	SLL1.addToHead(5);
	SLL1.addToHead(6);
	//SLL1.print();
	Node* f = SLL1.getHeadNode();
	cout << f->data;
	cout << SLL1.getHead();
	SLL1.addToHead(7); 
	SLL1.addToHead(8);
	SLL1.print();
	cout << SLL1.getValueAtIndex(3); 
	cout << SLL1.isInList(5);
	cout << SLL1.getSum(6);*/
	/*cout << "Max:" << SLL1.getMax() << endl;
	cout << endl << SLL1.getHead() << endl;
	cout << SLL1.isEmpty();
	cout << SLL1.getHeadNode() << endl;
	SLL1.print();
	SLL1.addToHead(1);
	cout << "Max:" << SLL1.getMax() << endl;
	SLL1.addToHead(2);
	SLL1.addToHead(8);
	SLL1.addToHead(7);
	SLL1.print();
	cout << SLL1.getHeadNode() << endl;
	cout << endl << SLL1.getHead() << endl;
	cout << SLL1.getSize();
	cout << SLL1.getSum(7);
	Node* f = SLL1.getTailNode();
	cout << f->data;
	cout << endl;
	cout << "Max:" << SLL1.getMax() << endl;*/
	/*SLL1.addToTail(2);
	SLL1.addToTail(8);
	SLL1.addToHead(8);
	SLL1.addToTail(8);*/
	SLL1.print();
	//SLL1.deleteFromHead();
	SLL1.print();
	//while (!SLL1.isEmpty());
		//SLL1.deleteFromHead();
		//SLL1.deleteFromTail();
	//bool flag = SLL1.deleteNode(8);
	//cout << flag << endl << endl;
	//SLL1.print();
	//while (SLL1.deleteNode(8));
	SLL1.print();
	//SLL1.deleteFirstOcc(8);
	//SLL1.print();
	for (int i = 0; i <= 10; i=i+2) {
		SLL1.insert(i);
	}
	SLL1.print();
	/*cout << "With: (return)" << endl;
	SLL1.insert(5);
	SLL1.print();
	while (!SLL1.isEmpty())SLL1.deleteFromHead();
	for (int i = 0; i <= 10; i = i + 2) {
		SLL1.insert(i, true);
	}
	SLL1.insert(5, false);
	cout << "Withot: (return)" << endl;
	SLL1.print();*/
	SLL1.clearAll();
	SLL1.print();
	
}