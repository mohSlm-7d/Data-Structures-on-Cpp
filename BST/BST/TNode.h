#pragma once
using namespace std;
template<class T>
class BST;
template<class T>
class TNode {
private:
	T data;
	TNode* left;
	TNode* right;
	int depth;
	int height;
	int total_below;
	friend class BST<T>;
public:
	TNode(T& data, TNode<T>* left, TNode<T>* right);
	~TNode();
	T getData();
	TNode* getLeft();
	TNode* getRight();
	int getDepth() { return depth; }
	int getHeight() { return height; }
	int getTotal_below() { return total_below; }
};
template <class T>
TNode<T>::TNode(T& data, TNode<T>* left, TNode<T>* right) {
	this->data = data;
	this->left = left;
	this->right = right;
}
template<class T>
TNode<T>::~TNode() {}
template<class T>
T TNode<T>::getData() {
	return data;
}
template<class T>
TNode<T>* TNode<T>::getLeft() {
	return left;
}
template<class T>
TNode<T>* TNode<T>::getRight() {
	return right;
}