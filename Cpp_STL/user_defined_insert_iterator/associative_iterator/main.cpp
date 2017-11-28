#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

#include "../../../print.h"
#include "assoiter.h"

int main(int argc, char *argv[])
{
    set<int> coll;
    // 用初始化方式（原始方式），为std::set集合的对象 创建一个插入迭代器
    asso_insert_iterator<set<int>> iter(coll);
    *iter = 1;
    iter++;
    *iter = 2;
    ++iter;
    ++iter = 3;

    // 打印 赋值之后的 std::set<int>集合 coll
    PRINT_ELEMENT(coll, "coll : ");

    // 使用更方便方式（接口函数），来为std::set<int>集合 创建插入迭代器
    asso_insert<set<int>>(coll) = 55;
    asso_insert<set<int>>(coll) = 66;

    // 打印set集合
    PRINT_ELEMENT(coll, "coll after inserting values with an convenient way : ");

    // 使用算法，来插入元素
    int vals[] = {33, 88, -7, 9, 25, 13, 2, 3, 18};
    copy(vals, vals + (sizeof(vals) / sizeof(vals[0])), // source iterator : 源迭代器范围
         asso_insert<set<int>>(coll));  // 目的地 迭代器

    // 打印数据
    PRINT_ELEMENT(coll, "coll after using algorithm to insert values : ");
    return 0;
}
