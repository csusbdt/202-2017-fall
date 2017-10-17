#pragma once

#include "Iterator.h"

class List {
public:
	List() {}
	~List() {}
	bool empty() const;
	void push_back(int x);
	Iterator begin();
	Iterator end();

private:

};

