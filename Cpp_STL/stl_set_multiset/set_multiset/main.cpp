#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
    /*
     * type of the collection: set
     * - no duplicates
     * - element are integral values
     * - descending order
    */
    typedef set<int, std::greater<int>> IntSet;

    IntSet coll;    // create an empty set container

    // insert elements in random order
    coll.insert(4);
    coll.insert(3);
    coll.insert(5);
    coll.insert(1);
    coll.insert(6);
    coll.insert(2);
    std::pair<IntSet::iterator, bool> iter = coll.insert(5);
    if (iter.second)
        cout << "5 inserted as element" << endl;
    else
        cout << "5 alreay exists" << endl;

    // iterate over all elements and print them
    //IntSet::const_iterator pos;   // initialize an iterator for IntSet type
    for (auto pos = coll.cbegin(); pos != coll.cend(); ++pos)
    {
        cout << *pos << " ";
    }
    cout << "\n\n";

    // insert 4 again and process return value
    std::pair<IntSet::iterator, bool> status = coll.insert(4);
    if (status.second)
        cout << "4 inserted as element "
             << distance(coll.begin(), status.first) + 1
             << endl;
    else
        cout << "4 already exists" << endl;

    // assign elements to another set with ascending order
    // by default, elements are sorted by less<> or "operator <"
    std::set<int> coll2(coll.cbegin(), coll.cend());

    // print all elements of copy
    copy(coll2.cbegin(), coll2.cend(),
         std::ostream_iterator<int>(cout, " "));
    cout << endl;

    // reomve all elements up to element with 3 (excluding element with value 3)
    coll2.erase(coll2.cbegin(), coll2.find(3));
    copy(coll2.cbegin(), coll2.cend(),
         std::ostream_iterator<int>(cout, " "));
    cout << "\n\n";

    // remove all elements with value 5
    int num;
    num = coll2.erase(5);
    cout << num << " element(s) removed." << endl;

    // print all elements
    copy(coll2.cbegin(), coll2.cend(),
         std::ostream_iterator<int>(cout, " "));
    cout << "\n\n";

    return 0;
}
