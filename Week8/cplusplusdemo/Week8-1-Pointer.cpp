//Problems with Normal Pointers
//Pointers are used for accessing the resources which are external to the program – like heap memory. 
//So, for accessing the heap memory (if anything is created inside heap memory), pointers are used. 
//When accessing any external resource we just use a copy of the resource. 
//If we make any change to it, we just change it in the copied version. 
//But, if we use a pointer to the resource, we’ll be able to change the original resource.
//
//When the function fun ends, p will be destroyed as it is a local variable. 
//But, the memory it consumed won’t be deallocated because we forgot to use delete p; at the end of the function. 
//That means the memory won’t be free to be used by other resources. 
//But, we don’t need the variable anymore, but we need the memory.

#include <iostream>
using namespace std;

class Rectangle {
private:
	int length;
	int breadth;
};

void fun()
{
	// By taking a pointer p and
	// dynamically creating object
	// of class rectangle
	Rectangle* p = new Rectangle();
}

int main()
{
	// Infinite Loop
	while (1) {
		fun();
	}
}
