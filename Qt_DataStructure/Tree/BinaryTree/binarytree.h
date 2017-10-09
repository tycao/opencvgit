/*
 * 二叉树类的完整实现代码
 * 2017-10-8
 *
*/
#pragma once

#include <queue>
#include <stack>
#include "binarytreenode.h"

template<typename T>
class BinaryTree
{
public:
    BinaryTree();   // 默认构造函数
    BinaryTree(T data);   // 带有一个参数的构造函数
    virtual ~BinaryTree();  // （虚函数）析构函数

    bool IsEmpty() const; // 判断树是否为空树
    bool IsLeftChild(BinaryTreeNode<T>* p) const;   // 判断一个节点是唯恐左孩子节点
    bool IsRightChild(BinaryTreeNode<T>* p) const;    // 判断一个节点是否为右孩子节点
    BinaryTreeNode<T>* GetRoot(); // 取得整棵树的根节点
    BinaryTreeNode<T>* GetParent(BinaryTreeNode<T>* p); // 取得一个节点的父节点指针
    BinaryTreeNode<T>* LeftChild(BinaryTreeNode<T>* p); // 取得一个节点的左子树根节点
    BinaryTreeNode<T>* RightChild(BinaryTreeNode<T>* p);  // 获得一个节点的右子树根节点
    BinaryTreeNode<T>* LeftSibling(BinaryTreeNode<T>* leftChild); // 取得一个节点的左兄弟指针
    BinaryTreeNode<T>* RightSibling(BinaryTreeNode<T>* rightChild); // 取得一个节点的右兄弟指针
    T GetData(BinaryTreeNode<T>* p) const; // 返回一个节点的数据
    void Assign(BinaryTreeNode<T>* p, const T& data);    // 设置一个节点的数据
    void InsertRightChild(BinaryTreeNode<T>* p, const T& data); // 插入右孩子到当前节点下
    void InsertLeftChild(BinaryTreeNode<T>* p, const T& data); // 插入左孩子到当前节点下
    void DeleteLeftChild(BinaryTreeNode<T>* p);     // 删除当前节点的左孩子
    void DeleteRightChild(BinaryTreeNode<T>* p);    // 删除当前节点的右孩子

    virtual void PreOrderTraverse(BinaryTreeNode<T>* root) const;    // 前序遍历整棵树
    virtual void InOrderTraverse(BinaryTreeNode<T>* root) const;   // 中序遍历整棵树
    virtual void PostOrderTraverse(BinaryTreeNode<T>* root) const; // 后序遍历整棵树
    virtual void LevelOrderTraverse(BinaryTreeNode<T>* root) const;    // 按层遍历整棵树
private:
    BinaryTreeNode<T>* m_root;  //  私有数据成员：树的根节点
protected:
    BinaryTreeNode<T>* Parent(BinaryTreeNode<T>* root, BinaryTreeNode<T>* p);  //
    void Destroy(BinaryTreeNode<T>* p);
};

template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::Parent(BinaryTreeNode<T>* root, BinaryTreeNode<T>* p)  //
{
    BinaryTreeNode<T>* q;
    if (nullptr == root)
        return nullptr;
    if ((p == root->GetLeftChild()) || (p == root->GetRightChild()))
        return root;
    if (nullptr != (q = Parent(root->GetLeftChild(), p)))
        return q;
    else
        return Parent(root->GetRightChild(), p);
}
template<typename T>
void BinaryTree<T>::Destroy(BinaryTreeNode<T>* p)
{
    if (nullptr != p)
    {
        Destroy(p->GetLeftChild());
        Destroy(p->GetRightChild());
        delete p;
    }
}

template<typename T>
BinaryTree<T>::BinaryTree()  : m_root(nullptr) { } // 默认构造函数

template<typename T>
BinaryTree<T>::BinaryTree(T data) : m_root(new BinaryTreeNode<T>(data)) { }  // 带有一个参数的构造函数

template<typename T>
BinaryTree<T>::~BinaryTree(void)  // （虚函数）析构函数
{
    Destroy(m_root);
    m_root = nullptr;
}
template<typename T>
bool BinaryTree<T>::IsEmpty() const // 判断树是否为空树
{
    return m_root == nullptr ? true : false;
}
template<typename T>
bool BinaryTree<T>::IsLeftChild(BinaryTreeNode<T>* p) const   // 判断一个节点是否为左孩子节点
{
    if (p == GetParent(p)->GetLeftChild())
        return true;
    else
        return false;
}
template<typename T>
bool BinaryTree<T>::IsRightChild(BinaryTreeNode<T>* p) const   // 判断一个节点是否为右孩子节点
{
    return p == GetParent(p)->GetRightChild() ? true : false;
}
template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::GetRoot() // 取得整棵树的根节点
{
    return m_root;
}
template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::GetParent(BinaryTreeNode<T>* p) // 取得一个节点的父节点指针
{
    return this->Parent(m_root, p);
}
template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::LeftChild(BinaryTreeNode<T>* p) // 取得一个节点的左子树根节点
{
    return nullptr == p ? nullptr : p->GetLeftChild();
}
template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::RightChild(BinaryTreeNode<T>* p)  // 获得一个节点的右子树根节点
{
    return nullptr == p ? nullptr : p->GetRightChild();
}
template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::LeftSibling(BinaryTreeNode<T>* leftChild) // 取得一个节点的左兄弟指针
{
    BinaryTreeNode<T>* q;
    q = Parent(m_root, leftChild);
    if ( nullptr == q || leftChild == q->GetLeftChild() )
        return nullptr;
    else
        return q->GetLeftChild();
}
template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::RightSibling(BinaryTreeNode<T>* rightChild) // 取得一个节点的右兄弟指针
{
    BinaryTreeNode<T>* q;
    q = Parent(m_root, rightChild);
    if ( nullptr == q || rightChild == q->GetRightChild())
        return nullptr;
    else
        return q->GetRightChild();
}
template<typename T>
T BinaryTree<T>::GetData(BinaryTreeNode<T>* p) const // 返回一个节点的数据
{
    return p->GetData();
}
template<typename T>
void BinaryTree<T>::Assign(BinaryTreeNode<T>* p, const T& data)    // 设置一个节点的数据
{
    p->SetData(data);
}
template<typename T>
void BinaryTree<T>::InsertRightChild(BinaryTreeNode<T>* p, const T& data)  // 插入右孩子到当前节点下
{
    BinaryTreeNode<T>* q(new BinaryTreeNode<T>(data));
    q->SetRightChild(p->GetRightChild());
    p->SetRightChild(q);
}
template<typename T>
void BinaryTree<T>::InsertLeftChild(BinaryTreeNode<T>* p, const T& data)  // 插入左孩子到当前节点下
{
    BinaryTreeNode<T>* q = new BinaryTreeNode<T>(data);
    q->SetLeftChild(p->GetLeftChild());
    p->SetLeftChild(q);
}
template<typename T>
void BinaryTree<T>::DeleteLeftChild(BinaryTreeNode<T>* p)     // 删除当前节点的左孩子
{
    Destroy(p->GetLeftChild());
}
template<typename T>
void BinaryTree<T>::DeleteRightChild(BinaryTreeNode<T>* p)   // 删除当前节点的右孩子
{
    Destroy(p->GetRightChild());
}
template<typename T>
void BinaryTree<T>::PreOrderTraverse(BinaryTreeNode<T>* root)  const  // 前序遍历整棵树（先根遍历）
{
    // 这是一种递归实现方法。
    if (nullptr != root)
    {
        cout << root->GetData();
        PreOrderTraverse(root->GetLeftChild());
        PreOrderTraverse(root->GetRightChild());
    }

    /*
     // 另外一种是使用栈结构来完成二叉树的前序遍历

    std::stack< BinaryTreeNode<T>* > s;
    BinaryTreeNode<T>* p = root;
    while (!s.empty() || nullptr != p)
    {
        while (p)
        {
            s.push(p);
            cout << p->GetData();
            p = p->GetLeftChild();
        }
        p = s.top();
        s.pop();
        p = p->GetRightChild();
    }
    */

}

template<typename T>
void BinaryTree<T>::InOrderTraverse(BinaryTreeNode<T>* root) const   // 中序遍历整棵树（中根遍历）
{
    // 这是一种递归实现的方法
    if (nullptr != root)
    {
        InOrderTraverse(root->GetLeftChild());
        cout << root->GetData();
        InOrderTraverse(root->GetRightChild());
    }
    /*
    // 这是一种使用栈结构来完成的二叉树的中根遍历
    std::stack< BinaryTreeNode<T>* > s;
    BinaryTreeNode<T>* p = root;
    while (!s.empty() || nullptr != p)
    {
        while (p)
        {
            s.push(p);
            p = p->GetLeftChild();
        }
        p = s.top();
        s.pop();
        cout << p->GetData();
        p = p->GetRightChild();
    }
    */
}
template<typename T>
void BinaryTree<T>::PostOrderTraverse(BinaryTreeNode<T>* root) const // 后序遍历整棵树（后根遍历）
{
    // 这是一种递归实现的方法
    if (nullptr != root)
    {
        PostOrderTraverse(root->GetLeftChild());
        PostOrderTraverse(root->GetRightChild());
        cout << root->GetData();
    }

    // 这是一种使用栈结构实现的二叉树的后序遍历
}
template<typename T>
void BinaryTree<T>::LevelOrderTraverse(BinaryTreeNode<T>* root) const    // 按层遍历整棵树
{
    queue< BinaryTreeNode<T>* > myQueue;
    if (nullptr != root)
        myQueue.push(root);
    while (!myQueue.empty())
    {
        root = myQueue.front();
        myQueue.pop();
        cout << root->GetData();
        if (root->GetLeftChild())
            myQueue.push(root->GetLeftChild());
        if (root->GetRightChild())
            myQueue.push(root->GetRightChild());
    }
}
