#pragma once

template<typename T>
struct LinkQueueNode
{
    // 默认构造函数
    LinkQueueNode(T&);
    T data;
    LinkQueueNode<T>* link;
};
template<typename T>
LinkQueueNode<T>::LinkQueueNode(T& value) : data(value), link(nullptr) { }

template<typename T>
class LinkQueue
{
public:
    LinkQueue();    // 默认构造函数
    void EnQueue(T);
    T DelQueue();
    T& GetFront();
    bool MakeEmpty();
    bool IsEmpty();
private:
    LinkQueueNode<T>* front;
    LinkQueueNode<T>* back;
};
template<typename T>
LinkQueue<T>::LinkQueue() : front(nullptr), back(nullptr) {}

