#include <iostream>
#include <cassert>
#include "List.h"

using namespace std;

void test1() {
	List a;
	assert(a.empty() == true);
	assert(a.size() == 0);

	a.push_back(1);
	assert(a.empty() == false);
	assert(a.size() == 1);

	Iterator it = a.begin();
	assert(*it == 1);
	++it;
	assert(it == a.end());

	it = a.begin();
	a.insert(it, 0);
	it = a.begin();
	assert(*it == 0);
	++it;
	assert(*it == 1);
	++it;
	assert(it == a.end());
}

test2() {
	List a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(4);
	Iterator it = a.begin();
	++it;
	++it;
	assert(*it == 4);
	a.insert(it, 3);
	it = a.begin();
	assert(*it == 1);
	++it;
	assert(*it == 2);
	++it;
	assert(*it == 3);
	++it;
	assert(*it == 4);
	++it;
	assert(it == a.end());
}

int main() {
	test1();

	cout << "All tests passed." << endl;
}

