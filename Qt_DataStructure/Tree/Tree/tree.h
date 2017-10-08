#pragma once

#include "treenode.h"

template<typename T>
class Tree
{
private:
    TreeNode<T>* root;
    TreeNode<T>* parent;
    int getParent(TreeNode<T>* root, TreeNode<T>* current);
public:
    Tree(); // 默认构造函数
    Tree(TreeNode<T>* rt);  // 构造函数，生成树的结构
    ~Tree();    // 析构函数
    TreeNode<T>* getRoot();  // 返回树的根节点，若为空树，则返回nullptr
    TreeNode<T>* Parent(TreeNode<T>* current);  // 返回节点current的父节点，若current为根节点，则返回nullptr
    TreeNode<T>* getFirstChild(TreeNode<T>* t); // 返回节点t的第一个子节点，若无 则返回nullptr
    TreeNode<T>* getNextSibling(TreeNode<T>* t);  // 返回节点t的下一个兄弟节点，若无 则返回nullptr
    void insertChild(TreeNode<T>* t, TreeNode<T>* n);   // 在节点t下 插入一个子节点n
    void deleteSubTree(TreeNode<T>* t);   // 删除以t为根节点的子树
    bool isEmpty(); // 判断是否为空树
};

// 默认构造函数
template<typename T>
Tree<T>::Tree()
    : root(nullptr), parent(nullptr) { }

// 构造函数，生成树的结构
template<typename T>
Tree<T>::Tree(TreeNode<T>* rt)
    : root(rt), parent(nullptr) { }

// 析构函数
template<typename T>
Tree<T>::~Tree() { }

// 返回树的根节点，若为空树，则返回nullptr
template<typename T>
TreeNode<T>* Tree<T>::getRoot()
{
    return root;
}

// 返回节点current的父节点，若current为根节点，则返回nullptr
template<typename T>
TreeNode<T>* Tree<T>::Parent(TreeNode<T>* current)
{
    //TreeNode<T>* pointer = current, *t;
    if (current == nullptr || current == root)
    {
        current = nullptr;
        return 0;
    }
   // t = root;
   // getParent(t, pointer);
    getParent(root, current);
    return parent;
}

// 返回节点t的第一个子节点，若无 则返回nullptr
template<typename T>
TreeNode<T>* Tree<T>::getFirstChild(TreeNode<T>* t)
{
    return t->getLeftChild();
}

// 返回节点t的下一个兄弟节点，若无 则返回nullptr
template<typename T>
TreeNode<T>* Tree<T>::getNextSibling(TreeNode<T>* t)
{
    return t->getRightSibling();
}

// 在节点t下 插入一个子节点n
template<typename T>
void Tree<T>::insertChild(TreeNode<T>* t, TreeNode<T>* n)
{
    if (t->getLeftChild() == nullptr)
        t->setLeftChild(n);
    else
    {
        TreeNode<T>* p = t->getLeftChild();
        while (p->getRightSibling() != nullptr)
            p = p->getRightSibling();
        p->setRightSibling(n);
    }
}

// 删除以t为根节点的子树
template<typename T>
void Tree<T>::deleteSubTree(TreeNode<T>* t)
{
    TreeNode<T>* temp = t;
    while (temp->getLeftChild() != nullptr)
        temp = temp->getLeftChild();
    if (temp->getRightSibling() != nullptr)
        deleteSubTree(temp->getRightSibling());
    if (temp->getLeftChild() == nullptr)
        delete temp;
}

// 判断是否为空树
template<typename T>
bool Tree<T>::isEmpty()
{
    if (root == nullptr)
        return true;
    else
        return false;
}

// private member function for Parent() (a public member function)
template<typename T>
int Tree<T>::getParent(TreeNode<T>* root, TreeNode<T>* current)
{
    TreeNode<T>* q = root->getLeftChild();

    while (q != nullptr && q != current)
    {
        if (getParent(q, current) != 0)
            return 2;
        q = q->getRightSibling();
    }
    if (q != nullptr && q == current)
    {
        parent = root;
        return 1;
    }
    else return 0;
}
