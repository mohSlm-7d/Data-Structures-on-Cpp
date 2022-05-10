#include<iostream>
#include"TNode.h"
#include"BST.h"
using namespace std;
void main() {
	BST<int> bst1;
	int x;
	/*bst1.insert(x = 0);
	bst1.insert(x = 2);
	bst1.insert(x = 10);
	bst1.insert(x = 7);
	bst1.insert(x = 8);
	bst1.insert(x = 5);
	bst1.insert(x = 4);*/
	bst1.insert(x = 7);
	bst1.insert(x = 9);
	bst1.insert(x = 3);
	bst1.insert(x = -1);
	bst1.insert(x = 5);
	bst1.insert(x = 6);
	bst1.insert(x = 4);
	bst1.insert(x = 8);
	bst1.insert(x = 10);
	bst1.insert(x = 11);	
	bst1.insert(x = 12);
	//bst1.insert(x = 13);
	//bst1.insert(x = 3);
	/*bst1.inOrderDFT(bst1.getRoot());
	cout << endl << "preOrderDFT: ";
	bst1.preOrderDFT(bst1.getRoot());
	cout << endl << "postOrderDFT: ";
	bst1.postOrderDFT(bst1.getRoot());*/

	/*cout << "inOrderDFT: ";
	bst1.inOrderDFT();
	cout << endl << "preOrderDFT: ";
	bst1.preOrderDFT();
	cout << endl << "postOrderDFT: ";
	bst1.postOrderDFT();
	cout << endl << endl;

	cout << bst1.sum() << endl;
	cout << bst1.count() << endl;
	//cout << bst1.searchRec(x = 8);
	//bst1.clearALL();
	bst1.inOrderDFT();*/
	bst1.BFT();
	/*cout << endl;
	bst1.preOrderDFTStack();
	cout << endl << bst1.delNode(x = 5) << endl;
	bst1.BFT();*/
	/*while (!bst1.isEmpty()) {
		x = bst1.getRoot()->getData();
		cout << "NEW ROOT: " << x << endl;
		bst1.delNode(x);
		bst1.BFT();
		cout << endl << endl;
		bst1.inOrderDFT();
	}*/
	bst1.computeHeight();
	cout << endl << endl;
	cout << bst1.getRoot()->getHeight();
	bst1.computeTotalBelow();
	cout << endl << "Total Below: " << bst1.getRoot()->getTotal_below();

	cout << endl << endl;
	cout << bst1.isBalanced();
}