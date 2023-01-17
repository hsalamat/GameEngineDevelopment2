
/** @file enumDemo6.cpp
 *  @brief Enum Class
 *
 *  Enumerated types declared the enum class also have more control over their underlying type; it may be any integral data type, such as char, short or unsigned int, which essentially serves to determines the size of the type.

 *  This is specified by a colon and underlying type following the enumerated type:
 *
 *  eg: enum class eyecolor : char {char,green,blue};
 *  Here eyecolor is a distinct type with the same size as a char (1 byte).
 *
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include <iostream>
using namespace std;
enum rainbow {
	violet,
	indigo,
	blue,
	green, yellow, orange, red
}colors;
enum class eyecolor :char {
	blue, green, brown
}eye;
int main() {

	cout << "size of enum rainbow variable: " << sizeof(colors) << endl;
	cout << "size of enum class eyecolor variable:" << sizeof(eye) << endl;
	return 0;
}