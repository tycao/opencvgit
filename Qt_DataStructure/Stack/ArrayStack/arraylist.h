/*
 * 栈有两种实现方式：使用数组实现 和 使用链表实现
 * 用数组实现的栈叫做 顺序栈 ： 顺序栈是在内存中连续存储的。
 * 用链表实现的栈叫做 链式栈 ： 链式栈是在内存中链式（分散）存储的。
 * 由顺序栈的实现方式可知：顺序栈存放元素的总数是有限的。因此，在向顺序栈中添加元素前，要先判断栈是否已满。若已满，则忽略添加操作。
 * 同样，在删除栈中元素前，应该判断栈是否为空，若是空栈，则忽略删除（出栈）操作。
 *
 * 以下是顺序栈的类定义：
*/
#pragma once

#include <cassert>

template<typename T>
class ArrayStack
{
public:
    ArrayStack() : size(0), tos(-1), contain(nullptr) {}    // 默认构造函数
    ArrayStack(int MaxSize);    // 带有一个int型参数的默认构造函数
    void Push(const T& element);
    T& GetTop();
    T& Pop();
    bool IsEmpty();
    bool MakeEmpty();
private:
    int tos; // 栈顶索引
    int size;
    T* contain;
};
// 成员函数的实现
template<typename T>
ArrayStack<T>::ArrayStack(int MaxSize)
{
    // 构造函数
    size = MaxSize;
    tos = -1;
    contain = new T[size];
}
template<typename T>
void ArrayStack<T>::Push(const T& element)
{
    // 向栈中添加新元素
    assert(tos != size - 1);
    contain[++tos] = element;
}
template<typename T>
T& ArrayStack<T>::GetTop()
{
    // 返回栈顶元素
    assert(tos != -1);  // 确保栈非空
    return contain[tos];
}
template<typename T>
T& ArrayStack<T>::Pop()
{
    // 从栈顶删除元素
    assert(tos != -1);
    return contain[tos--];
}
template<typename T>
bool ArrayStack<T>::IsEmpty()
{
    // 判断栈是否为空
    return tos == -1;
}
template<typename T>
bool ArrayStack<T>::MakeEmpty()
{
    // 置空栈
    tos = -1;
    delete [] contain;
    if (this->IsEmpty())
        return true;
    else
        return false;
}
