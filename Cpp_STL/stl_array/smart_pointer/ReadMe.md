动手实现Reference的定义
======
#### 想要在STL容器中用到“Reference语义”（不论是因为元素的复制代价太大，或者是因为需要在不同的容器内 享用 同一个对象），就要采用智能型指针，避免可能的错误。这里有一个解决办法：对指针所指的对象采用 *引用计数（reference counting）智能型指针*。

### demo的目录树结构 ：
* Project:
 ** countedptr.h
 ** main.cpp
![CountedPtr](https://github.com/tycao/opencvgit/blob/master/Cpp_STL/stl_array/smart_pointer/src/CountedPtr.png "CountedPtr")

### countedptr.h
```cpp
#pragma once


/*
 * class for counted reference semantics
 * - delete the object to which it refers when the last CountedPtr that refers to it is destroyed
*/
template<typename T>
class CountedPtr
{
public:
    explicit CountedPtr(T* p = nullptr)
        : ptr(p),   // 初始化为空指针
          count(new long(1))    // 初始化为 1
    { }    // 空的函数体 ： 不做任何操作

    // 拷贝构造函数
    CountedPtr(const CountedPtr<T>& p) noexcept(false)
        : ptr(p.ptr),
          count(p.count)
    {
        ++(*count);
    }

    // 拷贝赋值运算符
    CountedPtr& operator =(const CountedPtr<T>& p)
    {
        // 防止自赋值
        if (this != &p)
        {
            dispose();
            ptr = p.ptr;
            count = p.count;
            ++*count;
        }
        return *this;
    }

    // 析构函数
    ~CountedPtr() noexcept(false)
    {
        dispose();  // 若当前对象没有被其他对象引用了，则小慧当前对象 以及 相应的引用计数
    }

    // 重载 自定义运算符
    T& operator *() const noexcept(false)
    {
        return *this->ptr;
    }

    T* operator ->() const noexcept(false)
    {
        return this->ptr;
    }
private:
    T* ptr;     // 引用的对象
    long* count;    // 引用计数 ： 用来记录一个对象被引用多少次

    // 判断引用计数是否为0，若是，则销毁被引用的对象 以及 引用计数
    void dispose()
    {
        if (--*count == 0)
        {
            delete count;
            delete ptr;
        }
    }
};

```

### main.cpp
```cpp
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

```		

### 程序的输出结果：
![output](https://github.com/tycao/opencvgit/blob/master/Cpp_STL/stl_array/smart_pointer/src/output.png "output")	  