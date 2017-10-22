#pragma once
#include <iostream>
#include "listsetnode.h"

using namespace std;

// ��������һ����������Ȼû������ O(��_��)O����~
template<typename T> std::ostream& operator <<(std::ostream& os, ListSet<T>& set);

template<typename T>
class ListSet
{
    // ����һ��Ҫ��ס ȫ�ֺ�������Ԫ�����������ĸ�ʽ
    friend std::ostream& operator << <>(std::ostream& os, ListSet<T>& set);
public:
    ListSet();  // default constructor function
    // public member function
    void Add(T add);
    void Del(T del);
    bool IsEmpty();
    void MakeEmpty();
    ListSetNode<T>* GetHead();
    // ���������
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
    ListSetNode<T>* preCurrent = head;  // ��¼��ǰ�ڵ�
    ListSetNode<T>* current = preCurrent->link; // ��¼��ǰ�ڵ��ǰ�����
    while (current != nullptr && current->data < value) // Ѱ�Ҳ���λ��
    {
        preCurrent = current;
        current = preCurrent->link;
    }
    if (head == tail && current == nullptr) // ��������в���ڵ�
    {
        head->link = add;
        tail = add;
    }
    if (head != tail && current == nullptr) // �������β������ڵ�
    {
        preCurrent->link = add;
        add->link = nullptr;
        tail = add;
    }
    if (current != nullptr && current->data == value)   // �������Ѵ���ֵvalue
    {
        return;
    }
    if (current != nullptr && current->data > value)    // ������β������ֵvalue
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
    while (current != nullptr && current->data != del)  // Ѱ�Ҵ�ɾ���ڵ�
    {
        preCurrent = current;
        current = preCurrent->link;
    }
    if (current != nullptr)
    {
        preCurrent->link = current->link;
        if (current->link == nullptr)
            tail = preCurrent;  // �����βָ��
        delete current;
    }
}
template<typename T>
bool ListSet<T>::IsEmpty()
{
    return head == tail; // �жϼ����Ƿ�Ϊ��
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
        delete del; // ����delete �ͷŵ�ǰ�ڵ�
    }
    tail = head;
}

// ���������
template<typename T>
ListSet<T>& ListSet<T>::operator + (ListSet<T>& another)
{
    ListSetNode<T>* current = another.head;
    current = current->link;
    while (current != nullptr)
    {
        Add(current->data); // ���ú���Addʵ�ּ��ϼ�Ĳ�
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
        Add(current->data); // ���ú���Addʵ�ּ��ϼ�Ĳ�
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



// ���ڣ���ʵ���� listnode.h ��������operator <<()
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
