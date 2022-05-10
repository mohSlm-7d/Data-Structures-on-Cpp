#pragma once
#include"DNode.h"
#include"DLL.h"
template<class T>
class Hash {
private:
	DLL<T>* data;
	int size;
	int computeHash(T& val);
public:
	Hash(int size=100);
	~Hash();
	bool search(T& val);
	void insert(T& val);
	bool del(T& val);
	void print();

};
template<>
int Hash<int>::computeHash(int& val)
{
	return 0;
}
template<class T>
Hash<T>::Hash(int size) {
	this->size = size;
	data = new DLL<T>[this->size];
}
template<class T>
Hash<T>::~Hash() {
	for (int i = 0; i < size; i++)
		data[i].clearAll();
	
	delete[] data;
}
template<class T>
void Hash<T>::insert(T& val) {
	int indx = computeHash(val);
	data[indx].addTail(val);
}
template<class T>
bool Hash<T>::search(T& val) {
	int indx = computeHash(val);

	if (data[i].search(val))
		return true;
	else
		return false;
}
template<class T>
void Hash<T>::print() {
	for (int i = 0; i < size; i++) {
		if (!data[i].isEmpty()) {
			cout << "bucket: " << i + ": ";
			data[i].print();
			cout << endl;
		}
	}
}
template<class T>
bool Hash<T>::del(T& val) {
	int indx = computeHash(val);

	return data[indx].delNode(val);
}
template<>
int Hash<int>::computeHash(int& val) {
	return val % size;
}
template<>
int Hash<string>::computeHash(string& val) {
	int asciiSum = 0;
	
	for (int i = 0; i < val.length(); i++) {
		asciiSum = asciiSum + val[i];
	}

	return asciiSum % size;
}