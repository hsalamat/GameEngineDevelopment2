
/** @file enumDemo4.cpp
 *  @brief Enums are not type - safe:
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

    // Defining enum2 Color
    enum Color {
        Red,
        Green
    };

    // Creating Gender type variable
    Gender gender = Male;
    Color color = Red;

    // Upon comparing gender and color
    // it will return true as both have value 0
    // which should not be the case actually
    if (gender == color)
        cout << "Equal";

    return 0;
}