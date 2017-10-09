/*
 * �������������ʵ�ִ���
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
    BinaryTree();   // Ĭ�Ϲ��캯��
    BinaryTree(T data);   // ����һ�������Ĺ��캯��
    virtual ~BinaryTree();  // ���麯������������

    bool IsEmpty() const; // �ж����Ƿ�Ϊ����
    bool IsLeftChild(BinaryTreeNode<T>* p) const;   // �ж�һ���ڵ���Ψ�����ӽڵ�
    bool IsRightChild(BinaryTreeNode<T>* p) const;    // �ж�һ���ڵ��Ƿ�Ϊ�Һ��ӽڵ�
    BinaryTreeNode<T>* GetRoot(); // ȡ���������ĸ��ڵ�
    BinaryTreeNode<T>* GetParent(BinaryTreeNode<T>* p); // ȡ��һ���ڵ�ĸ��ڵ�ָ��
    BinaryTreeNode<T>* LeftChild(BinaryTreeNode<T>* p); // ȡ��һ���ڵ�����������ڵ�
    BinaryTreeNode<T>* RightChild(BinaryTreeNode<T>* p);  // ���һ���ڵ�����������ڵ�
    BinaryTreeNode<T>* LeftSibling(BinaryTreeNode<T>* leftChild); // ȡ��һ���ڵ�����ֵ�ָ��
    BinaryTreeNode<T>* RightSibling(BinaryTreeNode<T>* rightChild); // ȡ��һ���ڵ�����ֵ�ָ��
    T GetData(BinaryTreeNode<T>* p) const; // ����һ���ڵ������
    void Assign(BinaryTreeNode<T>* p, const T& data);    // ����һ���ڵ������
    void InsertRightChild(BinaryTreeNode<T>* p, const T& data); // �����Һ��ӵ���ǰ�ڵ���
    void InsertLeftChild(BinaryTreeNode<T>* p, const T& data); // �������ӵ���ǰ�ڵ���
    void DeleteLeftChild(BinaryTreeNode<T>* p);     // ɾ����ǰ�ڵ������
    void DeleteRightChild(BinaryTreeNode<T>* p);    // ɾ����ǰ�ڵ���Һ���

    virtual void PreOrderTraverse(BinaryTreeNode<T>* root) const;    // ǰ�����������
    virtual void InOrderTraverse(BinaryTreeNode<T>* root) const;   // �������������
    virtual void PostOrderTraverse(BinaryTreeNode<T>* root) const; // �������������
    virtual void LevelOrderTraverse(BinaryTreeNode<T>* root) const;    // �������������
private:
    BinaryTreeNode<T>* m_root;  //  ˽�����ݳ�Ա�����ĸ��ڵ�
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
BinaryTree<T>::BinaryTree()  : m_root(nullptr) { } // Ĭ�Ϲ��캯��

template<typename T>
BinaryTree<T>::BinaryTree(T data) : m_root(new BinaryTreeNode<T>(data)) { }  // ����һ�������Ĺ��캯��

template<typename T>
BinaryTree<T>::~BinaryTree(void)  // ���麯������������
{
    Destroy(m_root);
    m_root = nullptr;
}
template<typename T>
bool BinaryTree<T>::IsEmpty() const // �ж����Ƿ�Ϊ����
{
    return m_root == nullptr ? true : false;
}
template<typename T>
bool BinaryTree<T>::IsLeftChild(BinaryTreeNode<T>* p) const   // �ж�һ���ڵ��Ƿ�Ϊ���ӽڵ�
{
    if (p == GetParent(p)->GetLeftChild())
        return true;
    else
        return false;
}
template<typename T>
bool BinaryTree<T>::IsRightChild(BinaryTreeNode<T>* p) const   // �ж�һ���ڵ��Ƿ�Ϊ�Һ��ӽڵ�
{
    return p == GetParent(p)->GetRightChild() ? true : false;
}
template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::GetRoot() // ȡ���������ĸ��ڵ�
{
    return m_root;
}
template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::GetParent(BinaryTreeNode<T>* p) // ȡ��һ���ڵ�ĸ��ڵ�ָ��
{
    return this->Parent(m_root, p);
}
template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::LeftChild(BinaryTreeNode<T>* p) // ȡ��һ���ڵ�����������ڵ�
{
    return nullptr == p ? nullptr : p->GetLeftChild();
}
template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::RightChild(BinaryTreeNode<T>* p)  // ���һ���ڵ�����������ڵ�
{
    return nullptr == p ? nullptr : p->GetRightChild();
}
template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::LeftSibling(BinaryTreeNode<T>* leftChild) // ȡ��һ���ڵ�����ֵ�ָ��
{
    BinaryTreeNode<T>* q;
    q = Parent(m_root, leftChild);
    if ( nullptr == q || leftChild == q->GetLeftChild() )
        return nullptr;
    else
        return q->GetLeftChild();
}
template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::RightSibling(BinaryTreeNode<T>* rightChild) // ȡ��һ���ڵ�����ֵ�ָ��
{
    BinaryTreeNode<T>* q;
    q = Parent(m_root, rightChild);
    if ( nullptr == q || rightChild == q->GetRightChild())
        return nullptr;
    else
        return q->GetRightChild();
}
template<typename T>
T BinaryTree<T>::GetData(BinaryTreeNode<T>* p) const // ����һ���ڵ������
{
    return p->GetData();
}
template<typename T>
void BinaryTree<T>::Assign(BinaryTreeNode<T>* p, const T& data)    // ����һ���ڵ������
{
    p->SetData(data);
}
template<typename T>
void BinaryTree<T>::InsertRightChild(BinaryTreeNode<T>* p, const T& data)  // �����Һ��ӵ���ǰ�ڵ���
{
    BinaryTreeNode<T>* q(new BinaryTreeNode<T>(data));
    q->SetRightChild(p->GetRightChild());
    p->SetRightChild(q);
}
template<typename T>
void BinaryTree<T>::InsertLeftChild(BinaryTreeNode<T>* p, const T& data)  // �������ӵ���ǰ�ڵ���
{
    BinaryTreeNode<T>* q = new BinaryTreeNode<T>(data);
    q->SetLeftChild(p->GetLeftChild());
    p->SetLeftChild(q);
}
template<typename T>
void BinaryTree<T>::DeleteLeftChild(BinaryTreeNode<T>* p)     // ɾ����ǰ�ڵ������
{
    Destroy(p->GetLeftChild());
}
template<typename T>
void BinaryTree<T>::DeleteRightChild(BinaryTreeNode<T>* p)   // ɾ����ǰ�ڵ���Һ���
{
    Destroy(p->GetRightChild());
}
template<typename T>
void BinaryTree<T>::PreOrderTraverse(BinaryTreeNode<T>* root)  const  // ǰ��������������ȸ�������
{
    // ����һ�ֵݹ�ʵ�ַ�����
    if (nullptr != root)
    {
        cout << root->GetData();
        PreOrderTraverse(root->GetLeftChild());
        PreOrderTraverse(root->GetRightChild());
    }

    /*
     // ����һ����ʹ��ջ�ṹ����ɶ�������ǰ�����

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
void BinaryTree<T>::InOrderTraverse(BinaryTreeNode<T>* root) const   // ����������������и�������
{
    // ����һ�ֵݹ�ʵ�ֵķ���
    if (nullptr != root)
    {
        InOrderTraverse(root->GetLeftChild());
        cout << root->GetData();
        InOrderTraverse(root->GetRightChild());
    }
    /*
    // ����һ��ʹ��ջ�ṹ����ɵĶ��������и�����
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
void BinaryTree<T>::PostOrderTraverse(BinaryTreeNode<T>* root) const // ������������������������
{
    // ����һ�ֵݹ�ʵ�ֵķ���
    if (nullptr != root)
    {
        PostOrderTraverse(root->GetLeftChild());
        PostOrderTraverse(root->GetRightChild());
        cout << root->GetData();
    }

    // ����һ��ʹ��ջ�ṹʵ�ֵĶ������ĺ������
}
template<typename T>
void BinaryTree<T>::LevelOrderTraverse(BinaryTreeNode<T>* root) const    // �������������
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
