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
