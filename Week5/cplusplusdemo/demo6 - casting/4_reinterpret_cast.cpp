// reinterpret_cast
//It is used to convert a pointer of some data type into a pointer of another data type, 
//even if the data types before and after conversion are different.
//It does not check if the pointer type and data pointed by the pointer is same or not.
//data_type *var_name = reinterpret_cast <data_type*>(pointer_variable);
#include <iostream>
using namespace std;

int main()
{
    int* p = new int(65);
    char* ch = reinterpret_cast<char*>(p);
    cout << *p << endl;
    cout << *ch << endl;
    cout << p << endl;
    cout << ch << endl;
    return 0;
}