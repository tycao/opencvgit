#include "binarysearchtreenode.h"

BinarySearchTree::BinarySearchTree(BinaryNode* rt)   // 构造函数
    : root(rt)
{

}
BinaryNode* BinarySearchTree::findMax(BinaryNode* t) const
{
    if (t != nullptr)
        while (t->rightChild != nullptr)
            t = t->rightChild;
    return t;
}
BinaryNode* BinarySearchTree::findMin(BinaryNode* t) const
{
    if (t != nullptr)
        while (t->leftChild != nullptr)
            t = t->leftChild;
    return t;
}
BinaryNode* BinarySearchTree::find(int x, BinaryNode* t) const
{
    while (t != nullptr)
        if (x < t->element)
            t = t->leftChild;
        else if (x > t->element)
            t = t->rightChild;
        else
            return t;
    return nullptr; // 若没有找到x,返回空指针
}

void BinarySearchTree::insert(int x, BinaryNode*& t)
{
    if (t == nullptr)
        t = new BinaryNode(x, nullptr, nullptr);
    else if (x < t->element)
        insert(x, t->leftChild);    // 运用递归思想
    else if (x > t->element)
        insert(x, t->rightChild);   // 运用递归思想
    else
    {
        cout << "Error!!!Duplicate Element!" << endl;
        return;
    }
}
void BinarySearchTree::remove(int x, BinaryNode*& t)
{
    if (t == nullptr)
    {
        cout << "This node does not exist!" << endl;
        return;
    }
    if (x < t->element)
        remove(x, t->leftChild);
    else if (x > t->element)
        remove(x, t->rightChild);
    else if (t->leftChild != nullptr && t->rightChild != nullptr)
    {
        t->element = this->findMin(t->rightChild)->element;
        removeMin(t->rightChild);
    }
    else
    {
        BinaryNode* tmp = t;
        t = (t->leftChild != nullptr) ? t->leftChild : t->rightChild;
        delete tmp;
    }
}
void BinarySearchTree::removeMin(BinaryNode*& t)
{
    if (t == nullptr)
    {
        cout << "Empty Tree!!!" << endl;
        return;
    }
    else if (t->leftChild != nullptr)
        removeMin(t->leftChild);
    else if (t->leftChild == nullptr)
    {
        BinaryNode* tmp = t;
        t = t->rightChild;
        delete tmp;
    }
}


