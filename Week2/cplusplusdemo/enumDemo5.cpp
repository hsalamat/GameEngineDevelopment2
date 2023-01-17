
/** @file enumDemo5.cpp
 *  @brief Enum Class
 *
 *  C++11 has introduced enum classes (also called scoped enumerations), that makes enumerations both strongly typed and strongly scoped. Class enum doesn’t allow implicit conversion to int, and also doesn’t compare enumerators from different enumerations.
 *  To define enum class we use class keyword after enum keyword. 
 *  Syntax: 
 *   
 *  
 *  // Declaration
 *  enum class EnumName{ Value1, Value2, ... ValueN};
 *  
 *  // Initialisation
 *  EnumName ObjectName = EnumName::Value;
 *
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

 // C++ program to demonstrate working
 // of Enum Classes
#include <iostream>
using namespace std;

int main()
{

    enum class Color {
        Red,
        Green,
        Blue
    };
    enum class Color2 {
        Red,
        Black,
        White
    };
    enum class Textures {
        Airplane,
        Background
    };

    // An enum value can now be used
    // to create variables
    int Green = 10;

    // Instantiating the Enum Class
    Color x = Color::Green;

    // Comparison now is completely type-safe
    if (x == Color::Red)
        cout << "It's Red\n";
    else
        cout << "It's not Red\n";

    Textures p = Textures::Airplane;

    if (p == Textures::Background)
        cout << "Bad Texture\n";
    else
        cout << "Good Texture\n";

    // gives an error
    // if(x == p)
    // cout<<"red is equal to good";

    // won't work as there is no
    // implicit conversion to int
    // cout<< x;

    cout << int(x);

    return 0;
}