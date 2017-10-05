#include <iostream>
#include <cassert>

using namespace std;

// Sort values in range [s, e].
void quicksort(int a[], int s, int e) {
	// If there are less than 2 values to sort,
	// then there is nothing to do.
	if (e - s < 1) return;

	// Use last value in range [s, e] as pivot.

	// Re-organize range so that values less than pivot
	// are located before pivot and values greater than
	// pivot are after pivot.

	// Scan range [a, e] from left to right; 
	// move elements less than pivot to front of range.

	int i = s - 1; 
	for (int j = s; j < e; ++j) {
		if (a[j] < a[e]) swap(a[++i], a[j]);
	}
	swap(a[++i], a[e]);

	// Sort values before pivot.
	quicksort(a, s, i - 1);

	// Sort values after pivot.
	quicksort(a, i + 1, e);
}

bool sorted(int a[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] > a[i + 1]) return false;
	}
	return true;
}

int main(int argc, char * args[]) {
	int a[] = { 2, -9, 122, 45, -7, 33, -7, 16, 99, 21 };
	quicksort(a, 0, 9);
	assert(a[0] == -9);
	assert(a[1] == -7);
	assert(a[2] == -7);
	assert(a[3] == 2);
	assert(a[4] == 16);
	assert(a[5] == 21);
	assert(a[6] == 33);
	assert(a[7] == 45);
	assert(a[8] == 99);
	assert(a[9] == 122);

	int b[] = { 2 };
	quicksort(b, 0, 0);
	assert(b[0] == 2);

	int c[] = { 2, 2 };
	quicksort(c, 0, 1);
	assert(c[0] == 2);
	assert(c[1] == 2);

	int d[] = { 2, -2 };
	quicksort(d, 0, 1);
	assert(d[0] == -2);
	assert(d[1] == 2);

	srand(time(0));
	int e[1000];
	for (int i = 0; i < 1000; ++i) e[i] = rand() % 100;
	quicksort(e, 0, 999);
	assert(sorted(e, 1000));

	cout << "All tests passed." << endl;	
}

