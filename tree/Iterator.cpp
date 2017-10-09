#include <iostream>
#include <cassert>

#include "Iterator.h"

using namespace std;

// Go to the node with the next larger value.
Iterator & Iterator::operator++() {
	// If there is a right branch, then go to right child and
	// then slide left;
	if (node->right != nullptr) {
		node = node->right;
		while (node->left != nullptr) node = node->left;
		return *this;
	}

	// We have no right child. 
	assert(node->right == nullptr);

	// If we're root then we're at the end.
	if (node->parent == nullptr) {
		node = nullptr;
		return *this;
	}

	// If I am the left child of my parent then the parent
	// contains the next larger value;
	if (node == node->parent->left) {
		node = node->parent;
		return *this;
	}

	// I am the right child of my parent (or I'm the root node).
	// The next largest value is at the parent of the nearest
	// grand parent who is a left child of its parent. 

	// Slide upwards until we find ourselves at the root of a left subtree.
        // If we hit the root of the tree, then return the end iterator.
	while (node == node->parent->right) {
		node = node->parent;
		if (node->parent == nullptr) {
			node = nullptr;
			return *this; 
		}
	}

	// I am the left child of my parent, so go to it and we're done.
	assert(node->parent->left == node);
	node = node->parent;
	return *this;
}

