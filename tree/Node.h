#pragma once

/*! Helper class for the Tree class. */
class Node {
public:
	~Node() {}

private:
	/*! Construct iterator initialized to point to given node.
         *
         * \param parent  the parent node or null if root node
	 * \param value   the value to be stored in the node
	 *
	 *  Sets left and right nodes to null.
	 *
	 *  This constructor made private because only the Tree and Iterator
	 *  classes should be able to create node instances.
	 */
	Node(Node * parent, int value) 
	: parent(parent), value(value), left(nullptr), right(nullptr) {}

	/*! pointer to the parent node */
	Node * parent;

	/*! pointer to the left child node */
	Node * left; 

	/*! pointer to the right child node */
	Node * right;

	/*! value contained in the node */
	int value;

	friend class Tree;
	friend class Iterator;
};

