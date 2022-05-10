#include<iostream>
#include"StackArray.h"
using namespace std;
/*template <class T>class Test {
public:
	void print(StackArray<T>& STS) {
		for (int i = 0; i < STS.cap; i++)
			cout << STS.A[i] << endl;
	}
};*/
void main() {
	StackArray<int> st(4);
	int array[] = { 1 ,2,3,4,5 };
	int x;
	st.push(x = 5);
	st.push(x = 6);
	st.push(x = 7);
	st.push(x = 8);
	st.print();
	StackArray<int> st1(4);
	while (!st.isEmpty()) {
		x = st.pop();
		//if (x % 2 == 0)
			//st1.push(x);
		st1.push(x);
		//cout << x << endl;
	}
	cout << st1.top() << endl << endl;
	while (!st1.isEmpty()) {
		x = st1.pop();
		st.push(x);
	}
	cout << st.top() << endl;
	//st.print();
	//st1.print();
	/*x = st.pop();
	cout << st.top();
	st.push(x);
	st.print();*/
	/*for (int i = 0; i < 4; i++)
		st.push(array[i]);
	st.print();
	st.pop();
	st.print();
	st.top();
	st.print();
	st.clear();
	st.push(x = 3);
	st.print();*/
	//st.push(x = 5);
	/*st.pop();
	st.pop();
	st.pop(); st.print();*/
	
	/*try {
		st.pop();
	}
	catch (const char* Exception) { cout << Exception; }*/
	//st.clear();
	//st.print();
}