#include"DLL.h"
#include"QueueDLL.h"
#include<iostream>
using namespace std;
void main() {
	int val;
	QueueDLL<int> q;
	q.enq(val = 4);
	q.enq(val = 5);
	q.enq(val = 6);
	q.print();
	/*cout << q.getFirst() << endl; cout << q.getLast() << endl;	
	cout << q.deq() << endl;
	cout << q.getFirst() << endl; cout << q.getLast() << endl;
	cout << q.deq() << endl;
	cout << q.getFirst() << endl; cout << q.getLast() << endl;
	cout << q.deq() << endl;
	try { cout << q.getFirst() << endl; cout << q.getLast() << endl; }
	catch (const char* error) { cout << endl << endl << error; }*/
	while (!q.isEmpty()) {
		//cout << q.getFirst();
		cout << q.deq() << endl;
	}
}