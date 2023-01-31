
//std::function template type represents a “thing you can invoke”.It can hold any callable, such as

//1. Function pointer.
//2. Lambda.
//3. Other object with operator().

#include <functional>
#include <string>
#include <iostream>
using namespace std;

void goodbye(const std::string& s)
{
	std::cout << "Goodbye " << s << '\n';
}

class Object {
public:
	void hello(const std::string& s)
	{
		std::cout << "Hello " << s << '\n';
	}
};

int fn(int a, int b)
{
	cout << "call fn function using bind function template: bound_fn(5) = " << a - b << endl;
	return a - b;
}

int main()
{
	//Using the standard function template std::bind(), the function arguments can be bound to the given values.
	//The std::bind() function returns a new function object that can be stored inside std::function.
	using namespace std::placeholders;
	auto bound_fn = std::bind(fn, 100, _1);
	bound_fn(5);  // calls fn(100,5), i.e.: replacing _1 by the first argument: 100

	//_1: Replaced by the first argument in the function call.
	//_2: Replaced by the second argument in the function call.
	//_N: Replaced by the Nth argument in the function call(where N is a natural number)

	typedef std::function<void(const std::string&)> ExampleFunction;
	Object instance;
	std::string str("World");

	ExampleFunction f = std::bind(&Object::hello, &instance, std::placeholders::_1);
	f(str); // equivalent to instance.hello(str)

	f = std::bind(&goodbye, std::placeholders::_1);
	f(str); 	// equivalent to goodbye(str)

	string bye = "bye";
	getline(cin, bye);

	return 0;
}