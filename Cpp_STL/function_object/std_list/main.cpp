#include <iostream>
#include <algorithm>
#include <list>
#include <iterator> // for ostream_iterator<>

using namespace std;

// 声明（且同时定义）一个全局函数
// 打印出list的全部元素
void printLists(const list<int>& lhs, const list<int>& rhs)
{
    cout << "list1 : ";
    copy(lhs.cbegin(), lhs.cend(), ostream_iterator<int>(cout, " "));
    cout << endl << "list2 : ";
    copy(rhs.cbegin(), rhs.cend(), ostream_iterator<int>(cout, " "));
    cout << "\n\n";
}

int main(int argc, char *argv[])
{
    // create two empty lists
    list<int> list1, list2;

    // fill both lists with elements
    for (int i = 0; i != 6; ++i)
    {
        list1.push_back(i);
        list2.push_front(i);
    }
    printLists(list1, list2);

    // insert all elements of list1 before the first element with value 3 of list2
    // - find() returns an iterator to the first element with value 3
    list2.splice(find(list2.cbegin(), list2.cend(), 3),     // destination position
                 list1);    // source list
    printLists(list1, list2);

    // move the first element to the end
    list2.splice(list2.end(),   // destination position
                 list2, // source list
                 list2.cbegin() //  source position
                 );
    printLists(list1, list2);

    // sort the 2nd list, assign to list1 and remove duplicates
    list2.sort();   // by default, sort by " operator <() "
    list1 = list2;
    list2.unique(); // 若存在若干相邻而数值相等的元素，就移除重复元素，只留下一个【前提是相邻二数值相等，所以必须先排序，再调用list<>::unique】
    printLists(list1, list2);

    // merge both sorted lists into the first list
    list1.merge(list2);
    printLists(list1, list2);
    return 0;
}
