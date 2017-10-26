#include <iostream>
#include <cassert>

using namespace std;

int main() {
	int k = 3;
	cout << k << endl;

	int * kptr = &k;
	cout << *kptr << endl;

	int & kref = k;
	cout << kref << endl;

	kref += 1;
	cout << k << endl;

	*kptr += 1;
	cout << k << endl;

	double x = 2.5;
	kref = x;
	cout << kref << endl;
}

