#include <iostream>
#include <set>
#include <deque>
#include <algorithm>
#include <functional>
#include "../../print.h"

using namespace std;

int main(int argc, char *argv[])
{
    std::set<int, greater<int>> coll1;
    deque<int> coll2;   // 队列（LIFO 后进先出）

    // insert elements from 1 to 9
    for (int i = 1; i != 10; ++i)
        coll1.insert(i);

    // 打印整个coll1
    PRINT_ELEMENT(coll1, "initialized: ");

    // transform all elements into coll2 by multiplying 10
    transform(coll1.begin(), coll1.end(),   // 遍历整个coll1的所有元素
              back_inserter(coll2), // 插入到coll2尾部
              std::bind(multiplies<int>(), std::placeholders::_1, 10)); // 将每个元素都乘以10
    coll2.push_back(70);

    // 打印整个coll2
    PRINT_ELEMENT(coll2, "transformed: ");

    // 把元素数值等于70的元素 替换为 42
    std::replace_if(coll2.begin(), coll2.end(), // 遍历整个coll2
                    std::bind(equal_to<int>(), std::placeholders::_1, 70),  // 找出所有等于70的元素
                    42);    // 将其换成42

    // 打印替换后的coll2
    PRINT_ELEMENT(coll2, "replaced: ");

    // 删除元素数值小于50的元素
    coll2.erase(remove_if(coll2.begin(), coll2.end(),   // 删除所有小于50的元素
                          std::bind(std::less<int>(), std::placeholders::_1, 50)),
                coll2.end());

    // 打印删除后的coll2
    PRINT_ELEMENT(coll2, "removed: ");

    return 0;
}
