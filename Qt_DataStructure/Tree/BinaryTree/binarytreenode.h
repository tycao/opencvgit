/*
 * �������ڵ��������ʵ�ִ���
 * 2017-10-8
*/
#pragma once

#include <iostream>

using namespace std;


template<typename T>
class BinaryTreeNode
{
public:
    BinaryTreeNode();   // Ĭ�Ϲ��캯��
    BinaryTreeNode(const T& data,
                   BinaryTreeNode<T>* leftChild = nullptr, BinaryTreeNode<T>* rightChild = nullptr);    // ���캯��
    const T& GetData() const;    // ��ȡ��ǰ�ڵ������
    BinaryTreeNode<T>* GetLeftChild();  // ���ظýڵ������ָ��
    BinaryTreeNode<T>* GetRightChild(); // ���ظýڵ���Һ���ָ��
    void SetData(const T& data); // ���øýڵ������
    void SetLeftChild(BinaryTreeNode<T>* leftChild);    // ���øýڵ������ָ��
    void SetRightChild(BinaryTreeNode<T>* rightChild);    // ���øýڵ���Һ���ָ��

private:
    T m_data;   // �洢�ýڵ������
    BinaryTreeNode<T>* m_leftNode;  // �洢�ýڵ������ָ��
    BinaryTreeNode<T>* m_rightNode; // �洢�ýڵ���Һ���ָ��
};

// +++++++++++++++++++Member function+++++++++++++++++++++++++
// Ĭ�Ϲ��캯��
template<typename T>
BinaryTreeNode<T>::BinaryTreeNode() : m_leftNode(nullptr), m_rightNode(nullptr) { }
// ���캯��
template<typename T>
BinaryTreeNode<T>::BinaryTreeNode
(
        const T& data,
        BinaryTreeNode<T>* leftChild,
        BinaryTreeNode<T>* rightChild
)
    : m_leftNode(leftChild),
      m_rightNode(rightChild),
      m_data(data)
{

}
// ��ȡ��ǰ�ڵ������
template<typename T>
const T& BinaryTreeNode<T>::GetData() const
{
    return this->m_data;
}
// ���ظýڵ������ָ��
template<typename T>
BinaryTreeNode<T>* BinaryTreeNode<T>::GetLeftChild()
{
    return this->m_leftNode;
}
// ���ظýڵ���Һ���ָ��
template<typename T>
BinaryTreeNode<T>* BinaryTreeNode<T>::GetRightChild()
{
    return this->m_rightNode;
}
// ���øýڵ������
template<typename T>
void BinaryTreeNode<T>::SetData(const T& data)
{
    this->m_data = data;
}
template<typename T>
void BinaryTreeNode<T>::SetLeftChild(BinaryTreeNode<T>* leftChild)    // ���øýڵ������ָ��
{
    this->m_leftNode = leftChild;
}
template<typename T>
void BinaryTreeNode<T>::SetRightChild(BinaryTreeNode<T>* rightChild)    // ���øýڵ���Һ���ָ��
{
    this->m_rightNode = rightChild;
}

