#include <iostream>
#include <cassert>

using namespace std;

class Animal {
public:
    virtual string speak() const = 0;
};

class Cat : public Animal {
public: 
        virtual string speak() const;
};

class Dog : public Animal {
public: 
        virtual string speak() const;
};

string Cat::speak() const {
	return "meow";
}

string Dog::speak() const {
	return "bark";
}

template <class T>
class Stack {
public:
	Stack();
	~Stack();
	int size() const;
	bool empty() const;
	void push(T x);  
	void pop();     
	T & top();     

private:
	void ensureCapacity(int c);

	T * data;
	int capacity;  // capacity of data array
	int n;         // number of elements in stack
};

template <class T>
Stack<T>::Stack() : data(nullptr), capacity(0), n(0) {
}

template <class T>
Stack<T>::~Stack() {
	delete [] data;
}

template <class T>
void Stack<T>::ensureCapacity(int c) {
	if (capacity >= c) return;
	T * oldData = data;
	data = new T[c];
	for (int i = 0; i < n; ++i) {
		data[i] = oldData[i];
	}
	delete [] oldData;
	capacity = c;
}

template <class T>
bool Stack<T>::empty() const {
	return n == 0;
}

template <class T>
int Stack<T>::size() const {
	return n;
}

template <class T>
void Stack<T>::push(T k) {
	ensureCapacity(n + 1);
	data[n++] = k;
}

template <class T>
void Stack<T>::pop() {
	--n;
}

template <class T>
T & Stack<T>::top() {
	return data[n - 1];
}

int main(int argc, char * args[]) {
	Stack<Animal *> s;
	s.push(new Cat());
	cout << s.top()->speak() << endl;

	//cout << "All tests passed." << endl;
}

