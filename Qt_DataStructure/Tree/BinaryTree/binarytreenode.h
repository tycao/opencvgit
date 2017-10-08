/*
 * 二叉树节点类的完整实现代码
 * 2017-10-8
*/
#pragma once

#include <iostream>

using namespace std;


template<typename T>
class BinaryTreeNode
{
public:
    BinaryTreeNode();   // 默认构造函数
    BinaryTreeNode(const T& data,
                   BinaryTreeNode<T>* leftChild = nullptr, BinaryTreeNode<T>* rightChild = nullptr);    // 构造函数
    const T& GetData() const;    // 获取当前节点的数据
    BinaryTreeNode<T>* GetLeftChild();  // 返回该节点的左孩子指针
    BinaryTreeNode<T>* GetRightChild(); // 返回该节点的右孩子指针
    void SetData(const T& data); // 设置该节点的数据
    void SetLeftChild(BinaryTreeNode<T>* leftChild);    // 设置该节点的左孩子指针
    void SetRightChild(BinaryTreeNode<T>* rightChild);    // 设置该节点的右孩子指针

private:
    T m_data;   // 存储该节点的数据
    BinaryTreeNode<T>* m_leftNode;  // 存储该节点的左孩子指针
    BinaryTreeNode<T>* m_rightNode; // 存储该节点的右孩子指针
};

// +++++++++++++++++++Member function+++++++++++++++++++++++++
// 默认构造函数
template<typename T>
BinaryTreeNode<T>::BinaryTreeNode() : m_leftNode(nullptr), m_rightNode(nullptr) { }
// 构造函数
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
// 获取当前节点的数据
template<typename T>
const T& BinaryTreeNode<T>::GetData() const
{
    return this->m_data;
}
// 返回该节点的左孩子指针
template<typename T>
BinaryTreeNode<T>* BinaryTreeNode<T>::GetLeftChild()
{
    return this->m_leftNode;
}
// 返回该节点的右孩子指针
template<typename T>
BinaryTreeNode<T>* BinaryTreeNode<T>::GetRightChild()
{
    return this->m_rightNode;
}
// 设置该节点的数据
template<typename T>
void BinaryTreeNode<T>::SetData(const T& data)
{
    this->m_data = data;
}
template<typename T>
void BinaryTreeNode<T>::SetLeftChild(BinaryTreeNode<T>* leftChild)    // 设置该节点的左孩子指针
{
    this->m_leftNode = leftChild;
}
template<typename T>
void BinaryTreeNode<T>::SetRightChild(BinaryTreeNode<T>* rightChild)    // 设置该节点的右孩子指针
{
    this->m_rightNode = rightChild;
}

