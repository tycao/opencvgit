#pragma once

#include <cassert>
#include "linkstacknode.h"

template<typename T>
class LinkStack
{
public:
    LinkStack();  // Ĭ�Ϲ��캯��
    LinkStack(T); // ����һ��T���Ͳ����Ĺ��캯��

    LinkStack<T>& Push(T value);
    T& GetTop();
    T Pop();
    bool IsEmpty();
    bool MakeEmpty();
private:
    LinkStackNode<T>* tos;
};

// ��Ա������ʵ��
template<typename T>
LinkStack<T>::LinkStack() : tos(nullptr) { }  // Ĭ�Ϲ��캯��
template<typename T>
LinkStack<T>::LinkStack(T value) : tos(new LinkStackNode<T>(value)) { } // ����һ��T���Ͳ����Ĺ��캯��

template<typename T>
LinkStack<T>& LinkStack<T>::Push(T value)
{
    LinkStackNode<T>* add = new LinkStackNode<T>(value);
    add->GetLink() = tos;   // ��ǰ��ջ��Ԫ�أ���Ϊ�¼�Ԫ�صĺ�̽�㡣
    tos = add; //  ����ջ��Ԫ�� ��ʹ�ռӽ�����Ԫ�س�Ϊջ��Ԫ��
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
    assert(tos != nullptr); // �����ж���ʽջ�ǿ�
    LinkStackNode<T>* old = tos;    // Ȼ����ʱ���ջ��Ԫ�ص�ָ��
    tos = tos->GetLink();   // ɾ��ջ��Ԫ��
    T data = old->GetData();    // �����ʱջ��Ԫ�صİ��������ݣ�������Ϊ����ķ���ֵ��
    delete old; // ɾ����ǰջ��Ԫ��
    return data;  // ���ؾɵ�ջ��Ԫ���ڰ���������
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
