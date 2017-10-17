#pragma once

#include "binarysearchtree.h"


class BinarySearchTree
{
public:
    BinaryNode* root;
    BinarySearchTree(BinaryNode* rt);   // ���캯��
    BinaryNode* findMax(BinaryNode* t) const;
    BinaryNode* findMin(BinaryNode* t) const;
    BinaryNode* find(int x, BinaryNode* t) const;

    void insert(int x, BinaryNode*& t);
    void remove(int x, BinaryNode*& t);
    void removeMin(BinaryNode*& t);


    // ������Ա�������ԣ�
};
