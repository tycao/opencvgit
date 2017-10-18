#pragma once

#include "avlnode.h"

template<typename T>
class AvlTree
{
public:
    // 构造函数
    AvlTree();
    AvlNode<T>* GetRoot() const;    // 获取根节点
    bool Insert(T x);
    bool Remove(T x);
    void DisplayTree(AvlNode<T>* t, int layer) const;
private:
    AvlNode<T>* root;
    bool Insert(AvlNode<T>*& rt, T x, bool& taller);
    bool Remove(AvlNode<T>*& rt, T x, bool& shorter);
    void RotateLeft(AvlNode<T>*& node); // 左旋函数
    void RotateRight(AvlNode<T>*& node); // 右旋函数
    void RightBalanceAfterInsert(AvlNode<T>*& sRoot, bool& taller);
    void LeftBalanceAfterInsert(AvlNode<T>*& sRoot, bool& taller);
    void RightBalanceAfterDelete(AvlNode<T>*& sRoot, bool& shorter);
    void LeftBalanceAfterDelete(AvlNode<T>*& sRoot, bool& shorter);
};

// 私有成员函数的实现
template<typename T>
bool AvlTree<T>::Insert(AvlNode<T>*& rt, T x, bool& taller)
{

}
template<typename T>
bool AvlTree<T>::Remove(AvlNode<T>*& rt, T x, bool& shorter)
{

}
template<typename T>
void AvlTree<T>::RotateLeft(AvlNode<T>*& node) // 左旋函数
{
    if (node == nullptr || node->rightChild == nullptr)
        return;
    AvlNode<T>* tmpNode = new AvlNode<T>(node->data);
    if (tmpNode == nullptr)
        return;
    tmpNode->leftChild = node->leftChild;
    node->leftChild = tmpNode;
    tmpNode->rightChild = node->rightChild->leftChild;
    AvlNode<T>* toDelete = node->rightChild;
    node->data = toDelete->data;
    node->rightChild = toDelete->rightChild;
    delete toDelete;
}
template<typename T>
bool AvlTree<T>::RotateRight(AvlNode<T>*& node) // 右旋函数
{
    if (node == nullptr || node->leftChild == nullptr) return;
    AvlNode<T>* tmpNode = new AvlNode<T>(node->data);
    if (tmpNode == nullptr) return;
    tmpNode->rightChild = node->rightChild;
    node->rightChild = tmpNode;
    tmpNode->leftChild = node->leftChild->rightChild;
    AvlNode<T>* toDelete = node->leftChild;
    node->data = toDelete->data;
    node->leftChild = toDelete->leftChild;
    delete toDelete;
}
template<typename T>
void AvlTree<T>::RightBalanceAfterInsert(AvlNode<T>*& sRoot, bool& taller)
{
    if (sRoot == nullptr || sRoot->rightChild == nullptr) return;
    AvlNode<T>* rightsub = sRoot->rightChild, *leftsub;
    switch (rightsub->balance) {
    case 1:

        break;
    case 0:

        break;
    case -1:

    default:
        break;
    }
}
template<typename T>
void AvlTree<T>::LeftBalanceAfterInsert(AvlNode<T>*& sRoot, bool& taller)
{

}
template<typename T>
void AvlTree<T>::RightBalanceAfterDelete(AvlNode<T>*& sRoot, bool& shorter)
{

}
template<typename T>
void AvlTree<T>::LeftBalanceAfterDelete(AvlNode<T>*& sRoot, bool& shorter)
{

}

// 共有成员函数的实现
template<typename T>
AvlTree<T>::AvlTree()  // 构造函数
{

}
template<typename T>
AvlNode<T>* AvlTree<T>::GetRoot() const;    // 获取根节点
template<typename T>
bool AvlTree<T>::Insert(T x)
{

}
template<typename T>
bool AvlTree<T>::Remove(T x)
{

}
template<typename T>
void AvlTree<T>::DisplayTree(AvlNode<T>* t, int layer) const
{

}
