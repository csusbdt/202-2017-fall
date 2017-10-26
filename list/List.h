#pragma once

#include "Iterator.h"

class List {
public:
	List() : head(nullptr) {}
	~List() {}
	bool empty() const;
	int size() const;
	void push_back(int x);
	Iterator begin();
	Iterator end();
	void insert(Iterator it, int value);

private:
	Link * head;

};

