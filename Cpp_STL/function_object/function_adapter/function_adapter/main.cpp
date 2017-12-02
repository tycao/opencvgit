#include <iostream>
#include <vector>
#include <algorithm>    // for transform
#include <functional>   // for bind
#include <iterator>     // for ostream_iterator<int>(cout, "")

#include "../../../print.h"
#include "adapter.h"

int main(int argc, char *argv[])
{
    // create an empty vector container
    std::vector<int> coll;

    // insert into element from 1 to 9
    for (int i = 1; i != 10; ++i)
        coll.push_back(i);

    // print vector container
    PRINT_ELEMENT(coll);

    // for each element add 10 then multiply by 5
    std::transform(coll.begin(), coll.end(),    // source
                   std::ostream_iterator<int>(std::cout, " "),  // destination
                   compose_f_gx(std::bind(std::multiplies<int>(), std::placeholders::_1, 5),   // operation
                                std::bind(std::plus<int>(), std::placeholders::_1, 10))
                   );
    std::cout << "\n";
    return 0;
}
