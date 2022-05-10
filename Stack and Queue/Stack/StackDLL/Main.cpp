#include"DLL.h"
#include"StackDLL.h"
#include<iostream>
using namespace std;
void main() {
	StackDLL<int> st;
	int val;
	st.push(val = 4);
	st.push(val = 5);
	st.push(val = 6);
	st.print();
	/*cout << st.pop() << endl;
	cout << st.pop() << endl;
	st.print();
	cout << st.top() << endl;
	st.print();*/
	//int y = 0;
	//while (!st.isEmpty()) {
		//cout << st.top() << endl;
		//y = y + st.pop();
		//cout << st.pop() << endl;
	//}
	//cout << y << endl;
	/*st.print();
	st.push(val = 4);
	st.push(val = 5);
	st.push(val = 6);
	st.print();

	st.clear();
	st.print();*/
	StackDLL<int> tempSt;
	//int val;
	int sum = 0;
	while (!st.isEmpty()) {
		val = st.pop();
		sum += val;
		tempSt.push(val);
	}
	cout << "The temp list: " << endl;
	tempSt.print();

	cout << "Sum is: " << sum;
	while (!tempSt.isEmpty()) {
		val = tempSt.pop();
		st.push(val);
	}
	cout << "The original list after: " << endl;
	st.print();
}