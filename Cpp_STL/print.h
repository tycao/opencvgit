#include <iostream>

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
