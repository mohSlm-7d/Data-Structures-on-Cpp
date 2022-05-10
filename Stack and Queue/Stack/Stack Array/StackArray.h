#pragma once
using namespace std;
//template <class T>class Test;
template<class T>
class StackArray {
	//friend class Test<T>;
private:
	T* A;
	int cap;
	int L;
public:
	StackArray(int cap=100);
	~StackArray();
	void push(T& data);
	T pop();
	T top();
	bool isEmpty();
	bool isFull();
	void clear();
	void print();
};
template<class T>
StackArray<T>::StackArray(int cap) {
	this->cap = cap;
	A = new T[this->cap];
	L = -1;
}
template <class T>
StackArray<T>::~StackArray() {
	delete[] A;
}
template<class T>
void StackArray<T>::push(T& data) {
	if (!isFull())
		A[++L] = data;
	else
		cout << "\nSorry can't push in a full stack." << endl;
}
template<class T>
T StackArray<T>::pop() {
	if (!isEmpty())
		return A[L--];
	else
		throw("\nSorry can't pop from an empty stack.\n");
}
template<class T>
T StackArray<T>::top() {
	if (!isEmpty())
		return A[L];
	else
		throw("\nSorry the stack is empty.\n");
}
template<class T>
bool StackArray<T>::isEmpty() {
	return L == -1;
}
template<class T>
bool StackArray<T>::isFull() {
	return L == cap - 1;
}
template<class T>
void StackArray<T>::clear() {
	L = -1;
}
template<class T>
void StackArray<T>::print() {
	cout << "The list: ";
	for (int i = 0; i <= L; i++) {
		cout << A[i] << ", ";
	}
	cout << "." << endl;
}