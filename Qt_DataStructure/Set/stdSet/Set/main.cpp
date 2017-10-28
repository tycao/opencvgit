#include <set>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

/*
 * set里面有 :
 * set_intersection（取集合交集）、set_union（取集合并集）、
 * set_difference（取集合差集）、set_symmetric_difference（取集合对称差集）
 * 等函数
*/

int main(int argc, char *argv[])
{
    std::set<int> MySet2;
    std::set<int> MySet3;
    std::set<int>::iterator i;
    int a[] = {1, 2, 3, 4, 5};
    set<int> MySet1{begin(a), begin(a) + 5};

    // Operation on MySet1
    cout << MySet1.size() << endl;
    i = MySet1.begin();
    cout << "MySet1 :";
    // 遍历 输出
    while (i != MySet1.end())
        cout << *i++ << " ";

    // operation on MySet2
    MySet2.insert(2);
    MySet2.insert(3);
    MySet2.insert(5);
    MySet2.insert(7);
    cout << endl;
    // 遍历输出 MySet2
    cout << "MySet2 :";
    std::for_each(MySet2.begin(), MySet2.end(), [&](int i){ cout << i << " "; });

    cout << endl;
    if (MySet2.find(5) != MySet2.end())
        cout << "MySet2 contains 5";
    ostream_iterator<int> out(cout, " ");   // ostream_iterator : 定义在头文件 <iterator> 内
    // 求集合MySet1与MySet2的交集
    cout << "\nMySet1与MySet2的交集：";
    set_intersection( MySet1.begin(), MySet1.end(),
                      MySet2.begin(), MySet2.end(),
                      out );
    // 求集合MySet1和MySet2的并集
    cout << "\nMySet1和MySet2的并集：";
    set_union(MySet1.begin(), MySet1.end(),
              MySet2.begin(), MySet2.end(),
              out);
    // 求集合MySet1和MySet2的差集
    cout << "\nMySet1和MySet2的差集：";
    set_difference(MySet1.begin(), MySet1.end(),
                   MySet2.begin(), MySet2.end(),
                   out);

    cout << "\nMySet2和MySet1的差集：";
    set_difference(MySet2.begin(), MySet2.end(),
                   MySet1.begin(), MySet1.end(),
                   out);

    cout << endl;
    // 求集合MySet1和MySet2的对称差
    set_symmetric_difference(MySet1.begin(), MySet1.end(),
                             MySet2.begin(), MySet2.end(),
                             inserter(MySet3, MySet3.begin())); // inserter : 定义在头文件 <iterator> 内

    cout << "MySet1和MySet2的对称差：";
    set<int>::iterator j = MySet3.begin();
    //while (j != MySet3.end())
      //  cout << *j++ << " ";
    std::for_each(MySet3.begin(), MySet3.end(), [&](int i){ cout << i << " "; });
    cout << endl;

    return 0;
}
