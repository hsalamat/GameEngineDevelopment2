/** @file mapvsunorderedmapDemo.cpp
 *  @brief ordered vs. unordered map
 *
 *                   | map             | unordered_map
 *   ---------------------------------------------------------
 *   Ordering        | increasing  order   | no ordering
 *                   | (by default)        |
 *   
 *   Implementation  | Self balancing BST  | Hash Table
 *                   | like Red-Black Tree |  
 *   
 *   search time     | log(n)              | O(1) -> Average 
 *                   |                     | O(n) -> Worst Case
 *   
 *   Insertion time  | log(n) + Rebalance  | Same as search
 *                         
 *   Deletion time   | log(n) + Rebalance  | Same as search
 *   
 *   https://www.geeksforgeeks.org/advantages-of-bst-over-hash-table/
 *   
 *   Use std::map when
 *   
 *   You need ordered data.
 *   You would have to print/access the data (in sorted order).
 *   You need predecessor/successor of elements.
 *   
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include <map>
#include <unordered_map>
#include <iostream>

int main()
{

    // Ordered map
    std::map<int, int> order;

    // Mapping values to keys
    order[5] = 10;
    order[3] = 5;
    order[20] = 100;
    order[1] = 1;

    // Iterating the map and 
    // printing ordered values
    for (auto i = order.begin(); i
        != order.end(); i++) {
        std::cout << i->first
            << " : "
            << i->second << '\n';
    }

    // Unordered map
    std::unordered_map<int, int> order2;

    // Mapping values to keys
    order2[5] = 10;
    order2[3] = 5;
    order2[20] = 100;
    order2[1] = 1;

    // Iterating the map and 
    // printing unordered values
    for (auto i = order2.begin();
        i != order2.end(); i++)
    {
        std::cout << i->first
            << " : "
            << i->second << '\n';
    }

    return 0;
}