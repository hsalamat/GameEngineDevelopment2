//The normal cast like (int)x is C style typecasting where static_cast<int>(x) is used in C++. 
//This static_cast<>() gives compile time checking facility, but the C style casting does not support that. 
#include <iostream>
using namespace std;

int main()
{
	//Since in a 4-byte pointer, it is pointing to 1-byte of allocated memory, 
	//it may generate runtime error or will overwrite some adjacent memory.
	char c = 65; //1-byte data. ASCII of ‘A’
	int* ptr = (int*)&c; //4-byte
	cout << *ptr;

	//In C++ the static_cast<>() will allow the compiler to check whether the pointer and the data are of same type or not. 
	//If not it will raise incorrect pointer assignment exception during compilation.

	int* ptr = static_cast<int>(&c);
}