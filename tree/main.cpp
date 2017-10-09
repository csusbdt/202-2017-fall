#include <iostream>
#include <cassert>

#include "Tree.h"

using namespace std;

void test1() {
	Tree t;
	assert(t.size() == 0);
	t.insert(-9);
	assert(t.size() == 1);
	Iterator it = t.begin();
	assert(*it == -9); 
	++it;
	assert(it == t.end());
	it = t.begin();
	t.erase(it);
	assert(t.size() == 0);
}

void test2() {
	Tree t;
	t.insert(-9);
	t.insert(-7);
	assert(t.size() == 2);
	Iterator it = t.begin();
	assert(*it == -9); 
	++it;
	assert(*it == -7); 
	++it;
	assert(it == t.end());
	it = t.begin();
	assert(*it == -9); 
	t.erase(it);
	assert(t.size() == 1);
	it = t.begin();
	assert(*it == -7); 
	t.erase(it);
	assert(t.size() == 0);
}

void test3() {
	Tree t;
	t.insert(-7);
	t.insert(-9);
	assert(t.size() == 2);
	Iterator it = t.begin();
	assert(*it == -9); 
	++it;
	assert(*it == -7); 
	++it;
	assert(it == t.end());
	it = t.begin();
	assert(*it == -9); 
	t.erase(it);
	assert(t.size() == 1);
	it = t.begin();
	assert(*it == -7); 
	t.erase(it);
	assert(t.size() == 0);
}

void test4() {
	Tree t;
	t.insert(0);
	t.insert(0);
	assert(t.size() == 1);
}

void test5() {
	Tree t;
	t.insert( 0);
	t.insert(-4);
	t.insert( 4);
	t.insert(-8);
	t.insert(-2);
	t.insert( 2);
	t.insert( 8);
	assert(t.size() == 7);
	Iterator it = t.begin();
	assert(*it == -8); ++it;
	assert(*it == -4); ++it;
	assert(*it == -2); ++it;
	assert(*it ==  0); ++it;
	assert(*it ==  2); ++it;
	assert(*it ==  4); ++it;
	assert(*it ==  8); ++it;
	assert(it == t.end());
}

void test6() {
	Tree t;
	t.insert( 0);
	t.insert(-4);
	t.insert( 4);
	t.insert(-8);
	t.insert(-2);
	t.insert( 2);
	t.insert( 8);
	Iterator it = t.begin();
	t.erase(it);
	it = t.begin();
	assert(*it == -4); ++it;
	assert(*it == -2); ++it;
	assert(*it ==  0); ++it;
	assert(*it ==  2); ++it;
	assert(*it ==  4); ++it;
	assert(*it ==  8); ++it;
	assert(it == t.end());
}

void test7() {
	Tree t;
	t.insert( 0);
	t.insert(-4);
	t.insert( 4);
	t.insert(-8);
	t.insert(-2);
	t.insert( 2);
	t.insert( 8);
	Iterator it = t.begin();
	++it;
	t.erase(it);
	it = t.begin();
	assert(*it == -8); ++it;
	assert(*it == -2); ++it;
	assert(*it ==  0); ++it;
	assert(*it ==  2); ++it;
	assert(*it ==  4); ++it;
	assert(*it ==  8); ++it;
	assert(it == t.end());
}

void test8() {
	Tree t;
	t.insert( 0);
	t.insert(-4);
	t.insert( 4);
	t.insert(-8);
	t.insert(-2);
	t.insert( 2);
	t.insert( 8);
	Iterator it = t.begin();
	++it;
	++it;
	t.erase(it);
	it = t.begin();
	assert(*it == -8); ++it;
	assert(*it == -4); ++it;
	assert(*it ==  0); ++it;
	assert(*it ==  2); ++it;
	assert(*it ==  4); ++it;
	assert(*it ==  8); ++it;
	assert(it == t.end());
}

void test9() {
	// This test exposed a bug.
	Tree t;
	t.insert( 0);
	t.insert(-4);
	t.insert( 4);
	t.insert(-8);
	t.insert(-2);
	t.insert( 2);
	t.insert( 8);
	Iterator it = t.begin();
	++it;
	++it;
	++it;
	t.erase(it);
	it = t.begin();
	assert(*it == -8); ++it;
	assert(*it == -4); ++it;
	assert(*it == -2); ++it;
	assert(*it ==  2); ++it;
	assert(*it ==  4); ++it;
	assert(*it ==  8); ++it;
	assert(it == t.end());
}

void test10() {
	Tree t;
	t.insert( 0);
	t.insert(-4);
	t.insert( 4);
	t.insert(-8);
	t.insert(-2);
	t.insert( 2);
	t.insert( 8);
	Iterator it = t.begin();
	++it;
	++it;
	++it;
	++it;
	t.erase(it);
	it = t.begin();
	assert(*it == -8); ++it;
	assert(*it == -4); ++it;
	assert(*it == -2); ++it;
	assert(*it ==  0); ++it;
	assert(*it ==  4); ++it;
	assert(*it ==  8); ++it;
	assert(it == t.end());
}

void test11() {
	Tree t;
	t.insert( 0);
	t.insert(-4);
	t.insert( 4);
	t.insert(-8);
	t.insert(-2);
	t.insert( 2);
	t.insert( 8);
	Iterator it = t.begin();
	++it;
	++it;
	++it;
	++it;
	++it;
	t.erase(it);
	it = t.begin();
	assert(*it == -8); ++it;
	assert(*it == -4); ++it;
	assert(*it == -2); ++it;
	assert(*it ==  0); ++it;
	assert(*it ==  2); ++it;
	assert(*it ==  8); ++it;
	assert(it == t.end());
}

void test12() {
	Tree t;
	t.insert( 0);
	t.insert(-4);
	t.insert( 4);
	t.insert(-8);
	t.insert(-2);
	t.insert( 2);
	t.insert( 8);
	Iterator it = t.begin();
	++it;
	++it;
	++it;
	++it;
	++it;
	++it;
	t.erase(it);
	it = t.begin();
	assert(*it == -8); ++it;
	assert(*it == -4); ++it;
	assert(*it == -2); ++it;
	assert(*it ==  0); ++it;
	assert(*it ==  2); ++it;
	assert(*it ==  4); ++it;
	assert(it == t.end());
}

int main(int argc, char * arg[]) {
	test1();	
	test2();	
	test3();	
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	test11();
	test12();
	std::cout << "All tests passed." << std::endl;
}

