////So, dynamic_cast is used to promote safe downcasting in C++. 
//It is always performed with polymorphic classes having at least one virtual function inside the class.

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
    d = dynamic_cast<derived*>(b);      //to promote downcasting
    cout << d << "\n";
    d->electric();
}