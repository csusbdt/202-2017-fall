#include <iostream>
#include <cassert>
#include "List.h"

using namespace std;

int main() {
	List a;
	assert(a.empty() == true);
	a.push_back(17);
	assert(a.empty() == false);
/*
	a.push_front(3);
	a.push_back(10);
	assert(a.size() == 3);
	list<int>::iterator it = a.begin();	
	assert(*it == 3);
	++it;
	assert(*it == 17);
	++it;
	assert(*it == 10);
	++it;
	assert(it == a.end());

	it = a.begin();
	assert(*it == 3);
	*it += 1;
	cout << *it << endl;
*/
	cout << "All tests passed." << endl;
}

