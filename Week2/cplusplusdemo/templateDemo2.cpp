/** @file templateDemo2.cpp
 *  @brief Class Template Demo
 *
 *  Class Templates like function templates, class templates are useful when a class defines something that is independent of the data type. Can be useful for classes like LinkedList, BinaryTree, Stack, Queue, Array, etc. 
 * 
 *  template < typename T >
 *  template < class T >
 *
 *  are equivalent.
 *  Having said that, there are specific cases where there is a difference between typename and class.
 *  The first one is in the case of dependent types. typename is used to declare when you are referencing a nested type that depends on another template parameter, such as the typedef in this example:

 * template<typename param_t>
 * class Foo
 * {
 *   typedef typename param_t::baz sub_t;
 * }; 
 * 
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */


#include <iostream>
using namespace std;

template <typename T> class Array {
private:
    T* ptr;
    int size;

public:
    Array(T arr[], int s);
    void print();
};

template <typename T> Array<T>::Array(T arr[], int s)
{
    ptr = new T[s];
    size = s;
    for (int i = 0; i < size; i++)
        ptr[i] = arr[i];
}

template <typename T> void Array<T>::print()
{
    for (int i = 0; i < size; i++)
        cout << " " << *(ptr + i);
    cout << endl;
}

template <class T, class U> class A {
    T x;
    U y;

public:
    A() { cout << "Constructor Called" << endl; }
};

//Yes, like normal parameters, we can specify default arguments to templates. 
template <class T, class U = char> class B {
public:
    T x;
    U y;
    B() { cout << "Constructor Called" << endl; }
};

int main()
{
    int arr[5] = { 1, 2, 3, 4, 5 };
    Array<int> a(arr, 5);
    a.print();

    A<char, char> a2;
    A<int, double> b2;

    B<char> a3; // This will call B<char, char>

    return 0;
}