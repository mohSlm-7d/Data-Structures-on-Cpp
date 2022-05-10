#include<iostream>
#include"DNode.h"
#include"DLL.h"
using namespace std;
void main() {
	DLL<int> dl1, dl2, dl3;
	try { dl1.print(); }
	catch (const char* msg) {
		cout << msg;
	}try {
		dl1.printR();
	}
	catch (const char* error) {
		cout << error;
	}
	dl1.print();
	dl1.printR();
	try {
		dl1.getHead();
	}
	catch (const char* msg) {
		cout << msg;
	}
	int x;
	/*dl1.addHead(x = 0);
	dl1.addHead(x = 7);
	dl1.addHead(x = 9);
	dl1.printR();
	dl2.addTail(x = 0);
	dl2.addTail(x = 7);
	dl2.addTail(x = 9);	
	dl2.print();
	dl2.delHead();
	dl2.print();
	dl2.delTail();
	dl2.print();*/
	int A[] = { 5,2,1,0,3 };
	for (int i = 0; i < 5; i++) {
		dl1.insert(A[i]);
	}
	dl1.print();
	for (int i = 0; i < 5; i++) {
		dl2.insert(A[i]);
	}
	/*dl2.print();
	dl2.delNode(x = 1);
	dl2.print();*/
	dl2.print();
	int one = 0, two = 1, three = 20;
	//dl2.insert_in_between(one, two, three);
	dl2.print();
	//dl2.merge(dl1);
	int n;
	dl2.deleteKLessN(x = 4, n = 20);
	dl2.print();
}