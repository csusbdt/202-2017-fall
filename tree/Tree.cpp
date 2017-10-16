#include <cassert>
#include <iostream>

#include "Tree.h"

using namespace std;

// recursively delete all nodes.
void Tree::deleteSubtree(Node * subtree) {
	if (subtree != nullptr) {
		deleteSubtree(subtree->left);
		deleteSubtree(subtree->right);
	}
	delete subtree;
}

// Recursively count the number of nodes in the tree.
int Tree::countNodes(Node * subtree) const {
	if (subtree == nullptr) return 0;
	else return 1 + countNodes(subtree->left) + countNodes(subtree->right);
}

Tree::~Tree() {
	deleteSubtree(root);
}

Iterator Tree::begin() const {
	if (root == nullptr) return Iterator(nullptr);
	Node * node = root;
	while (node->left != nullptr) node = node->left;
	return Iterator(node);
}

Iterator Tree::end() const { 
	return Iterator(nullptr); 
}

int Tree::size() const {
	return countNodes(root);
}

void Tree::insert(int value) {
	// If tree is empty, then put value in root.
	if (root == nullptr) {
		root = new Node(nullptr, value);
		return;
	}

	// Attach new node as a leaf.
	// Start search from the root node.

	Node * node = root;
	Node * parent = node->parent;
	assert(parent == nullptr);

	bool makeLeftChild = false;
	while (node != nullptr) {
		if (value < node->value) {
			parent = node;
			node = node->left;
			makeLeftChild = true; 
		} else if (value > node->value) {
                        parent = node;
                        node = node->right;
			makeLeftChild = false; 
		} else {
			assert(value == node->value);
			return;
		}
	}
	assert(node == nullptr);
	node = new Node(parent, value);
	if (makeLeftChild) {
		parent->left = node;
	} else {
		parent->right = node;
	}
}

void Tree::erase(Iterator it) {
	Node * n = it.node;

	if (n == root) {
		if (n->left == nullptr and n->right == nullptr) {
			root = nullptr;
		} else if (n->left == nullptr and n->right != nullptr) {
			n->right->parent = nullptr;
			root = n->right;
		} else if (n->left != nullptr and n->right == nullptr) {
			n->left->parent = nullptr;
			root = n->left;
		} else {
			assert(n->left != nullptr and n->right != nullptr);
			n->left->parent = nullptr;
			root = n->left;
			// Slide right on the new root and attach
			// the right subtree of n to it.
			Node * k = n->left;
			while (k->right != nullptr) k = k->right;
			n->right->parent = k;
			k->right = n->right;
		}
	} else {
		assert(n != root);
		Node * p = n->parent;
		if (n->left == nullptr and n->right == nullptr) {
			if (n == p->left) p->left = nullptr;
			else p->right = nullptr;
		} else if (n->left == nullptr and n->right != nullptr) {
			n->right->parent = p;
			if (n == p->left) p->left = n->right;
			else p->right = n->right;
		} else if (n->left != nullptr and n->right == nullptr) {
			n->left->parent = p;
			if (n == p->left) p->left = n->left;
			else p->right = n->left;
		} else {
			assert(n->left != nullptr and n->right != nullptr);
			// Attach n's left subtree to n's parent.
			n->left->parent = p;
			if (n == p->left) p->left = n->left;
			else p->right = n->left;
			// Attach n's right subtree to the rightmost point
			// of n's left subtree. 
			Node * k = n->left;
			while (k->right != nullptr) k = k->right;
			n->right->parent = k;
			k->right = n->right;
		}
	}
	delete n;
}

