����ʵ��Reference�Ķ���
======
#### ��Ҫ��STL�������õ���Reference���塱����������ΪԪ�صĸ��ƴ���̫�󣬻�������Ϊ��Ҫ�ڲ�ͬ�������� ���� ͬһ�����󣩣���Ҫ����������ָ�룬������ܵĴ���������һ������취����ָ����ָ�Ķ������ *���ü�����reference counting��������ָ��*��

### demo��Ŀ¼���ṹ ��
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
        : ptr(p),   // ��ʼ��Ϊ��ָ��
          count(new long(1))    // ��ʼ��Ϊ 1
    { }    // �յĺ����� �� �����κβ���

    // �������캯��
    CountedPtr(const CountedPtr<T>& p) noexcept(false)
        : ptr(p.ptr),
          count(p.count)
    {
        ++(*count);
    }

    // ������ֵ�����
    CountedPtr& operator =(const CountedPtr<T>& p)
    {
        // ��ֹ�Ը�ֵ
        if (this != &p)
        {
            dispose();
            ptr = p.ptr;
            count = p.count;
            ++*count;
        }
        return *this;
    }

    // ��������
    ~CountedPtr() noexcept(false)
    {
        dispose();  // ����ǰ����û�б��������������ˣ���С�۵�ǰ���� �Լ� ��Ӧ�����ü���
    }

    // ���� �Զ��������
    T& operator *() const noexcept(false)
    {
        return *this->ptr;
    }

    T* operator ->() const noexcept(false)
    {
        return this->ptr;
    }
private:
    T* ptr;     // ���õĶ���
    long* count;    // ���ü��� �� ������¼һ���������ö��ٴ�

    // �ж����ü����Ƿ�Ϊ0�����ǣ������ٱ����õĶ��� �Լ� ���ü���
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

// ���³���˵�����ʹ�� CountedPtr ����ָ��

// ����һ��ȫ�ֺ�����������ӡCountedPtr�����õĶ���
void printCountedPtr(const CountedPtr<int>& elem)
{
    std::cout << *elem << " ";
}

int main(int argc, char *argv[])
{
    // ��̬����
    static int value[] = {3, 5, 9, 1, 6, 4};

    // ���ֲ�ͬ������
    typedef CountedPtr<int> IntPtr;
    std::deque<IntPtr> coll1;
    std::list<IntPtr> coll2;

    // �����õĶ������������
    for (int i = 0; i != sizeof(value) / sizeof(value[0]); ++i)
    {
        IntPtr ptr(new int(value[i]));
        coll1.push_back(ptr);
        coll2.push_front(ptr);  // reverse order comapred with coll1
    }

    // �ֱ��ӡ����������Ԫ��
    std::for_each(coll1.begin(), coll1.end(), [&](CountedPtr<int>& i){ std::cout << *i << " "; });
    std::cout << "\n\n";
    std::for_each(coll2.begin(), coll2.end(), printCountedPtr);
    std::cout << "\n\n";

    *coll1[2] *= *coll1[2];
    **coll1.begin() *= -1;
    **coll2.begin() = 0;

    // �޸����ݺ󣬷ֱ��ӡ���������ڵ�����Ԫ��
    std::for_each(coll1.begin(), coll1.end(), printCountedPtr);
    std::cout << "\n\n";
    std::for_each(coll2.begin(), coll2.end(), printCountedPtr);
    std::cout << "\n\n";

    return 0;
}

```		

### �������������
![output](https://github.com/tycao/opencvgit/blob/master/Cpp_STL/stl_array/smart_pointer/src/output.png "output")	  