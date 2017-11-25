#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <iterator>
#include"countedptr.h"

// 以下程序说明如何使用 CountedPtr 智能指针

// 定义一个全局函数，用来打印CountedPtr所引用的对象
void printCountedPtr(const CountedPtr<int>& elem)
{
    std::cout << *elem << " ";
}

int main(int argc, char *argv[])
{
    // 静态数组
    static int value[] = {3, 5, 9, 1, 6, 4};

    // 两种不同的容器
    typedef CountedPtr<int> IntPtr;
    std::deque<IntPtr> coll1;
    std::list<IntPtr> coll2;

    // 将引用的对象插入容器内
    for (int i = 0; i != sizeof(value) / sizeof(value[0]); ++i)
    {
        IntPtr ptr(new int(value[i]));
        coll1.push_back(ptr);
        coll2.push_front(ptr);  // reverse order comapred with coll1
    }

    // 分别打印两个容器的元素
    std::for_each(coll1.begin(), coll1.end(), [&](CountedPtr<int>& i){ std::cout << *i << " "; });
    std::cout << "\n\n";
    std::for_each(coll2.begin(), coll2.end(), printCountedPtr);
    std::cout << "\n\n";

    *coll1[2] *= *coll1[2];
    **coll1.begin() *= -1;
    **coll2.begin() = 0;

    // 修改数据后，分别打印两个容器内的所有元素
    std::for_each(coll1.begin(), coll1.end(), printCountedPtr);
    std::cout << "\n\n";
    std::for_each(coll2.begin(), coll2.end(), printCountedPtr);
    std::cout << "\n\n";

    return 0;
}
