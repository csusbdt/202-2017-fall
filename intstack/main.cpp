#include <iostream>
#include <cassert>

using namespace std;

class Stack {
public:
	Stack();
	~Stack();
	int size() const;
	bool empty() const;
	void push(int k);  // add an element to the top
	void pop();        // remove top element
	int & top();       // access the top element

private:
	void ensureCapacity(int c);

	int * data;
	int capacity;  // capacity of data array
	int n;         // number of elements in stack
};

// Optional constructor with initialization list.
//Stack::Stack() : data(nullptr), capacity(0), n(0) {
//}

Stack::Stack() {
	data = nullptr;
	capacity = 0;
	n = 0;
}

Stack::~Stack() {
	// The following if is not need because ok to delete nullptr.
	//if (data != nullptr) {   
		delete [] data;
	//}
}

void Stack::ensureCapacity(int c) {
	if (capacity >= c) return;
	int * oldData = data;
	data = new int[c];
	for (int i = 0; i < n; ++i) {
		data[i] = oldData[i];
	}
	delete [] oldData;
	capacity = c;
}

bool Stack::empty() const {
	return n == 0;
}

int Stack::size() const {
	return n;
}

void Stack::push(int k) {
	ensureCapacity(n + 1);
	data[n++] = k;
}

void Stack::pop() {
	--n;
}

int & Stack::top() {
	return data[n - 1];
}

int main(int argc, char * args[]) {
	Stack s;
	assert(s.empty());
	assert(s.size() == 0);
	s.push(20);
	assert(not s.empty());
	assert(s.size() == 1);
	assert(s.top() == 20);
	s.pop();	
	assert(s.empty());
	assert(s.size() == 0);

	s.push(11);
	assert(not s.empty());
	assert(s.size() == 1);
	assert(s.top() == 11);
	s.push(22);
	assert(not s.empty());
	assert(s.size() == 2);
	assert(s.top() == 22);
	s.pop();	
	assert(not s.empty());
	assert(s.size() == 1);
	assert(s.top() == 11);
	s.push(2);
	assert(not s.empty());
	assert(s.size() == 2);
	assert(s.top() == 2);
	s.push(3);
	assert(not s.empty());
	assert(s.size() == 3);
	assert(s.top() == 3);

	cout << "All tests passed." << endl;
}

