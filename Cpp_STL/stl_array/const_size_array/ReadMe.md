class C Array : ��һ���������װ, ���� "C array" ���� "const size array"����д��
=======
#### C++֮�� Bjarne Stroustrup������д�� <<The C++ Programming Language>> һ��ĵ������У�������һ�������õ������װ��� ���ܲ���Ϊһ������飬���Ҹ���ȫ������ "ʹ�������ж���STL����" ��һ�������ӡ���������ʹ�õľ��� _��װ��_�����������װһ�㳣�õ��������档

### ��demo����չ����C array��ʹ�÷�����

#### ��demo��Ŀ¼����
![tree_of_carray](https://github.com/tycao/opencvgit/blob/master/Cpp_STL/stl_array/const_size_array/src/tree_of_carray.png "tree_of_carray")

#### ��������
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
    // ���ͱ����Ķ���
    typedef T               value_type;
    typedef T*              iterator;
    typedef const T*        const_iterator;
    typedef T&              reference;
    typedef const T&        const_reference;
    typedef std::size_t     size_type;
    typedef std::ptrdiff_t  different_type;

    // ֧�ֵ���
    iterator begin() { return v; }  // �����������Ԫ��
    const_iterator begin() const { return v; }  // begin()��Ա������ �����汾
    iterator end() { return v + thesize; }  // �������������һ��Ԫ�ص� ��һλ��
    const_iterator end() const { return v + thesize; }  // end() ��Ա������ �����汾

    // ������Ԫ�ص�ֱ�ӷ���
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

    // ���鳤���ǳ���
    size_type size() const { return thesize; }
    size_type max_size() const { return thesize; }

    // conversion to ordinary array
    T* as_array() { return v; }

private:
    T v[thesize];   // ӵ�й̶����ȵ�����ΪT��Ԫ������
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


#### ������������
![output](https://github.com/tycao/opencvgit/blob/master/Cpp_STL/stl_array/const_size_array/src/output.png "output")