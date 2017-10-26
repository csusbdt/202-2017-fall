#include "Iterator.h"

int & Iterator::operator*() {
	assert(link != nullptr);
	return link->value;
}

void Iterator::operator++() {
	assert(link != nullptr);
	link = link->next;
}

