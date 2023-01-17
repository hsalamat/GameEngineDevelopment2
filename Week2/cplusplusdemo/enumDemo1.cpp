/** @file enumDemo1.cpp
 *  @brief Two enumerations cannot share the same names
 *
 *  1.Enum is a collection of named integer constant means it’s each element is assigned by integer value. 
 *  2.It is declared with enum keyword.
 * 
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */




#include <iostream>
using namespace std;

using namespace std;
enum textures {
    airplane = 70,
    background = 73,
    player = 31,
    enemy = 05,
};
int main()
{
    enum textures obj;
    obj = player;
    cout << "The exture id  of player =" << obj;
}