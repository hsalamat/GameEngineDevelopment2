/** @file enumDemo2.cpp
 *  @brief Two enumerations cannot share the same names
 *
 * 
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */




#include <iostream>
using namespace std;

int main()
{
    // Defining enum1 Gender
    enum Gender {
        Male,
        Female
    };

    // Defining enum2 Gender2 with same values
    // This will throw error
    enum Gender2 {
        Male,
        Female
    };

    // Creating Gender type variable
    Gender gender = Male;
    Gender2 gender2 = Female;

    cout << gender << endl
        << gender2;

    return 0;
}