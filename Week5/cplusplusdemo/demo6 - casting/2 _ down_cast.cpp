//In C++, a derived class reference/pointer can be treated as a base class pointer. 
//This is called upcasting in C++. The opposite process, called downcasting, is not allowed in C++.
// You will get an error saying: a value of type cannot be assigned to an entity of type  


#include <iostream>
using namespace std;

class base
{
public:
    virtual void car()
    {
        cout << "base";
    }
};
class derived :public base
{
public:
    void electric()
    {
        cout << "derived";
    }
};
int main()
{
    base* b = new derived;
    derived* d;
    d = b;        //base class pointer assigned to the derived class pointer
    d->electric();
}