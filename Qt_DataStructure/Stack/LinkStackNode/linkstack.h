#pragma once

#include <cassert>
#include "linkstacknode.h"

template<typename T>
class LinkStack
{
public:
    LinkStack();  // 默认构造函数
    LinkStack(T); // 带有一个T类型参数的构造函数

    LinkStack<T>& Push(T value);
    T& GetTop();
    T Pop();
    bool IsEmpty();
    bool MakeEmpty();
private:
    LinkStackNode<T>* tos;
};

// 成员函数的实现
template<typename T>
LinkStack<T>::LinkStack() : tos(nullptr) { }  // 默认构造函数
template<typename T>
LinkStack<T>::LinkStack(T value) : tos(new LinkStackNode<T>(value)) { } // 带有一个T类型参数的构造函数

template<typename T>
LinkStack<T>& LinkStack<T>::Push(T value)
{
    LinkStackNode<T>* add = new LinkStackNode<T>(value);
    add->GetLink() = tos;   // 当前的栈顶元素，成为新加元素的后继结点。
    tos = add; //  更新栈顶元素 ：使刚加进来的元素成为栈顶元素
    return *this;
}

template<typename T>
T& LinkStack<T>::GetTop()
{
    return tos->GetData();
}

template<typename T>
T LinkStack<T>::Pop()
{
    assert(tos != nullptr); // 首先判断链式栈非空
    LinkStackNode<T>* old = tos;    // 然后暂时获得栈顶元素的指针
    tos = tos->GetLink();   // 删除栈顶元素
    T data = old->GetData();    // 获得临时栈顶元素的包含的数据，带回作为汉书的返回值。
    delete old; // 删除当前栈顶元素
    return data;  // 返回旧的栈顶元素内包含的数据
}

template<typename T>
bool LinkStack<T>::IsEmpty()
{
    return tos == nullptr;
}

template<typename T>
bool LinkStack<T>::MakeEmpty()
{
    while (!this->IsEmpty())
        this->Pop();
    return tos == nullptr;
}
