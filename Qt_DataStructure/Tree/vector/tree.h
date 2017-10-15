#pragma once

#include "treenode.h"

class Tree
{
public:
    Tree(TreeNode* rt); // 构造函数 ： 初始化树的根节点
    void DisplayTree(TreeNode* r);
private:
    TreeNode* root;
    // 其他成员方法（略）
};
