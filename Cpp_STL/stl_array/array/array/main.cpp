#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator> // for ostream_iterator

using namespace std;

int main(int argc, char *argv[])
{
    int coll[] = {5, 6, 2, 4, 1, 3};

    // square all elements
    std::transform(coll, coll + 6,  // first source
                   coll,    // second source
                   coll,    // destination
                   multiplies<int>()    // operation
                   );

    // sort beginning with the second element
    sort(coll + 1, coll + 6);

    // print all elements
    std::copy(coll, coll + 6,
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << endl;
    return 0;
}
