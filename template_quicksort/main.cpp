#include <iostream>
#include <cassert>

using namespace std;

// Sort values in range [s, e].
template <class T>
void quicksort(T a[], int s, int e) {
	// If there are zero or one values to sort,
	// then there is nothing to do.
	if (e - s < 1) return;

	// Use last value in range [s, e] as pivot.

	// Re-organize range so that values less than pivot
	// are located before pivot and values greater than
	// pivot are after pivot.

	// Scan range [s, e] from left to right; 
	// move elements less than pivot to front of range.

	int i = s - 1; 
	for (int j = s; j < e; ++j) {
		if (a[j] < a[e]) swap(a[++i], a[j]);
	}
	swap(a[++i], a[e]);

	// Sort values before pivot.
	quicksort<T>(a, s, i - 1);

	// Sort values after pivot.
	quicksort<T>(a, i + 1, e);
}

template <class T>
bool sorted(T a[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] > a[i + 1]) return false;
	}
	return true;
}

int main(int argc, char * args[]) {
	double a[] = { 2.2, -9.4, 122.11, 45, -7, 33, -7, 16, 99, 21 };
	quicksort<double>(a, 0, 9);
	assert(sorted<double>(a, 9));

	cout << "All tests passed." << endl;	
}

