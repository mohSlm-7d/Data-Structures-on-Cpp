#pragma once
using namespace std;
template<class T>
class QueueArray {
private:
	T* data;
	int cap;
	int size;
	int first, last;
public:
	QueueArray(int cap = 100);
	~QueueArray();
	void enq(T& x);
	T deq();
	T getFirst();
	T getLast();
	bool isEmpty();
	bool isFull();
	void clear();
	void print();
	//Extra functions(methods)
	void resize(int factor);
	void enq1(T& x);
	void normalize();
	void memOpt();
	int getSize();
	void Filter(T& val1, T& val2);
};
template<class T>
QueueArray<T>::QueueArray(int cap) {
	this->cap = cap;
	data = new T[this->cap];
	size = 0;
	first = last = -1;
}
template <class T>
QueueArray<T>::~QueueArray() {
	delete[] data;
}
template<class T>
bool QueueArray<T>::isEmpty() {
	return (first == -1 && last == -1);
}
template<class T>
bool QueueArray<T>::isFull() {
	//return size == cap;
	/*if (isEmpty())
		return false;
	if (first <= last) {
		return (last - first + 1) == cap;
	}
	else {
		return(last + 1) == first;
	}*/
	return (last + 1) % cap == first;
}
template<class T>
void QueueArray<T>::enq(T& x) {
	if (isFull()) {
		cout << "\nSorry\n";
		return;
	}
	if (isEmpty()) {
		first = last = 0;
	}
	else {
		last = (last + 1) % cap;
	}
	data[last] = x;
	size++;
}
template<class T>
T QueueArray<T>::deq() {
	if (isEmpty()) {
		throw("Sorry");
	}
	T value = data[first];
	if (first == last) {
		first = last = -1;
	}
	else {
		first = (first + 1) % cap;
	}
	size--;
	return value;
}
template<class T>
T QueueArray<T>::getFirst() {
	if (isEmpty())
		throw("\nSorry.\n");

	return data[first];
}
template<class T>
T QueueArray<T>::getLast() {
	if (isEmpty())
		throw("\nSorry.\n");

	return data[last];
}
template<class T>
void QueueArray<T>::clear() {
	first = last = -1;
	size = 0;
}
template<class T>
void QueueArray<T>::print() {
	cout << "First= " << first << "  Last= " << last << "  Size= " << size << "/" << cap << endl;
	cout << "The list: ";
	
	if (isEmpty()) {
		return;
	}
	
	if (first <= last) {
		for (int i = first; i <= last; i++) {
			cout << data[i] << " ,";
		}
	}
	else {
		for (int i = first; i < cap; i++) {
			cout << data[i] << " ,";
		}
		for (int i = 0; i <= last; i++) {
			cout << data[i] << " ,";
		}
	}
	cout << endl << "==============" << endl;
	//method 2
	/*int i = first;
	while (i != last) {
		cout << data[i] << " ,";
		i = (i + 1) % cap;
	}
	cout << data[i] << "." << endl;*/
}
//Extra functions(methods)
template<class T>
void QueueArray<T>::resize(int factor) {
	int newCap = cap * factor;
	T* A = new T[newCap];

	int  i = 0, j = first;	
	while (j != last) {
		A[i] = data[j];
		j = (j + 1) % cap;
		i++;
	}
	A[i] = data[last];
	
	delete data;
	data = A;
	cap = newCap;

	first = 0;
	last = i;
	

	/*int j = 0;
	if (first <= last) {
		for (int i = first; i <= last; i++) {
			A[j++] = data[i];
		}
	}
	else {
		for (int i = first; i < cap; i++) {
			A[j++] = data[i];
		}
		for (int i = 0; i <= last; i++) {
			A[j++] = data[i];
		}
	}

	delete data;
	data = A;
	cap = newCap;

	first = 0;
	last = j - 1;*/
}
template<class T>
void QueueArray<T>::enq1(T& x) {	
	if (isFull()) { resize(2); }

	if (isEmpty()) {
		first = last = 0;
	}
	else{
		last = (last + 1) % cap;
	}
	data[last] = x;
	size++;
}
template <class T>
void QueueArray<T>::normalize() {
	T* A = new T[cap];

	int j = 0;
	if (first <= last) {
		for (int i = first; i <= last; i++) {
			A[j++] = data[i];
		}
	}
	else {
		for (int i = first; i < cap; i++) {
			A[j++] = data[i];
		}
		for (int i = 0; i <= last; i++) {
			A[j++] = data[i];
		}
	}

	delete data;
	data = A;

	first = 0;
	last = j - 1;
}
template<class T>
void QueueArray<T>::memOpt() {
	int newCap = cap * 0.5;
	if (size < newCap) {
		T* A = new T[newCap];

		int j = 0;
		if (first <= last) {
			for (int i = first; i <= last; i++) {
				A[j++] = data[i];
			}
		}
		else {
			for (int i = first; i < cap; i++) {
				A[j++] = data[i];
			}
			for (int i = 0; i <= last; i++) {
				A[j++] = data[i];
			}
		}

		delete data;
		data = A;
		cap = newCap;

		first = 0;
		last = j - 1;
	}
	else {
		cout << "Sorry can't do memOpt." << endl;
	}
}
template<class T>
int QueueArray<T>::getSize() {
	if (first == -1)return 0;
	if (first <= last) {
		return last - first + 1;
	}
	else {
		return  cap - (first - last - 1);
	}
}
template<class T>
void QueueArray<T>::Filter(T& val1, T& val2) {
	T* A = new T[cap];

	int j = 0;
	if (first <= last) {
		for (int i = first; i <= last; i++) {
			if (data[i] >= val1 && data[i] <= val2)
				A[j++] = data[i];
		}
	}
	else {
		for (int i = first; i < cap; i++) {
			if (data[i] >= val1 && data[i] <= val2)
				A[j++] = data[i];
		}
		for (int i = 0; i <= last; i++) {
			if (data[i] >= val1 && data[i] <= val2)
				A[j++] = data[i];
		}
	}

	delete data;
	data = A;

	first = 0;
	last = j - 1;
	size = last + 1;
}