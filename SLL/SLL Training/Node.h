#pragma once
class Node {
public:
	int data;
	Node* next;
	Node(int data, Node* next);
	~Node();
};
Node::Node(int data, Node* next) {
	this->data = data;
	this->next = next;
}
Node::~Node(){}