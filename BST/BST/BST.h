#pragma once
#include<iostream>
#include"TNode.h"
#include"DLL.h"
#include"QueueDLL.h"
#include"StackDLL.h"
using namespace std;

template<class T>
class BST {
private:
	TNode<T>* root;
	void inOrderDFT(TNode<T>* root);
	void postOrderDFT(TNode<T>* root);
	void preOrderDFT(TNode<T>* root);
	T sum(TNode<T>* root);
	int count(TNode<T>* root);
	bool searchRec(TNode<T>* root, T& val);
	void clearALL(TNode<T>* root);
	void preOrderDFTStack(TNode<T>* root);
	void delSingle(TNode<T>* k, TNode<T>* prev);
	void delDoubleByCopying(TNode<T>* k, TNode<T>* prev);
	void computeNodeDepth(TNode<T>* c, TNode<T>* par);
	void computeNodeHeight(TNode<T>* c);
	bool isBalanced(TNode<T>* c);
	void computeTotalBelow(TNode<T>* c);
public:
	BST();
	~BST();
	bool isEmpty();
	T min();
	T max();
	bool search(T& val);
	TNode<T>* getRoot();
	void insert(T& val);
	
	void inOrderDFT();
	void postOrderDFT();
	void preOrderDFT();
	void BFT();
	void preOrderDFTStack();
	T sum();
	int count();
	bool searchRec(T& val);
	bool delNode(T& val);
	void clearALL();
	void computeDepth();
	void computeHeight();
	bool isBalanced();
	void computeTotalBelow();
};
template<class T>
BST<T>::BST() {
	root = nullptr;
}
template<class T>
BST<T>::~BST() {
	clearALL();
}
template<class T>
bool BST<T>::isEmpty() {
	return root == nullptr;
}
template<class T>
T BST<T>::min() {
	if (isEmpty()) {
		throw("Empty");
	}

	TNode<T>* p = root;
	while (p->left != nullptr)
		p = p->left;
	return p->data;
}
template<class T>
T BST<T>::max() {
	if (isEmpty()) {
		throw("Empty");
	}

	TNode<T>* p = root;
	while (p->right != nullptr)
		p = p->right;
	return p->data;
}
template<class T>
bool BST<T>::search(T& val) {
	TNode<T>* p = root;
	while (p != nullptr) {
		if (p->data == val)
			return true;
		if (p->data > val)
			p = p->left;
		else
			p = p->right;
	}
	return false;
}
template<class T>
TNode<T>*BST<T>::getRoot() {
	return root;
}
template<class T>
void BST<T>::insert(T& val) {
	TNode<T>* n = new TNode<T>(val, nullptr, nullptr);
	if (isEmpty()) {
		root = n;
		return;
	}
	TNode<T>* p = root;
	TNode<T>* prev = nullptr;
	while (p != nullptr) {
		prev = p;
		if (p->data >= val)
			p = p->left;
		else
			p = p->right;
	}
	if (prev->data >= val)
		prev->left = n;
	else
		prev->right = n;
	
}
template<class T>
void BST<T>::inOrderDFT(TNode<T>* root) {
	if (root == nullptr)
		return;

	inOrderDFT(root->left);
	cout << root->data << ",";
	inOrderDFT(root->right);
}
template<class T>
void BST<T>::postOrderDFT(TNode<T>* root) {
	if (root == nullptr)
		return;

	postOrderDFT(root->left);
	postOrderDFT(root->right);
	cout << root->data << ",";
}
template<class T>
void BST<T>::preOrderDFT(TNode<T>* root) {
	if (root == nullptr)
		return;

	cout << root->data << ',';
	preOrderDFT(root->left);
	preOrderDFT(root->right);
}
template<class T>
void BST<T>::inOrderDFT() {
	inOrderDFT(root);
}
template<class T>
void BST<T>::postOrderDFT() {
	postOrderDFT(root);
}
template<class T>
void BST<T>::preOrderDFT() {
	preOrderDFT(root);
}
template<class T>
T BST<T>::sum(TNode<T>* root) {
	if (root == nullptr)
		return 0;
	return sum(root->left) + root->data + sum(root->right);
}
template<class T>
T BST<T>::sum() {
	return sum(root);
}
template<class T>
int BST<T>::count(TNode<T>* root) {
	if (root == nullptr)
		return 0;
	return count(root->left) + 1 + count(root->right);
}
template<class T>
int BST<T>::count() {
	return count(root);
}
template<class T>
bool BST<T>::searchRec(TNode<T>* root,T& val) {
	if (root == nullptr)
		return false;
	if (root->data == val)
		return true;

	if (root->data > val)
		return searchRec(root->left, val);
	else
		return searchRec(root->right, val);

}
template<class T>
bool BST<T>::searchRec(T& val) {
	return searchRec(root, val);
}
template<class T>
void BST<T>::clearALL(TNode<T>* root) {
	if (root == nullptr)
		return;
	clearALL(root->left);
	clearALL(root->right);
	delete root;
	//this->root = nullptr;
}
template<class T>
void BST<T>::clearALL() {
	clearALL(root);
	root = nullptr;
}
template<class T>
void BST<T>::BFT() {
	if (isEmpty())
		return;
	QueueDLL<TNode<T>*> q;
	q.enq(root);
	while (!q.isEmpty()) {
		TNode<T>* x = q.deq();
		cout << x->data << ",";
		if (x->left != nullptr)
			q.enq(x->left);
		if (x->right != nullptr)
			q.enq(x->right);
	}
	
}
template<class T>
void BST<T>::preOrderDFTStack(TNode<T>* root) {
	if (isEmpty())
		return;
	
	StackDLL<TNode<T>*> s;
	s.push(root);
	while (!s.isEmpty()) {
		TNode<T>* x = s.pop();
		cout << x->data << ",";
		if (x->right != nullptr)
			s.push(x->right);
		if (x->left != nullptr)
			s.push(x->left);
	}

}
template<class T>
void BST<T>::preOrderDFTStack()
{
	preOrderDFTStack(root);
}
template<class T>
bool BST<T>::delNode(T& val) {
	TNode<T>* prev = nullptr;
	TNode<T>* k = root;
	while (k != nullptr) {
		
		if (k->data == val) {
			break;
		}
		

		if (k->data < val) {
			prev = k;
			k = k->right;
		}
		else {
			prev = k;
			k = k->left;
		}
	}
	if (k == nullptr)
		return false;
	else {
		//delete...
		if (k->left == nullptr || k->right == nullptr) {
			delSingle(k, prev);
		}
		else {
			delDoubleByCopying(k, prev);
		}
		return true;
	}
}
template<class T>
void BST<T>::delSingle(TNode<T>* k, TNode<T>* prev) {
	if (k == root) {// if( prev == nullptr )
		if (k->left != nullptr) {
			root = root->left;
		}
		else {
			root = root->right;			
		}
		delete k;
		return;
	}
	if (prev->left == k) {
		if (k->left != nullptr) {
			prev->left = k->left;
		}
		else {
			prev->left = k->right;
		}
	}
	else {
		if (k->left != nullptr) {
			prev->right = k->left;
		}
		else {
			prev->right = k->right;
		}
	}
	delete k;
}
template<class T>
void BST<T>::delDoubleByCopying(TNode<T>* k, TNode<T>* prev) {
	/*TNode<T> predPrev = k;
	TNode<T>* p = k->left;
	while (p->right != nullptr) {
		prePrev = p;
		p = p->right;
	}
	k->data = p->data;
	delSingle(p, predPrev);*/

	TNode<T>* succssPrev = k;
	TNode<T>* p = k->right;
	while (p->left != nullptr) {
		succssPrev = p;
		p = p->left;
	}
	k->data = p->data;
	delSingle(p, succssPrev);
}
template<class T>
void BST<T>::computeDepth() {
	computeNodeDepth(root, nullptr);
}
template<class T>
void BST<T>::computeNodeDepth(TNode<T>* c, TNode<T>* par) {
	if (c == nullptr)
		return;
	if (c == root)
		c->depth = 0;
	else {
		c->depth = par->depth + 1;
	}
	computeDepth(c->left, c);
	computeDepth(c->right, c);
}
template<class T>
void BST<T>::computeHeight() {
	computeNodeHeight(root);
}
template <class T> 
void BST<T>::computeNodeHeight(TNode<T>* c) {
	if (c == nullptr)
		return;
	computeNodeHeight(c->left);
	computeNodeHeight(c->right);

	int LH = -1, RH = -1;

	if (c->left != nullptr)
		LH = c->left->height;

	if (c->right != nullptr)
		RH = c->right->height;

	if (LH > RH)
		c->height = LH + 1;
	else
		c->height = RH + 1;
}
template<class T>
void BST<T>::computeTotalBelow() {
	computeTotalBelow(root);
}
template<class T>
void BST<T>::computeTotalBelow(TNode<T>* c){
	if (c == nullptr)
		return;

	computeTotalBelow(c->left);
	computeTotalBelow(c->right);

	int totalR = 0, totalL = 0;

	if (c->left != nullptr)
		totalL = c->left->total_below + c->left->data;

	if (c->right != nullptr)
		totalR = c->right->total_below + c->right->data;

	c->total_below = totalL + totalR;
}
template<class T>
bool BST<T>::isBalanced() {
	computeHeight();
	return isBalanced(root);
}
template<class T>
bool BST<T>::isBalanced(TNode<T>* c) {
	if (c == nullptr)
		return true;
	int LH = -1, RH = -1;
	if (c->left != nullptr)
		LH = c->left->height;

	if (c->right != nullptr)
		RH = c->right->height;
	
	int BF = LH - RH;
	if (BF < -1 || BF > 1)
		return false;

	return (isBalanced(c->left) && isBalanced(c->right));
}
