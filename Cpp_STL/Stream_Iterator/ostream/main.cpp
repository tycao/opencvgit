#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main(int argc, char *argv[])
{
    // 为标准输出流 创建 输出流迭代器
    // 每个值 以换行符分割
    ostream_iterator<int> intWrite(cout, "\n");

    // write elements with the usual iterator interface
    *intWrite = 42;
    ++intWrite;
    *intWrite = 77;
    ++intWrite;
    *intWrite = -5;
    ++intWrite;

    // 创建一个新vector，元素从1到9
    vector<int> coll;
    for (int i = 1; i != 10; ++i)
        coll.push_back(i);

    // write all elements without any delimiter
    copy(coll.cbegin(), coll.cend(),
         ostream_iterator<int>(cout));
    cout << endl;

    // write all elements with " < " delimiter
    copy(coll.cbegin(), coll.cend(),
         ostream_iterator<int>(cout, " < "));
    cout << "\n";

    return 0;
}
