#pragma once
#include <iostream>
#include "listsetnode.h"

using namespace std;

// 在这里再一次声明，竟然没有问题 O(∩_∩)O哈哈~
template<typename T> std::ostream& operator <<(std::ostream& os, ListSet<T>& set);

template<typename T>
class ListSet
{
    // 这里一定要记住 全局函数的友元函数的声明的格式
    friend std::ostream& operator << <>(std::ostream& os, ListSet<T>& set);
public:
    ListSet();  // default constructor function
    // public member function
    void Add(T add);
    void Del(T del);
    bool IsEmpty();
    void MakeEmpty();
    ListSetNode<T>* GetHead();
    // 运算符重载
    ListSet<T>& operator + (ListSet<T>& another);
    ListSet<T>& operator - (ListSet<T>& another);
    ListSet<T>& operator * (ListSet<T>& another);
    ListSet<T>& operator = (ListSet<T>& another);
    bool        operator == (ListSet<T>& another);
private:
    ListSetNode<T>* head;
    ListSetNode<T>* tail;
};

// public member function
template<typename T>
ListSet<T>::ListSet()
    : head(new ListSetNode<T>()), tail(new ListSetNode<T>())
{

}
template<typename T>
ListSetNode<T>* ListSet<T>::GetHead()
{
    return this->head;
}

// public member function
template<typename T>
void ListSet<T>::Add(T value)
{
    ListSetNode<T>* add = new ListSetNode<T>(value);
    ListSetNode<T>* preCurrent = head;  // 记录当前节点
    ListSetNode<T>* current = preCurrent->link; // 记录当前节点的前驱结点
    while (current != nullptr && current->data < value) // 寻找插入位置
    {
        preCurrent = current;
        current = preCurrent->link;
    }
    if (head == tail && current == nullptr) // 向空链表中插入节点
    {
        head->link = add;
        tail = add;
    }
    if (head != tail && current == nullptr) // 向链表的尾部插入节点
    {
        preCurrent->link = add;
        add->link = nullptr;
        tail = add;
    }
    if (current != nullptr && current->data == value)   // 链表中已存在值value
    {
        return;
    }
    if (current != nullptr && current->data > value)    // 向链表尾部插入值value
    {
        preCurrent->link = add;
        add->link = current;
    }
}
template<typename T>
void ListSet<T>::Del(T del)
{
    ListSetNode<T>* preCurrent = head;
    ListSetNode<T>* current = preCurrent->link;
    while (current != nullptr && current->data != del)  // 寻找待删除节点
    {
        preCurrent = current;
        current = preCurrent->link;
    }
    if (current != nullptr)
    {
        preCurrent->link = current->link;
        if (current->link == nullptr)
            tail = preCurrent;  // 变更表尾指针
        delete current;
    }
}
template<typename T>
bool ListSet<T>::IsEmpty()
{
    return head == tail; // 判断集合是否为空
}
template<typename T>
void ListSet<T>::MakeEmpty()
{
    ListSetNode<T>* current = head->link;
    ListSetNode<T>* del = nullptr;
    while (head->link != nullptr)
    {
        head->link = current->link;
        del = current;
        current = current->link;
        delete del; // 调用delete 释放当前节点
    }
    tail = head;
}

// 运算符重载
template<typename T>
ListSet<T>& ListSet<T>::operator + (ListSet<T>& another)
{
    ListSetNode<T>* current = another.head;
    current = current->link;
    while (current != nullptr)
    {
        Add(current->data); // 利用函数Add实现集合间的并
        current =current->link;
    }
    return *this;
}
template<typename T>
ListSet<T>& ListSet<T>::operator - (ListSet<T>& another)
{
    ListSetNode<T>* current = another.head->link;
    while (current != nullptr)
    {
        this->Del(current->data);
        current = current->link;
    }
    return *this;
}
template<typename T>
ListSet<T>& ListSet<T>::operator * (ListSet<T>& another)
{
    ListSet<T> temp;
    temp = *this;
    *this = temp - (*this - another);
    temp.MakeEmpty();
    return *this;
}
template<typename T>
ListSet<T>& ListSet<T>::operator = (ListSet<T>& another)
{
    MakeEmpty();
    ListSetNode<T>* current = another.head->link;
    while (current != nullptr)
    {
        Add(current->data); // 利用函数Add实现集合间的并
        current =current->link;
    }
    return *this;
}
template<typename T>
bool ListSet<T>::operator == (ListSet<T>& another)
{
    ListSetNode<T>* current1 = head->link;
    ListSetNode<T>* current2 = another.head->link;
    while (current1 != nullptr)
    {
        if (current2 == nullptr) return false;
        if (current1->data != current2->data) return false;
        current1 = current1->link;
        current2 = current2->link;
    }
    if (current2 != nullptr) return false;
    if (current1 == nullptr && current2 == nullptr) return true;
    return true;
}



// 现在，来实现在 listnode.h 里声明的operator <<()
template<typename T>
std::ostream& operator << (std::ostream& os, ListSet<T>& set)
{
    ListSetNode<T>* current = set.GetHead()->link;
    while (current != nullptr)
    {
        cout << "*" << current->data;
        current = current->link;
    }
    return os;
}
