#pragma once

#include <iostream>

using namespace std;

// ������ AVL��ƽ�����������������
template<typename T> class AvlTree;

template<typename T>
class AvlNode
{
    friend class AvlTree<T>;
public:
    // ���캯��
    AvlNode();
    AvlNode(const T& e, AvlNode<T>* lt = nullptr, AvlNode<T>* rt = nullptr);

    int GetBalance() const; // ��ȡƽ������
    AvlNode<T>* GetLeftChild() const;   // ��ȡ����
    AvlNode<T>* GetRightChild() const;  // ��ȡ�Һ���
    T GetData() const;    // ��ȡ�ؼ���
private:
    T data; // �ؼ���
    AvlNode* leftChild; // ����
    AvlNode* rightChild;    // �Һ���
    int balance;    // ƽ������
};

// ��Ա������ʵ��
template<typename T>
AvlNode<T>::AvlNode()  // ���캯��
    : leftChild(nullptr), rightChild(nullptr), balance(0)   // ���캯����Ա��ʼ���б�
{

}

template<typename T>
AvlNode<T>::AvlNode(const T& e, AvlNode<T>* lt = nullptr, AvlNode<T>* rt = nullptr) // ������ʽ�����Ĺ��캯��
    : leftChild(lt), rightChild(rt), balance(0), data(e)
{

}

template<typename T>
int AvlNode<T>::GetBalance() const // ��ȡƽ������
{
    return this->balance;
}

template<typename T>
AvlNode<T>* AvlNode<T>::GetLeftChild() const   // ��ȡ����
{
    return this->leftChild;
}

template<typename T>
AvlNode<T>* AvlNode<T>::GetRightChild() const  // ��ȡ�Һ���
{
    return this->rightChild;
}

template<typename T>
T AvlNode<T>::GetData() const    // ��ȡ�ؼ���
{
    return this->data;
}
