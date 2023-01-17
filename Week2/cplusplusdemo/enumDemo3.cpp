/** @file enumDemo3.cpp
 *  @brief No variable can have a name which is already in some enumeration:
 *
 *  1.Enum is a collection of named integer constant means it’s each element is assigned by integer value.
 *  2.It is declared with enum keyword.
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

    // Creating Gender type variable
    Gender gender = Male;

    // creating a variable Male
    // this will throw error
    int Male = 10;

    cout << gender << endl;

    return 0;
}