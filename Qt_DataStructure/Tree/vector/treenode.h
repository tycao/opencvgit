#pragma once

#include <vector>
#include <iostream>

using namespace std;

class TreeNode
{
public:
    TreeNode(int);
    int getNum();
    std::vector<TreeNode*>* getSub();
    void setNum(int);
    void setSub(std::vector<TreeNode*>* newSub);
    // ������Ա�������ԣ�
private:
    int num;
    std::vector<TreeNode*>* Sub;
};
