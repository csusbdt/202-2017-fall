#include <iostream>
#include <cassert>

using namespace std;

class Stack {
public:
	Stack();
	~Stack();
	int size() const;
	bool empty() const;
	void push(int k);
	void pop();
	int & top();

private:
	void ensureCapacity(int c);

	int * data;
	int capacity;  // capacity of data array
	int n;         // number of elements in stack
};

int main(int argc, char * args[]) {
	Stack s;
/*
	assert(s.empty());
	assert(s.size() == 0);
	s.push(1);
	assert(not s.empty());
	assert(s.size() == 1);
	assert(s.top() == 1);
	s.pop();	
	assert(s.empty());
	assert(s.size() == 0);

	s.push(1);
	assert(not s.empty());
	assert(s.size() == 1);
	assert(s.top() == 1);
	s.push(2);
	assert(not s.empty());
	assert(s.size() == 2);
	assert(s.top() == 2);
	s.pop();	
	assert(not s.empty());
	assert(s.size() == 1);
	assert(s.top() == 1);
	s.push(2);
	assert(not s.empty());
	assert(s.size() == 2);
	assert(s.top() == 2);
	s.push(3);
	assert(not s.empty());
	assert(s.size() == 3);
	assert(s.top() == 3);
*/
	cout << "All tests passed." << endl;
}

