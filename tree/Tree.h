#pragma once

#include "Node.h"
#include "Iterator.h"

class Tree {
public:
	Tree() : root(nullptr) {}
	~Tree();
	bool empty() const { return root == nullptr; }
	int size() const;
	void insert(int value);
	Iterator begin() const;
	Iterator end() const;
	void erase(Iterator it);

private:
	int countNodes(Node * node) const;
	void deleteSubtree(Node * n);

	Node * root;
};

