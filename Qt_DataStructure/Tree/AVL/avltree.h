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
        sRoot->balance = rightsub->balance = 0;
        RotateLeft(sRoot);
        taller = false;
        break;
    case 0:
        cout << "平衡二叉搜索树已经平衡化。" << endl;
        break;
    case -1:
        leftsub = rightsub->leftChild;
        switch (leftsub->balance) {
        case 1:
            sRoot->balance = -1;
            rightsub->balance = 0;
            break;
        case 0:
            sRoot->balance = rightsub->balance = 0;
            break;
        case -1:
            sRoot->balance = 0;
            rightsub->balance = 1;
            break;
        }
        leftsub->balance = 0;
        RotateRight(rightsub);
        RotateLeft(sRoot);
        taller = false;
        break;
    }
}
template<typename T>
void AvlTree<T>::LeftBalanceAfterInsert(AvlNode<T>*& sRoot, bool& taller)
{
    AvlNode<T>* leftsub = sRoot->leftChild;
    AvlNode<T> *rightsub;
    switch (leftsub->balance) {
    case -1:
        sRoot->balance = leftsub->balance = 0;
        RotateRight(sRoot);
        taller = false;
        break;
    case 0:
        cout << "平衡二叉搜索树已经平衡化。" << endl;
    case 1:
        rightsub = leftsub->rightChild;
        switch (rightsub->balance) {
        case -1:
            sRoot->balance = 1;
            leftsub->balance = 0;
            break;
        case 0:
            sRoot->balance = leftsub->balance = 0;
            break;
        case 1:
            sRoot->balance = 0;
            leftsub->balance = -1;
            break;
        }
        rightsub->balance = 0;
        RotateLeft(leftsub);
        RotateRight(sRoot);
        taller = false;
        break;
    }
}
// 如果删除节点后，rt的左高度减少，则调用此函数进行平衡化
template<typename T>
void AvlTree<T>::RightBalanceAfterDelete(AvlNode<T>*& sRoot, bool& shorter)
{
    AvlNode<T>* rightsub = sRoot->rightChild, *leftsub;
    switch (rightsub->balance) {
    case 1:
        sRoot->balance = rightsub->balance = 0;
        RotateLeft(sRoot);
        break;
    case 0:
        sRoot->balance = 0;
        rightsub->balance = -1;
        RotateLeft(sRoot);
        break;
    case -1:
        leftsub = rightsub->leftChild;
        switch (leftsub->balance) {
        case -1:
            sRoot->balance = 0;
            rightsub->balance = 1;
            break;
        case 0:
            sRoot->balance = rightsub->balance = 0;
            break;
        case 1:
            sRoot->balance = -1;
            rightsub->balance = 0;
            break;
        }
        leftsub->balance = 0;
        RotateRight(rightsub);
        RotateLeft(sRoot);
        shorter = false;
        break;
    }
}
//  如果删除节点后，rt的右高度减少，则调用此函数进行平衡化
template<typename T>
void AvlTree<T>::LeftBalanceAfterDelete(AvlNode<T>*& sRoot, bool& shorter)
{
    AvlNode<T>* leftsub = sRoot->leftChild, *rightsub;
    switch (leftsub->balance) {
    case 1:

        break;
    default:
        break;
    }
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
