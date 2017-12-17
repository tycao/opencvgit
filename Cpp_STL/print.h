#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>

/*
 * PRINT_ELEMENT()
 * - prints opetional C-string optstr followed by
 * - all elements of the collection coll
 * - seperated by spaces
*/
template<typename T>
inline void PRINT_ELEMENT(const T& coll, const char* optstr = "")
{
    typename T::const_iterator pos;

    std::cout << optstr;
    for (pos = coll.begin(); pos != coll.end(); ++pos)
        std::cout << *pos << ' ';
    std::cout << std::endl;
}

// INSERT_ELEMENT (collection, first, last)
/*
 * fill values from first to last into the collection
 * NOTE: No half-range open
*/
template<typename T>
inline void INSERT_ELEMENT(T& coll, int first, int last)
{
    for (int i = first; i <= last; ++i)
        coll.insert(coll.end(), i);
}
