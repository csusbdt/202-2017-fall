#pragma once

#include "Link.h"

class Iterator {
public:
	Iterator() {}
	void operator++();
	void operator--();
	int & operator*();

private:
	Link * link;

};

