#include <iostream>
#include "List.h"

bool List::empty() const {
	return head == nullptr;
}

int List::size() const {
	Link * link = head;
	int count = 0;
	while (link != nullptr) {
		++count;
		link = link->next;
	}
	return count;
}

void List::push_back(int x) {
	if (head == nullptr) {
		head = new Link(x);
	} else {
		Link * link = head;
		while (link->next != nullptr) {
			link = link->next;
		}
		link->next = new Link(x);
	}
}

Iterator List::begin() {
	return Iterator(head);
}

Iterator List::end() {
	return Iterator(nullptr);
}

void List::insert(Iterator it, int value) {
	assert(it.link != nullptr);
	if (it.link == head) {
		head = new Link(value, head);
		return;
	}
	Link * prev = head;
	while (prev->next != it.link) {
		prev = prev->next;
	}
	prev->next = new Link(x, it.link);
}

