//We know that, in C++, we can assign one variable to another of the same type. 
//But what happens if the data type of both the variables is different. 
//In such a case, implicit type conversion would take place. 
//It means the conversion of one data type to another. 
//This typecasting may or may not be implicitly supported in C++. 
//If it is not supported, then we need to make use of casting methods available in C++. 
//So, there are four explicit type casting methods available in C++. 
//They are – static_cast, const_cast, reinterpret_cast and dynamic_cast.

//static_cast is the simplest one of all the cast. 
//static_cast simply performs implicit conversions between types.
//static_cast happens at compile time. 
//In the program, it checks whether we can typecast ‘ f ‘, which is of float type into ‘a’, which is of integer type.

#include<iostream>
using namespace std;
int main()
{
	float f = 6.4;
	int i, j;
	i = f;      //implicit type conversion from float to int 
	j = static_cast<int>(f);
	cout << i << "\n" << j;
}