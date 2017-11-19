#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char *argv[])
{
    // create empty deque of strings
    deque<string> coll;

    // insert several elements
    coll.assign(3, "string");
    coll.push_back("last string");
    coll.push_front("first string");
    // insert before the element ("first string")
    coll.insert(find(coll.cbegin(), coll.cend(), "first string"), "string before first string||");

    // print elements separated by newline
    copy(coll.cbegin(), coll.cend(),
         ostream_iterator<string>(cout, "\n"));

    // remove first and last element
    coll.pop_front();
    coll.pop_back();

    cout << endl;
    copy(coll.cbegin(), coll.cend(),
         ostream_iterator<string>(cout, "\n"));

    // insert "another" into every element but the first
    for (int i = 1; i != coll.size(); ++i)
        coll[i] = "another " + coll.at(i);

    cout << "\n";
    copy(coll.cbegin(), coll.cend(),
         ostream_iterator<string>(cout, "\n"));

    // change size to 4 elements
    coll.resize(6, "resized string");

    cout << "\n";
    copy(coll.cbegin(), coll.cend(),
         ostream_iterator<string>(cout, "\n"));

    // reinitialize coll
    coll.assign(4, "Fuck!");
    cout << "\n";
    copy(coll.cbegin(), coll.cend(),
         ostream_iterator<string>(cout, "\n"));
    return 0;
}
