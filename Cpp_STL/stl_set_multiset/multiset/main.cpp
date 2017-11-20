#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
    /*
     * type of the collection : multiset
     * - duplicates allowed
     * - elements are integral values
     * - descending order
    */
    typedef multiset<int, greater<int>> IntSet;

    IntSet coll;    // initialized an empty multiset with default constructor of multiset

    // insert elements in random order
    coll.insert(5);
    coll.insert(3);
    coll.insert(1);
    coll.insert(4);
    coll.insert(6);
    coll.insert(2);
    coll.insert(5);

    // iterate over all elements and print them
    IntSet::const_iterator iter;
    for (iter = coll.cbegin(); iter != coll.cend(); ++iter)
        cout << *iter << " ";
    cout << endl;

    // insert 4 again and process the return value
    iter = coll.insert(4);
    cout << "4 inserted as element "
         << distance(coll.cbegin(), iter) + 1
         << endl;

    // assign elements to another multisets with ascending order
    std::multiset<int, less<int>> coll2(coll.cbegin(), coll.cend());

    // print all elements of the copy
    std::copy(coll2.cbegin(), coll2.cend(),
              ostream_iterator<int>(cout, " "));
    cout << endl;

    // remove all elements up to element with value 3
    coll2.erase(coll2.cbegin(), coll2.find(3));
    copy(coll2.cbegin(), coll2.cend(),
         ostream_iterator<int>(cout, " "));
    cout << endl;

    // remove all elements with value 5
    int num;
    num = coll2.erase(5);
    cout << num << " element(s) with value 5 removed" << endl;

    // print all elements
    copy(coll2.cbegin(), coll2.cend(),
         ostream_iterator<int>(cout, " "));

    return 0;
}
