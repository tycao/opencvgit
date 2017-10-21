#pragma once

#include "avlnode.h"

template<typename T>
class AvlTree
{
public:
    // ���캯��
    AvlTree();
    AvlTree(T x);
    AvlNode<T>* GetRoot() const;    // ��ȡ���ڵ�
    bool Insert(T x);
    bool Remove(T x);
    void DisplayTree(AvlNode<T>* t, int layer) const;
private:
    AvlNode<T>* root;
    bool Insert(AvlNode<T>*& rt, T x, bool& taller);
    bool Remove(AvlNode<T>*& rt, T x, bool& shorter);
    void RotateLeft(AvlNode<T>*& node); // ��������
    void RotateRight(AvlNode<T>*& node); // ��������
    void RightBalanceAfterInsert(AvlNode<T>*& sRoot, bool& taller);
    void LeftBalanceAfterInsert(AvlNode<T>*& sRoot, bool& taller);
    void RightBalanceAfterDelete(AvlNode<T>*& sRoot, bool& shorter);
    void LeftBalanceAfterDelete(AvlNode<T>*& sRoot, bool& shorter);
};

// ˽�г�Ա������ʵ��
template<typename T>
bool AvlTree<T>::Insert(AvlNode<T>*& rt, T x, bool& taller)
{
    bool success;
    // �ݹ麯���ġ�����������
    if (rt == nullptr)
    {
        rt = new AvlNode<T>(x);
        success = rt != nullptr ? true : false;
        if (success)
            taller = true;
    }
    // ��x��ֵС��rt�Ĺؼ���
    else if (x < rt->data)
    {
        // Insert �ĵݹ���ã���rt��������Ѱ�Һ��ʵ�λ�ò���
        success = Insert(rt->rightChild, x, taller);
        if (taller) // ������� ʹ��rt���и߶�����
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
// ɾ��ֵΪx�Ľ�㣬ʵ�ַ�ʽ���õݹ�
template<typename T>
bool AvlTree<T>::Remove(AvlNode<T>*& rt, T x, bool& shorter)
{
    bool success = false;
    if (rt == nullptr) return false;
    // ��rt����Ҫɾ���Ľ��
    if (x == rt->data)
    {
        if (rt->leftChild != nullptr && rt->rightChild != nullptr)
        {
            // Ѱ��rt�����������ǰ����㣬��r��ʾ
            AvlNode<T>* r = rt->leftChild;
            while (r->rightChild != nullptr)
            {
                r = r->rightChild;
            }
            // ����rt��r��ֵ
            T temp = rt->data;
            rt->data = r->data;
            r->data = temp;
            // �ݹ麯������rt����������ɾ���ؼ���Ϊx�Ľڵ�
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
            // rt���ֻ��һ����Ů�����ǵݹ�ĳ���
            AvlNode<T>* p = rt;
            rt = rt->leftChild != nullptr ? rt->leftChild : rt->rightChild;
            delete p;
            success = true;
            shorter = true;
        }
    }
    else if (x < rt->data)
    {
        // �ݹ���ú�������rt����������ɾ���ؼ���Ϊx�Ľڵ�
        success = Remove(rt->leftChild, x, shorter);
        if (shorter)
        {   // ��ɾ��������rt����߶ȼ���
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
        // �ݹ麯�����á���rt����������ɾ���ؼ���Ϊx�Ľ��
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
void AvlTree<T>::RotateLeft(AvlNode<T>*& node) // ��������
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
void AvlTree<T>::RotateRight(AvlNode<T>*& node) // ��������
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
        cout << "ƽ������������Ѿ�ƽ�⻯��" << endl;
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
        cout << "ƽ������������Ѿ�ƽ�⻯��" << endl;
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
// ���ɾ���ڵ��rt����߶ȼ��٣�����ô˺�������ƽ�⻯
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
//  ���ɾ���ڵ��rt���Ҹ߶ȼ��٣�����ô˺�������ƽ�⻯
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

// ���г�Ա������ʵ��
template<typename T>
AvlTree<T>::AvlTree()  // ���캯��
    : root(nullptr)
{

}
template<typename T>
AvlNode<T>* AvlTree<T>::GetRoot() const    // ��ȡ���ڵ�
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
