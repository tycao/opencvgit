#include "addvalue.h"
#include "../../../print.h"

int main(int argc, char *argv[])
{
    std::vector<int> coll;

    INSERT_ELEMENT<std::vector<int>>(coll, 1, 9);
#if 0
    // add 10 to each element
    std::for_each(coll.begin(), coll.end(),
                  AddValue<int>(10));

    // print coll after adding operation
    PRINT_ELEMENT(coll, "coll : ");

    // addvalue of the first element to each element
    std::for_each(coll.begin(), coll.end(),
                  AddValue<int>(*coll.begin()));

    // print coll after adding operation
    PRINT_ELEMENT(coll, "coll : ");
#elif 1
    // add 10 to each element
    std::transform(coll.begin(), coll.end(),    // source range
                   coll.begin(),    // destination range
                   std::bind(std::plus<int>(), std::placeholders::_1, 10));

    // print all elements of coll after adding
    PRINT_ELEMENT(coll, "coll : ");

    // add value of the first element of coll to each element
    std::transform(coll.begin(), coll.end(),    // source range
                   coll.begin(),    // destination range
                   std::bind(std::plus<int>(), std::placeholders::_1, *coll.begin()));

    // print all elements of coll after adding the second time
    PRINT_ELEMENT(coll, "coll : ");

#endif


    return 0;
}
