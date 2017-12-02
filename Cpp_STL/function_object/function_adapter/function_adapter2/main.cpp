#include <iostream>     // for std::cout
#include <algorithm>    // for std::remove_if
#include <functional>   // for std::bind
#include <iterator>     // for ostream_iterator<>
#include <vector>       // for std::vector

#include "../../../print.h"
#include "adapter.h"

int main(int argc, char *argv[])
{
    std::vector<int> coll;

    // insert elements from 1 to 9
    for (int i = 1; i != 10; ++i)
        coll.push_back(i);

    // print vector container
    PRINT_ELEMENT(coll, "coll : ");

    // remove all elements that are greater than 4 and less than 7
    // - retain new end
    std::vector<int>::iterator pos;
    pos = std::remove_if(coll.begin(), coll.end(),
                    compose_f_gx_hx(
                                std::logical_and<bool>(),
                                std::bind(std::greater<int>(), std::placeholders::_1, 4),
                                std::bind(std::less<int>(), std::placeholders::_1, 7)
                             )
                         );
    // remove "removed" elements in coll
    if (pos != coll.end())
        coll.erase(pos, coll.end());
    else
        std::cout << "no element greater than 4 and less than 7 found!\n";

    // print all elements in coll
    PRINT_ELEMENT(coll, "coll after calling compose_f_gx_hx : ");

    return 0;
}
