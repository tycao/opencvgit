/*
 * STL里的链表类（list）是一个 *双向循环链表* 类。这意味着链表类（list）支持从表尾到表头的循环。
*/
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
#if 0
    list<int> myList;
    std:;vector<int> vInt{1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    for_each(vInt.begin(), vInt.end(), [&myList](int i){ myList.push_back(i); });
    for_each(myList.begin(), myList.end(), [](int& i){ cout << i << " "; });

    typedef list<int>::iterator iterator;
    iterator iter = myList.begin();
    iterator end = myList.end();
    //for_each(iter, end, [](int& i){ cout << i << " "; });
    while (iter != end)
    {
        cout << *iter++ << endl;
    }
#endif

#if 1
    // add element
    list<int> back1;
    for (int i = 0; i != 5; ++i)
        back1.push_back(i);

    // reversely foreach
    typedef list<int>::reverse_iterator iterator;   // type alias
    iterator iter = back1.rbegin();  // reverse iterator
    auto end = back1.rend();    // auto detect
    //while (iter != end)
    //    cout << *iter++ << " ";
    // equivlevant expression
    for_each(iter, end, [](int& i){ cout << i << " "; });
#endif
    return 0;
}
