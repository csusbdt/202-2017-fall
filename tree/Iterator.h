#pragma once

#include "Node.h"

/*! Iterator for the Tree class. */
class Iterator {
public:
	~Iterator() {}

	/*! Return reference to value. */
	int & operator*() const { return node->value; }

	/*! Return true if the 2 iterators refer to the same value. */
	bool operator==(const Iterator & it) { return it.node == node; }

	/*! Return true if the 2 iterators do not refer to the same value. */
	bool operator!=(const Iterator & it) { return it.node != node; }

	/*! Advnace the iterator to the next value. */
	Iterator & operator++();

private:
	/*! Construct iterator iitialized to point to given node.
	 *
	 *  This constructor made private because only the Tree class
	 *  should be able to create instances.
	 */
	Iterator(Node * node) : node(node) {}

	/*! node pointed to by this iterator */
	Node * node;

	friend class Tree;
};

