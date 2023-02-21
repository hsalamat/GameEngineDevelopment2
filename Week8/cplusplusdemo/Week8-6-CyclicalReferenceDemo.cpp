// In this example we use shared_ptr in cyclically referenced classes. When the classes go out of scope they are NOT destroyed.
//Memory Leak Demo

#include<iostream>
#include<memory>
using namespace std;

class B;

class A
{
public:
    shared_ptr<B> bptr;
    A() {
        cout << "A created" << endl;
    }
    ~A() {
        cout << "A destroyed" << endl;
    }
};

class B
{
public:
    shared_ptr<A> aptr;
    B() {
        cout << "B created" << endl;
    }
    ~B() {
        cout << "B destroyed" << endl;
    }
};

int main()
{
    {
        //unique_ptr<A> uniqueA = make_unique<A>();
        unique_ptr<A> aPtr (new A());
        aPtr.reset(); //// deletes managed object
        aPtr.reset(new A());
        // std::shared_ptr<A> a;
        // a.reset(new A);
        shared_ptr<A> a = make_shared<A>();
        shared_ptr<B> b = make_shared<B>();
        a->bptr = b;
        b->aptr = a;
    }
}