#pragma once
#include <memory>   // for allocator<T>
#include <iostream>

namespace std {
// 类型别名定义
typedef int size_type;

template<typename T, typename Allocator = allocator<T>>
class vector {
public:
    // 构造函数
    explicit vector(const Allocator a = Allocator());
    explicit vector(size_type num, const T& val = T(), const Allocator& a = Allocator());

    template<typename InputIterator>
    vector(InputIterator begin, InputIterator end, const Allocator& = Allocator());

    vector(const vector<T, Allocator>& v);

    void print() const;
private:
    Allocator alloc;    // 配置器
    T* elems;    // 元素数组
    size_type numElems; // 元素数量
    size_type sizeElems;    // 所有元素的内存大小
};
}

// 函数实现部分
namespace std
{
template<typename T, typename Allocator>
vector<T, Allocator>::vector(size_type num, const T& val, const Allocator& a)
    : alloc(a)  // 初始化列表：初始化配置器
{
    // allocate memory
    sizeElems = numElems = num;
    elems = alloc.allocate(num);
/*
    // 初始化元素
    for (size_type i = 0; i != num; ++i) {
        // 初始化第i个元素
        alloc.construct(&elems[i], val);
    }
*/
    // 第二种方式初始化元素
    uninitialized_fill_n(elems, num, val);
}

template<typename T, typename Allocator>
vector<T, Allocator>::vector(const Allocator a)
    : alloc(a), sizeElems(0), numElems(0), elems(nullptr)
{

}

template<typename T, typename Allocator>
void vector<T, Allocator>::print() const {
    for (size_type i = 0; i < numElems; ++i)
    {
        cout << elems[i] << " ";
    }
    cout << "\n";
}
}

