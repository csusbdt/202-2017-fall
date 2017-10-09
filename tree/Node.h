#pragma once

class Node {
public:
	Node(Node * parent, int value) 
	: parent(parent), value(value), left(nullptr), right(nullptr) {}
	~Node() {}

private:
	Node * parent;
	Node * left; 
	Node * right;
	int value;

	friend class Tree;
	friend class Iterator;
};

