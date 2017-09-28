#pragma once

#include <cassert>

// 优先级队列节点类
template<typename T>
class PriQueueNode
{
public:
    PriQueueNode(T& value) : data(value), link(nullptr) { } // 带有一个T类型形参的构造函数
    T data;
    PriQueueNode<T>* link;
};

// 优先级队列类
template<typename T>
class PriQueue
{
public:
    PriQueue(); // 默认构造函数
    void EnQueue(T& element);
    T DelQueue();
    T& GetFront();
    bool MakeEmpty();
    bool IsEmpty();
private:
    PriQueueNode<T>* front;
    PriQueueNode<T>* back;
};

// 优先级队列类的实现
template<typename T>
PriQueue<T>::PriQueue() : front(nullptr), back(nullptr) { }

template<typename T>
void PriQueue<T>::EnQueue(T &element)
{
    PriQueueNode<T>* add = new PriQueueNode<T>(element);
    if (back == nullptr)
        front = back = add; // 若添加第一个节点，则需使front指向这个节点
    else
    {
        back->link = add;   // 若队列中已有栈点，则只需要更改back的指针
        back = back->link;
    }
}


template<typename T>
T PriQueue<T>::DelQueue()
{
    PriQueueNode<T>* seek = front->link;    // 遍历队列，寻找最小元素的指针
    PriQueueNode<T>* min = front;   // 指向最小的元素
    T minData;  // 记录最小元素的数据
    while (seek != nullptr)
    {
        if (seek->data < min->data) //寻找最小元素：【注意】此处用到了T类型的'<'比较运算符。若T是用户自定义的类型，则需要重载T的<运算符
            min = seek;
        seek = seek->link;
    }
    seek = front;   // 指针重回队列头部
    while (seek != nullptr && seek->link != min)    // 寻找最小元素的前驱结点
        seek = seek->link;
    if (seek == nullptr)    // 若最小元素位于队列头部
    {
        minData = min->data;    // minData = front->data;
        front = front->link;    // 更新队头指针
        delete min;
    }
    if (min->link == nullptr)   // 若最小元素位于队列尾部
        back = seek;    // 更新队尾指针
    if (seek != nullptr)    // 若最小元素位于队列中间，无需更新
    {
        minData = min->data;    // 队头指针 与 队尾指针，直接删除即可
        seek->link = min->link;
        delete min;
    }
    return minData; // 返回数据
}

template<typename T>
T& PriQueue<T>::GetFront()
{
    assert(!this->IsEmpty());
    return front->data;
}

template<typename T>
bool PriQueue<T>::MakeEmpty()
{
    while (!this->IsEmpty())
        this->DelQueue();
    return this->IsEmpty();
}

template<typename T>
bool PriQueue<T>::IsEmpty()
{
    return front == nullptr;
}


