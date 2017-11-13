#include <iostream>
#include <set>
#include <deque>
#include <list>
#include <algorithm>
#include <cstdlib>  // for abs()
#include "../../print.h"

using namespace std;

// 判断一个数 是否为质数
bool isPrime(int number)
{
    // ignore negative sign 忽略负号
    number = abs(number);

    // 0 and 1 are prime numbers
    if (number == 0 || number == 1)
        return true;

    // find divisor that divides without a reminder
    int divisor;
    for (divisor = number / 2; number % divisor != 0; --divisor)
        ;

    // if no divisor greater than 1 is found, it is a prime number
    return divisor == 1;
}

void print(int& elem)
{
    cout << elem << ' ';
}

int square(int value)
{
    return value * value;
}

int main(int argc, char *argv[])
{
#if 0
    vector<int> coll;

    // insert elements from 1 to 9 into container
    for(int i = 1; i != 10; ++i)
        coll.push_back(i);

    // print all elements
    for_each(coll.begin(), coll.end(), print);
#endif

#if 0
    std::set<int> coll1;
    std::vector<int> coll2;

    // insert elements from 1 to 9 into coll1
    for (int i = 1; i != 10; ++i)
        coll1.insert(i);

    PRINT_ELEMENT(coll1, "initialized: ");

    // transform each element from coll1 to coll2
    // - square transformed values
    coll2.resize(coll1.size());
    std::transform(coll1.begin(), coll1.end(),  // source
                   std::back_inserter(coll2),   // destination
                   square); // operation

    PRINT_ELEMENT(coll2, "squared: ");
    PRINT_ELEMENT(coll1, "coll1: ");
#endif

#if 0
    list<int> coll;
    // insert elements from 24 to 30
    for (int i = 20; i != 31; ++i)
        coll.push_back(i);

    // search for prime number
    list<int>::iterator pos;
    pos = find_if(coll.begin(), coll.end(), // range
                  isPrime); // predicate

    if (pos != coll.end())
        cout << *pos << " is the first prime number found" << endl;
    else
        // no found
        cout << "no prime number found.\n";

#endif

    vector<int> coll;
    vector<int> coll2;
    for (int i = 1; i != 10; ++i)
        coll.push_back(i);
    for (int i = 11; i != 20; ++i)
        coll2.push_back(i);
    PRINT_ELEMENT(coll, "coll before transforming: ");
    PRINT_ELEMENT(coll2, "coll2 before transforming: ");
    transform(coll.begin(), coll.end(), // first source
              coll2.begin(), // second source
              coll.begin(), // destination
              multiplies<int>());   // operation
    PRINT_ELEMENT(coll, "coll after transforming: ");
    PRINT_ELEMENT(coll2, "coll2 after transforming: ");

    return 0;
}
