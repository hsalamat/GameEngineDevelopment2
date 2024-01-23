// You can think of an r-value as an expression, essentially, whereas an l-value is an actual object. 
// Expressions don't have addresses, and even if they did, it's hard to imagine what good the address would be. 
// 
// The & operator must be applied to an lvalue. 
// When the call  aClass.get_number() is not assigned to a variable, its return value is only put on the stack, 
// so it would be erroneous to get the address of a stack item.
// Stack memory is a sort of memory allocation that the OS continuously manages and uses to store local variables in a LIFO order. 
// On the other hand, heap memory is a type of dynamic memory allocation used for storing objects and data structures that require a longer lifespan than stack memory.

class a {
private:
	int* number;
public:
	int* get_number() const {
		return number;
	}
};


class b {
private:
	int dummy;
public:
	int get_dummy() const {
		return dummy;
	}
	int& get_dummy() {
		return dummy;
	}
};

int main()
{
	a aClass;

	// error C2102: '&' requires l-value
	// Because a::get_number() returns a unnamed temporary object (int pointer).
	//Object returned by function sit ontop of the stack frame and it is meaningless to get its address since it might be invalid after expression ends.
	//int** me = &(aClass.get_number());

	// OK!
	int* tmp = aClass.get_number();
	int** me = &(tmp);

	b bClass;

	int* me = &(bClass.get_dummy());
}