#pragma once

#include <iostream>

using namespace std;

// 先声明 AVL（平衡二叉搜索树）树类
template<typename T> class AvlTree;

template<typename T>
class AvlNode
{
    friend class AvlTree<T>;
public:
    // 构造函数
    AvlNode();
    AvlNode(const T& e, AvlNode<T>* lt = nullptr, AvlNode<T>* rt = nullptr);

    int GetBalance() const; // 获取平衡因子
    AvlNode<T>* GetLeftChild() const;   // 获取左孩子
    AvlNode<T>* GetRightChild() const;  // 获取右孩子
    T GetData() const;    // 获取关键码
private:
    T data; // 关键码
    AvlNode* leftChild; // 左孩子
    AvlNode* rightChild;    // 右孩子
    int balance;    // 平衡因子
};

// 成员函数的实现
template<typename T>
AvlNode<T>::AvlNode()  // 构造函数
    : leftChild(nullptr), rightChild(nullptr), balance(0)   // 构造函数成员初始化列表
{

}

template<typename T>
AvlNode<T>::AvlNode(const T& e, AvlNode<T>* lt = nullptr, AvlNode<T>* rt = nullptr) // 带有形式参数的构造函数
    : leftChild(lt), rightChild(rt), balance(0), data(e)
{

}

template<typename T>
int AvlNode<T>::GetBalance() const // 获取平衡因子
{
    return this->balance;
}

template<typename T>
AvlNode<T>* AvlNode<T>::GetLeftChild() const   // 获取左孩子
{
    return this->leftChild;
}

template<typename T>
AvlNode<T>* AvlNode<T>::GetRightChild() const  // 获取右孩子
{
    return this->rightChild;
}

template<typename T>
T AvlNode<T>::GetData() const    // 获取关键码
{
    return this->data;
}
