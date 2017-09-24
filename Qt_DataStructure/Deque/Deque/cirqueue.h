#pragma once

#include <cassert>

template<typename T>
class CirQueue
{
public:
    CirQueue(); // 默认构造函数
    CirQueue(int);  // 带有一个类型为int形参的构造函数
    void EnQueue(T);
    T DelQueue();
    T& GetFront();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
private:
    int size;
    int front;
    int back;
    T* contain;
};
template<typename T>
CirQueue<T>::CirQueue() :
    size(0), front(0), back(0), contain(nullptr) { } // 默认构造函数
template<typename T>
CirQueue<T>::CirQueue(int MaxSize) :
    size(MaxSize + 1), back(0), front(0), contain(new T[MaxSize + 1]) { } // 带有一个类型为int形参的构造函数
template<typename T>
void CirQueue<T>::EnQueue(T element)
{
    // 向队列中添加新元素
    assert(!IsFull());
    contain[back] = element;
    back = (back + 1) % size;   // 循环
}
template<typename T>
T CirQueue<T>::DelQueue()
{
    // 从队列中删除队列的头元素
    T old = contain[front];
    front = (front + 1) % size; // 循环
    return old;
}
template<typename T>
T& CirQueue<T>::GetFront()
{
    // 返回队列的头元素
    assert(!IsEmpty());
    return contain[front];
}
template<typename T>
void CirQueue<T>::MakeEmpty()
{
    // 置空队列
    front = back = 0;
}
template<typename T>
bool CirQueue<T>::IsEmpty()
{
    // 判断队列是否为空
    return front == back;
}
template<typename T>
bool CirQueue<T>::IsFull()
{
    // 判断队列是否已满
    return (back + 1) % size == front;
}
