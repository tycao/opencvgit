#include <iostream>
#include <set>
#include "../../print.h"

#include "runtimecmp.h"

using namespace std;

// type of a set that uses this sorting criterion
typedef set<int, RuntimeCmp<int>> IntSet;

// forward declaration
void fill(IntSet& set);

int main(int argc, char *argv[])
{
    // create, fill, and print set with normal element order
    // - uses default sorting criterion
    IntSet coll;
    fill(coll);
    PRINT_ELEMENT(coll, "coll : ");

    // create sorting criterion with reverse element order
    RuntimeCmp<int> reverse_order(RuntimeCmp<int>::reverse);

    // create, fill, and print set with reverse element order
    IntSet coll2(reverse_order);
    fill(coll2);
    PRINT_ELEMENT(coll2, "coll2 : ");

    // assign elements AND sorting criterion
    coll = coll2;
    coll.insert(3);
    PRINT_ELEMENT(coll, "coll : ");

    // just to make sure... that coll and coll2 have "the same sorting criterion"
    if (coll.value_comp() == coll2.value_comp())
        cout << "coll and coll2 have same sorting criterion" << endl;
    else
        cout << "coll and coll2 have different sorting criterion" << endl;

    return 0;
}


void fill(IntSet& set)
{
    // fill insert elements in random order
    set.insert(4);
    set.insert(7);
    set.insert(5);
    set.insert(1);
    set.insert(6);
    set.insert(2);
    set.insert(5);
}
