////Weak_ptr is much more similar to shared_ptr except it’ll not maintain a Reference Counter. 
//In this case, a pointer will not have a stronghold on the object. 
//The reason is if suppose pointers are holding the object and requesting for other objects then they may form a Deadlock. 
// In this example we use weak_ptr to avoid cyclically referenced classes. When the classes go out of scope they are  destroyed.


#include<iostream>
#include<memory>
using namespace std;

class B;

class A
{
public:
    weak_ptr<B>bptr;
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
    weak_ptr<A>aptr;
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
        shared_ptr<A> a = make_shared<A>();
        shared_ptr<B> b = make_shared<B>();
        a->bptr = b;
        b->aptr = a;
    }

    //it's going out of scope here, and hence destructed
}