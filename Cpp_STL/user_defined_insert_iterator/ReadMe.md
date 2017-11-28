User-Defined iterator（使用者自定义的迭代器）
========
让我们自己来写个迭代器吧！
--------
### 这是一个关联式容器的迭代器：
#### 它的目录树如下：
![tree](https://github.com/tycao/opencvgit/blob/master/Cpp_STL/user_defined_insert_iterator/src/tree.png "tree")

### 自定义的 插入迭代器如下：
#### assoiter.h
```cpp
#pragma once

#include <iterator>

/*
 * 这是一个关联式容器的insert迭代器 的模版类的创建源代码
*/
template<typename Container>
class asso_insert_iterator : public std::iterator<std::output_iterator_tag, void, void, void, void>
{
public:
    // 构造函数
    explicit asso_insert_iterator(Container& c)
        : container(c)
    {

    }

    // 拷贝赋值运算符
    // 将一条数据插入到容器内
    asso_insert_iterator<Container>& operator =(const typename Container::value_type& value)
    {
        container.insert(value);
        return *this;
    }

    // 解引用运算符
    // 不做任何操作，直接返回迭代器自身
    asso_insert_iterator<Container>& operator *()
    {
        return *this;
    }

    // 前置递增运算符
    // 不做任何操作，直接返回迭代器自身
    asso_insert_iterator<Container>& operator ++()
    {
        return *this;
    }

    // 后置递增运算符
    // 不做任何操作，直接返回迭代器自身
    asso_insert_iterator<Container>& operator ++(int)
    {
        return *this;
    }
protected:
    Container& container;   // 元素需要插入到此容器内
private:

};

// 更简单的接口，用来创建插入迭代器
// 是个内联函数 ： 编译器就可以展开该函数，降低运行时开销
template<typename Container>
inline asso_insert_iterator<Container> asso_insert(Container& c)
{
    return asso_insert_iterator<Container>(c);
}
```

#### main.cpp
```cpp
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
```

### 程序输出结果：
![output](https://github.com/tycao/opencvgit/blob/master/Cpp_STL/user_defined_insert_iterator/src/output.png "output")