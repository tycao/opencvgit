class C Array : 是一个数组外包装, 它是 "C array" 或者 "const size array"的缩写。
=======
#### C++之父 Bjarne Stroustrup在他所写的 <<The C++ Programming Language>> 一书的第三版中，介绍了一个很有用的数组包装类别， 性能部署为一般的数组，而且更安全。这是 "使用者自行定义STL容器" 的一个好例子。该容器所使用的就是 _包装法_：在数组外包装一层常用的容器界面。

### 本demo就是展现了C array的使用范例：

#### 本demo的目录树：
![tree_of_carray](https://github.com/tycao/opencvgit/blob/master/Cpp_STL/stl_array/const_size_array/src/tree_of_carray.png "tree_of_carray")

#### 主函数：
![main_cpp](https://github.com/tycao/opencvgit/blob/master/Cpp_STL/stl_array/const_size_array/src/main_cpp.png "main_cpp")

#### carray.h
```cpp
#pragma once

#include <cstdlib>
#include <stdexcept>

template<typename T, std::size_t thesize>
class carray
{
public:
    // 类型别名的定义
    typedef T               value_type;
    typedef T*              iterator;
    typedef const T*        const_iterator;
    typedef T&              reference;
    typedef const T&        const_reference;
    typedef std::size_t     size_type;
    typedef std::ptrdiff_t  different_type;

    // 支持迭代
    iterator begin() { return v; }  // 返回数组的首元素
    const_iterator begin() const { return v; }  // begin()成员函数的 常量版本
    iterator end() { return v + thesize; }  // 返回数组中最后一个元素的 下一位置
    const_iterator end() const { return v + thesize; }  // end() 成员函数的 常量版本

    // 对数组元素的直接访问
    reference operator[] (std::size_t t)
    {
        check_size(t);
        return v[t];
    }
    const_reference operator [](std::size_t t) const
    {
        check_size(t);
        return v[t];
    }

    // 数组长度是常数
    size_type size() const { return thesize; }
    size_type max_size() const { return thesize; }

    // conversion to ordinary array
    T* as_array() { return v; }

private:
    T v[thesize];   // 拥有固定长度的类型为T的元素数组
    check_size(std::size_t t)
    {
        if (t < 0 || t >= thesize)
            throw std::runtime_error("exceed the length of the array.");
    }
};

```

#### main.cpp
```cpp
#include <algorithm>
#include "carray.h"
#include "../../../print.h"

int main(int argc, char *argv[])
{
    carray<int, 10> a;

    for (unsigned i = 0; i < a.size(); ++i)
        a[i] = i + 1;

    // print all elements of the carray
    PRINT_ELEMENT(a, "carray : ");


    // reverse all elements of carray
    std::reverse(a.begin(), a.end());
    // print carray after reverse operation
    PRINT_ELEMENT(a, "carray after reverse: ");


    // transform
    std::transform(a.begin(), a.end(),  // source
                   a.begin(),   // destination
                   std::negate<int>()   // operation
                   );
    // print all elements of carray after transform operation
    PRINT_ELEMENT(a, "carray after transform: ");

    return 0;
}

```


#### 程序输出结果：
![output](https://github.com/tycao/opencvgit/blob/master/Cpp_STL/stl_array/const_size_array/src/output.png "output")