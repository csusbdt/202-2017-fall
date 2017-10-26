#pragma once

class Link {
public:
	Link(int value, Link * next = nullptr)
	: value(value), next(next) {}

private:
	Link * next;
	int value;

	friend class List;
	friend class Iterator;
};

