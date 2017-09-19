#include <iostream>
#include <cassert>

using namespace std;

/*
When studying the following code, keep in mind that main
memory (RAM) is comprised of a sequence of bytes that are
sequentially numbered starting from 0. Byte 0 is followed
by byte 1, which is followed by byte 2 and so on.  These 
numbers are called adresses. Programs access bytes in memory
by using addresses. These addresses are either managed directly
by code using pointers or indirectly by using variables that
are converted to addresses when the code is compiled.

The other thing to keep in mind is that when programs 
execute, the operating system allocates two types of memory
blocks to store data: stacks and heaps.  Each thread is given
a stack to store data that needed for the execution of a
function and released when the function returns.  When the
program starts, it is given a single heap to store data created
in functions and persists after the function returns.
See the following stackoverflow discussion:
https://stackoverflow.com/questions/79923/what-and-where-are-the-stack-and-heap
*/

int main(int argc, char * argv[]) {
	// The following definition of x allocates memory
	// on the program stack to store an integer value.
	int x;

	// On every computer I have worked on, 4 bytes of
	// memory is used to store an int, although this is
	// not required by any version of C++.  See the 
	// following stackoverflow post for additional details:
	// https://stackoverflow.com/questions/589575/what-does-the-c-standard-state-the-size-of-int-long-type-to-be
	assert(sizeof(x) == 4);

	// The following statement allocates memory on the program stack 
	// to store the memory address of an int. The datatype of ptr
	// is called a "pointer" or an "int pointer" to be more precise.
	int * ptr;

	// On 32-bit computers, 4 bytes are allocated to store pointers.
	// On 64-bit computers, 8 bytes are allocated to store pointers.
	assert(sizeof(ptr) == 4 or sizeof(ptr) == 8);

	// The following statement assigns the address of x
	// to ptr.  The ampersand in this statement is called 
	// the "address of operator." (Note: When used with function 
	// parameters, an ampersand indicates a "reference," which
	// is essentially a pointer.)
	ptr = &x;

	// The following statement assigns the value 3 to x by
	// using the "deference operator."
	*ptr = 3;

	// Think about this way: 
	// "ptr" represents the memory used to reference x and
	// "*ptr" represents the memory used to store x,
	// whence the term "dereference."

	// The following assertion proves that x has been set
	// to 3 through the pointer.
	assert(x == 3);

	// When we created ptr, we did not initialize it. so the
	// resulting address assigned to ptr is essentially random.
	// This makes debugging more difficult because the program
	// is non-deterministic.  To eliminate this problem, it is
	// a good idea to initialize pointers to a specific value.
	// If you have nothing to assign the pointer to, then assign
	// it the value zero, which is the address of the first byte
	// in memory.  It is illegal to read from or write to
	// the zero address.  The following code will crash the program.
	// Uncomment and run the following to see the result.
	//ptr = 0;
	//*ptr = 1;

	// It's better to consistenly crash with each run than to 
	// crash only sometimes, so initialize pointers to zero when
	// you have nothing else to assign to them.

	//  For increased redability, use nullptr rather than 0.
	ptr = nullptr;
	assert(nullptr == (void *) 0);

	// Most computers these days store multi-byte numbers
	// so that the least significant byte comes first.
	// This is also called "little endian" byte order.
	// "Big endian" means the opposite: most significant
	// byte first. The following code runs without fail
	// on little endian machines.
	x = 0x11223344;
	ptr = &x;
	unsigned char * a = (unsigned char *) ptr;
	assert(a[0] == 0x44);
	assert(a[1] == 0x33);
	assert(a[2] == 0x22);
	assert(a[3] == 0x11);

	// The following code does the same as above but uses
	// pointer arithmetic syntax rather than array syntax.
	assert(*a == 0x44);
	assert(*(a + 1) == 0x33);
	assert(*(a + 2) == 0x22);
	assert(*(a + 3) == 0x11);

	// The following code allocates memory in the heap to
	// store an int using the "new" operator.
	ptr = new int(5);
	assert(*ptr == 5);

	// Memory allocated on the heap is not reclaimed when 
	// execution returns from the function in which it is
	// allocated.  Reclamation of heap memory is done explicitly
	// using the "delete" operator.
	delete ptr;
	
	// After deleting memory, it's a good idea to set the pointer
	// to an address that corresponds to allocated memory.
	ptr = &x;
	// ... or set it to nullptr (memory address zero).
	ptr = nullptr;

	// The following code shows how to allocate an array of 3 
	// contiguous ints on the heap.
	ptr = new int[3];

	// Note that the 3 ints have an indetermined state.
	// It's usually a good idea to set this memory to zeros
	// if you are not ready to set to other values needed by
	// the program.  You can use memset for this purpose.
	memset(ptr, 0, 3 * sizeof(int));
	assert(ptr[0] == 0);
	assert(ptr[1] == 0);
	assert(ptr[2] == 0);

	// The following code shows the required syntax to reclaim
	// the array of ints with the delete operator.
	delete [] ptr;

	// At this point, the following code might not trigger a
	// memory fault but its effects are indeterminate.
	//memset(ptr, 0, 3 * sizeof(int));
	
	cout << "All tests passed." << endl;
}

