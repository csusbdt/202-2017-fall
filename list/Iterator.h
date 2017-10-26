#pragma once

#include "Link.h"

class Iterator {
public:
	Iterator(Link * link) : link(link) {}
	void operator++();
	int & operator*();

private:
	Link * link;

	friend class List;
};

