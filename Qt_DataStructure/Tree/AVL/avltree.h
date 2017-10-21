#pragma once

#include "avlnode.h"

template<typename T>
class AvlTree
{
public:
    // 构造函数
    AvlTree();
    AvlTree(T x);
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
    bool success;
    // 递归函数的“基本条件”
    if (rt == nullptr)
    {
        rt = new AvlNode<T>(x);
        success = rt != nullptr ? true : false;
        if (success)
            taller = true;
    }
    // 若x的值小于rt的关键码
    else if (x < rt->data)
    {
        // Insert 的递归调用，从rt的左子数寻找合适的位置插入
        success = Insert(rt->rightChild, x, taller);
        if (taller) // 若插入后 使得rt的有高度增加
        {
            switch (rt->balance) {
            case -1:
                rt->balance = 0;
                taller = false;
                break;
            case 0:
                rt->balance = 1;
                break;
            case 1:
                RightBalanceAfterInsert(rt, taller);
                break;
            }
        }
    }
    return success;
}
// 删除值为x的结点，实现方式采用递归
template<typename T>
bool AvlTree<T>::Remove(AvlNode<T>*& rt, T x, bool& shorter)
{
    bool success = false;
    if (rt == nullptr) return false;
    // 若rt就是要删除的结点
    if (x == rt->data)
    {
        if (rt->leftChild != nullptr && rt->rightChild != nullptr)
        {
            // 寻找rt的中序遍历的前驱结点，用r表示
            AvlNode<T>* r = rt->leftChild;
            while (r->rightChild != nullptr)
            {
                r = r->rightChild;
            }
            // 交换rt和r的值
            T temp = rt->data;
            rt->data = r->data;
            r->data = temp;
            // 递归函数、从rt的左子树中删除关键码为x的节点
            success = Remove(rt->leftChild, x, shorter);
            if (shorter)
            {
                switch (rt->balance) {
                case -1:
                    rt->balance = 0;
                    break;
                case 0:
                    rt->balance = 1;
                    shorter = 0;
                    break;
                case 1:
                    RightBalanceAfterDelete(rt, shorter);
                    break;
                }
            }
        }
        else
        {
            // rt最多只有一个子女，这是递归的出口
            AvlNode<T>* p = rt;
            rt = rt->leftChild != nullptr ? rt->leftChild : rt->rightChild;
            delete p;
            success = true;
            shorter = true;
        }
    }
    else if (x < rt->data)
    {
        // 递归调用函数、从rt的左子树中删除关键码为x的节点
        success = Remove(rt->leftChild, x, shorter);
        if (shorter)
        {   // 若删除后引起rt的左高度减少
            switch (rt->balance) {
            case -1:
                rt->balance = 0;
                break;
            case 0:
                rt->balance = 1;
                shorter = 0;
                break;
            case 1:
                RightBalanceAfterDelete(rt, shorter);
                break;
            }
        }
    }
    else if (x > rt->data)
    {
        // 递归函数调用、从rt的右子树中删除关键码为x的结点
        success = Remove(rt->rightChild, x, shorter);
        if (shorter)
        {
            switch (rt->balance) {
            case -1:
                LeftBalanceAfterDelete(rt, shorter);
                break;
            case 0:
                rt->balance = -1;
                shorter = 0;
                break;
            case 1:
                rt->balance = 0;
                break;
            }
        }
    }
    return success;
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
void AvlTree<T>::RotateRight(AvlNode<T>*& node) // 右旋函数
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
        sRoot->balance = leftsub->balance = 0;
        RotateRight(sRoot);
        break;
    case 0:
        sRoot->balance = 0;
        leftsub->balance = -1;
        RotateRight(sRoot);
        break;
    case -1:
        rightsub = leftsub->rightChild;
        switch (rightsub->balance) {
        case -1:
            sRoot->balance = 0;
            leftsub->balance = 1;
            break;
        case 0:
            sRoot->balance = leftsub->balance = 0;
            break;
        case 1:
            sRoot->balance = -1;
            leftsub->balance = 0;
            break;
        }
    rightsub->balance = 0;
    RotateLeft(leftsub);
    RotateRight(sRoot);
    shorter = false;
        break;
    }
}

// 共有成员函数的实现
template<typename T>
AvlTree<T>::AvlTree()  // 构造函数
    : root(nullptr)
{

}
template<typename T>
AvlNode<T>* AvlTree<T>::GetRoot() const    // 获取根节点
{
    return this->root;
}
template<typename T>
bool AvlTree<T>::Insert(T x)
{
    bool taller = false;
    return Insert(root, x, taller);
}
template<typename T>
bool AvlTree<T>::Remove(T x)
{
    bool shorter = false;
    return Remove(root, x, shorter);
}
template<typename T>
void AvlTree<T>::DisplayTree(AvlNode<T>* t, int layer) const
{
    if (t == nullptr) return;
    if (t->rightChild)
        DisplayTree(t->rightChild, layer + 1);
    for (int i = 0; i != layer; ++i)
        cout << "   ";
    cout << t->data << "\n";
    if (t->leftChild)
        DisplayTree(t->leftChild, layer + 1);
}

template<typename T>
AvlTree<T>::AvlTree(T x)
    : root(new AvlNode<T>(x))
{

}
