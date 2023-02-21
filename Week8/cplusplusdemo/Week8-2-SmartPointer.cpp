//Languages Java, C# has Garbage Collection Mechanisms to smartly deallocate unused memory to be used again. 
//The programmer doesn’t have to worry about any memory leak. C++11 comes up with its own mechanism that’s Smart Pointer. 
//When the object is destroyed it frees the memory as well.
//A Smart Pointer is a wrapper class over a pointer with an operator like * and -> overloaded. 
//The objects of the smart pointer class look like normal pointers. 
//But, unlike Normal Pointers it can deallocate and free destroyed object memory.

#include <iostream>
using namespace std;

class SmartPtr {
	int* ptr; // Actual pointer
public:
	// Constructor: 
	// for use of explicit keyword
	explicit SmartPtr(int* p = NULL) { ptr = p; }

	// Destructor
	~SmartPtr() { delete (ptr); }

	// Overloading dereferencing operator
	int& operator*() { return *ptr; }
};

int main()
{
	SmartPtr ptr(new int());
	*ptr = 20;
	cout << *ptr;

	// We don't need to call delete ptr: when the object
	// ptr goes out of scope, the destructor for it is automatically
	// called and destructor does delete ptr.

	return 0;
}
