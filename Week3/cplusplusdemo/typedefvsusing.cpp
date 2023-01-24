/** @file typedefvsusingDemo.cpp
 *  @brief typedef vs. using
 *
 *  typedef keyword in C++ is used for aliasing existing data types, user-defined data types, 
 *  and pointers to a more meaningful name. Typedefs allow you to give descriptive names to 
 *  standard data types, which can also help you self-document your code. 
 *  Mostly typedefs are used for aliasing, only if the predefined name is too long or complex 
 *  to write again and again.  The unnecessary use of typedef is generally not a good practice.
 *
 *  Syntax:
 *
 *  typedef <current_name> <new_name>
 *  Example:
 *  typedef std::vector<int> vInt;
 * 
 *  Using in C++ STL
 *  The using keyword in C++ is used to bring a specific member or all members into 
 *  the current scope and bring base class variables/methods into the derived class’s scope.
 * 
 *  Syntax:
 *
 * using <member_name> 
 * Example:
 * 
 *  using std::cout;
 * 
 *  Typedef in C++ STL	Using in C++ STL
 *  Typedef cannot be used with a template.	Using can be used with a template.
 *  It requires the type name.	It does not require the type name.
 *  It is difficult to modify. 	It is comparatively easy to modify. 
 *  It is not much readable.	It is comparatively readable.
 *  Typedef is an init-statement.	Using is not an init-statement
 *  The Pointer declaration is not much clean.	The Pointer declaration is comparatively clean.
 *  Syntax:
 *  typedef struct struct_type short_type_t;
 *
 *  Syntax:
 *  template<[template-parameters (T1, …)]> using [alias] = [original-type];
 *
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include<iostream>
#include <vector>

using namespace std;

int main()
{
    // Now we can make more vectors by using vInt
    typedef std::vector<int> vInt;

    // vec1 is a vector of type int
    vInt v;

    v.push_back(190);
    v.push_back(180);
    v.push_back(10);
    v.push_back(10);
    v.push_back(27);

    for (auto X : v) {
        cout << X << " ";
    }


    // Now we can make more vectors by using vInt
    using vInt2 = std::vector<int>;

    // vec2 is a vector of type int
    vInt2 v2;

    v2.push_back(190);
    v2.push_back(180);
    v2.push_back(10);
    v2.push_back(10);
    v2.push_back(27);

    for (auto X : v2) {
        cout << X << " ";
    }

    return 0;
}