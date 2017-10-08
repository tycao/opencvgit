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
    Tree(); // Ĭ�Ϲ��캯��
    Tree(TreeNode<T>* rt);  // ���캯�����������Ľṹ
    ~Tree();    // ��������
    TreeNode<T>* getRoot();  // �������ĸ��ڵ㣬��Ϊ�������򷵻�nullptr
    TreeNode<T>* Parent(TreeNode<T>* current);  // ���ؽڵ�current�ĸ��ڵ㣬��currentΪ���ڵ㣬�򷵻�nullptr
    TreeNode<T>* getFirstChild(TreeNode<T>* t); // ���ؽڵ�t�ĵ�һ���ӽڵ㣬���� �򷵻�nullptr
    TreeNode<T>* getNextSibling(TreeNode<T>* t);  // ���ؽڵ�t����һ���ֵܽڵ㣬���� �򷵻�nullptr
    void insertChild(TreeNode<T>* t, TreeNode<T>* n);   // �ڽڵ�t�� ����һ���ӽڵ�n
    void deleteSubTree(TreeNode<T>* t);   // ɾ����tΪ���ڵ������
    bool isEmpty(); // �ж��Ƿ�Ϊ����
};

// Ĭ�Ϲ��캯��
template<typename T>
Tree<T>::Tree()
    : root(nullptr), parent(nullptr) { }

// ���캯�����������Ľṹ
template<typename T>
Tree<T>::Tree(TreeNode<T>* rt)
    : root(rt), parent(nullptr) { }

// ��������
template<typename T>
Tree<T>::~Tree() { }

// �������ĸ��ڵ㣬��Ϊ�������򷵻�nullptr
template<typename T>
TreeNode<T>* Tree<T>::getRoot()
{
    return root;
}

// ���ؽڵ�current�ĸ��ڵ㣬��currentΪ���ڵ㣬�򷵻�nullptr
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

// ���ؽڵ�t�ĵ�һ���ӽڵ㣬���� �򷵻�nullptr
template<typename T>
TreeNode<T>* Tree<T>::getFirstChild(TreeNode<T>* t)
{
    return t->getLeftChild();
}

// ���ؽڵ�t����һ���ֵܽڵ㣬���� �򷵻�nullptr
template<typename T>
TreeNode<T>* Tree<T>::getNextSibling(TreeNode<T>* t)
{
    return t->getRightSibling();
}

// �ڽڵ�t�� ����һ���ӽڵ�n
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

// ɾ����tΪ���ڵ������
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

// �ж��Ƿ�Ϊ����
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
