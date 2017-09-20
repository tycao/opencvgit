#pragma once

#include <iostream>
#include "doulist.h"

using namespace std;

template<typename T> class Iterator;
template<typename T> T operator ++ (Iterator<T>&);   // 前置递增运算符 重载
template<typename T> T operator ++ (Iterator<T>&, int);  // 后置递增运算符 重载
template<typename T> T operator -- (Iterator<T>&);   // 前置递减运算符 重载
template<typename T> T operator -- (Iterator<T>&, int);  // 后置递减运算符 重载
template<typename T> bool operator == (Iterator<T>&, DouListNode<T>*);  // 相等运算符 重载
template<typename T> bool operator != (Iterator<T>&, DouListNode<T>*);  // 不相等运算符 重载
template<typename T> std::ostream& operator << (std::ostream&, Iterator<T>&);   // 输出运算符 重载

template<typename T>
class Iterator
{
    friend T operator ++ <> (Iterator<T>&);   // 前置递增运算符 重载
    friend T operator ++ <> (Iterator<T>&, int);   // 后置递增运算符 重载
    friend T operator -- <> (Iterator<T>&);   // 前置递减运算符 重载
    friend T operator -- <> (Iterator<T>&, int);  // 后置递减运算符 重载
    friend bool operator == <> (Iterator<T>&, DouListNode<T>*);   // 相等运算符 重载
    friend bool operator != <> (Iterator<T>&, DouListNode<T>*);  // 不相等运算符 重载
    friend std::ostream& operator << <> (std::ostream&, Iterator<T>&);  // 输出运算符 重载

public:
    Iterator() : cur(nullptr) {}    // default constructor
    Iterator(DouListNode<T>* point) : cur(point) {} // constructor with one formal parameter

    // 接口函数
    Iterator<T>& operator =(DouListNode<T>*);
    DouListNode<T>*& GetCur();
private:
    DouListNode<T>* cur;
};

template<typename T>
T operator ++ (Iterator<T>& iter)
{
    iter.GetCur() = iter.GetCur()->GetLink();   // cur顺着link方向移动到下一个位置
    T data = iter.GetCur()->GetData();
    return data;
}

template<typename T>
T operator ++ (Iterator<T>& iter, int)
{
    T data = iter.GetCur()->GetData();
    iter.GetCur() = iter.GetCur()->GetLink();
    return data;
}

template<typename T>
T operator -- (Iterator<T>& iter)
{
    iter.GetCur() = iter.GetCur()->GetPrior();
    T data = iter.GetCur()->GetData();
    return data;
}

template<typename T>
T operator -- (Iterator<T>& iter, int)
{
    T data = iter.GetCur()->GetData();
    iter.GetCur() = iter.GetCur()->GetPrior();
    return data;
}

template<typename T>
bool operator == (Iterator<T>& iter, DouListNode<T>* point)
{
    return iter.GetCur() == point;
}

template<typename T>
bool operator != (Iterator<T>& iter, DouListNode<T>* point)
{
    return iter.GetCur() != point;
}

template<typename T>
std::ostream& operator << (std::ostream& os, Iterator<T>& iter)
{
    os << iter.GetCur()->GetData();
    return os;
}

// 接口函数的实现
template<typename T>
Iterator<T>& Iterator<T>::operator =(DouListNode<T>* point)
{
    this->cur = point;
    return *this;
}

template<typename T>
DouListNode<T>*& Iterator<T>::GetCur()
{
    return cur;
}

