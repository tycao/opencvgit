#pragma once

#include <iostream>

using namespace std;

// 先声明二叉搜索树类：因为接下来 “二叉搜索节点类” 会用到 “二叉搜索树类”
//class BinarySearchTree;

class BinaryNode
{
    // 将二叉搜索树类 声明为二叉搜索节点类的友元类（因此 “二叉搜索树类” 可以访问 “二叉搜索节点类” 的所有成员）
    friend class BinarySearchTree;
public:
    BinaryNode(int theElement, BinaryNode* lt, BinaryNode* rt);   // 默认构造函数
    // 获得结点里存储的数据的 接口函数
    int GetElement();

private:
    int element;    // 节点中存储的数值
    BinaryNode* leftChild;  // 节点的左孩子节点指针
    BinaryNode* rightChild; // 节点的右孩子节点指针

};
