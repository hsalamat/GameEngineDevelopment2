/** @file templateDemo1.cpp
 *  @brief Funcation Template Demo
 *
 *  A template is a simple yet very powerful tool in C++. 
 *  The simple idea is to pass data type as a parameter so that we don’t need to write the same code for different data types.
 *
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */


#include <iostream>
using namespace std;

// One function works for all data types.  This would work
// even for user defined types if operator '>' is overloaded
template <typename T> T myMax(T x, T y)
{
    return (x > y) ? x : y;
}

int main()
{
    cout << myMax<int>(3, 7) << endl; // Call myMax for int
    cout << myMax<double>(3.0, 7.0)
        << endl; // call myMax for double
    cout << myMax<char>('g', 'e')
        << endl; // call myMax for char

    return 0;
}