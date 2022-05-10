#include<iostream>
#include"QueueArray.h"
using namespace std;
void main() {
	QueueArray<int> q(4);
	int x;
	q.enq(x = 5);
	q.enq(x = 15);
	q.enq(x = 25);
	q.enq(x = 35);
	q.print();
	q.enq1(x = 50);
	q.print();
	q.deq();
	q.print();
	q.enq(x = 50);
	q.print();
	q.normalize();
	q.print();
	q.deq();
	q.deq();
	q.print();
	q.memOpt();
	q.print();
	q.enq(x = 70);
	q.print();
	int n;
	q.Filter(x = 50, n = 70);
	q.print();
	/*q.clear();
	q.print();*/
}