#pragma once

#include "treenode.h"

class Tree
{
public:
    Tree(TreeNode* rt); // ���캯�� �� ��ʼ�����ĸ��ڵ�
    void DisplayTree(TreeNode* r);
private:
    TreeNode* root;
    // ������Ա�������ԣ�
};
