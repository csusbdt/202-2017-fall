#pragma once

#include "Node.h"

class Iterator {
public:
	Iterator(Node * node) : node(node) {}
	~Iterator() {}
	int & operator*() const { return node->value; }
	bool operator==(const Iterator & it) { return it.node == node; }
	bool operator!=(const Iterator & it) { return it.node != node; }
	Iterator & operator++();

private:
	Node * node;

	friend class Tree;
};

