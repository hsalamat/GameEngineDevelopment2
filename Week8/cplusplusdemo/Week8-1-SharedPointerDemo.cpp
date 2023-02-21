// Week8-1-SharepointerDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
// std::weak_ptr is a very good way to solve the dangling pointer problem. 
// By just using raw pointers it is impossible to know 
// if the referenced data has been deallocated or not. Instead, by letting a std::shared_ptr manage the data, 
// and supplying std::weak_ptr to users of the data, 
// the users can check validity of the data by calling expired() or lock().
//You could not do this with std::shared_ptr alone, 
//because all std::shared_ptr instances share the ownership of the data 
//which is not removed before all instances of std::shared_ptr are removed.
//Here is an example of how to check for dangling pointer using lock() :

#include <iostream>
#include <memory>

class Parent {

};

class Child {

};

class MyClass {

};


int main()
{

    MyClass* myClass = new MyClass();
    MyClass* myClass2 = myClass;
    //MyClass* hClass = myClass;

    delete myClass;

    std::shared_ptr<MyClass> mClass;
    mClass.reset(new MyClass);
    std::shared_ptr<MyClass> mClass2 = mClass;
    std::shared_ptr<MyClass> hClass = mClass;

    std::weak_ptr<MyClass> wClass = mClass;

    if (auto temp = wClass.lock())
        std::cout << "wClass still has the right value" << std::endl;
    else
        std::cout << "wClass is nullptr" << std::endl;

     
    // problem with dangling pointer
    // PROBLEM: ref will point to undefined data!

    int* ptr = new int(10);
    int* ref = ptr;
    delete ptr;

    // SOLUTION: check expired() or lock() to determine if pointer is valid

    // empty definition
    std::shared_ptr<int> sptr;

    // takes ownership of pointer
    sptr.reset(new int);
    *sptr = 10;

    // get pointer to data without taking ownership
    std::weak_ptr<int> weak1 = sptr;

    // deletes managed object, acquires new pointer
    sptr.reset(new int);
    *sptr = 5;

    // get pointer to new data without taking ownership
    std::weak_ptr<int> weak2 = sptr;

    // weak1 is expired!  weak_ptr uses lock to connect to the real owner or returns a NULL shared_ptr otherwise
    if (auto tmp = weak1.lock())
        std::cout << *tmp << '\n';
    else
        std::cout << "weak1 is expired\n";

    // weak2 points to new data (5)
    if (auto tmp = weak2.lock())
        std::cout << *tmp << '\n';
    else
        std::cout << "weak2 is expired\n";


    //another example
    std::shared_ptr<Parent> parentSharedPtr;
    std::weak_ptr<Parent> parentWeakPtr = parentSharedPtr; // automatic conversion to weak from shared

    std::shared_ptr<Parent> tempParentSharedPtr = parentWeakPtr.lock(); // on the stack, from the weak ptr
    if (!tempParentSharedPtr) {
        // yes, it may fail if the parent was freed since we stored weak_ptr
    }
    else {
        // do stuff
    }
    // tempParentSharedPtr is released when it goes out of scope

    

   
    {
        std::shared_ptr<Parent> parentSharedPtr1;

        std::shared_ptr<Parent> parentSharedPtr2 = parentSharedPtr1;
        parentSharedPtr1.reset();
        std::shared_ptr<Parent> parentSharedPtr3 = parentSharedPtr1;
        std::shared_ptr<Parent> parentSharedPtr4 = parentSharedPtr1;
        std::shared_ptr<Parent> parentSharedPtr5 = parentSharedPtr1;
        parentSharedPtr1.reset();
        std::weak_ptr<Parent> parentWeakPtr = parentSharedPtr1;
    }
   

}