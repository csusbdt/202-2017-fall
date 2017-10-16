#pragma once

#include "Node.h"
#include "Iterator.h"

/*! Binary search tree to store integers.
 *
 *  This implementation of the tree data structure is organized
 *  into three collaborating classes: Tree, Node, Iterator.
 */
class Tree {
public:
	/*! Create a tree with no values. */
	Tree() : root(nullptr) {}

	/*! Delete tree and all its values. */
	~Tree();

	/*! Return true if tree contains no values. */
	bool empty() const { return root == nullptr; }

	/*! Return the number of nodes in the tree. */
	int size() const;

	/*! Return the number of nodes in the tree. */
	void insert(int value);

	/*! Return iterator pointing to the smallest value in tree.
	 *  Iteration goes from smallest to largest value.
	 */
	Iterator begin() const;

	/*! Return iterator pointing to "one past the largest value." */
	Iterator end() const;

	/*! Remove all values from the tree. */
	void erase(Iterator it);

private:
	/*! Recursively count the nodes under subtree */
	int countNodes(Node * subtree) const;

	/*! Recursively delete the nodes under subtree */
	void deleteSubtree(Node * subtree);

	/*! The node currently pointed to by this iterator */
	Node * root; 
};

