#include "treenode.h"

TreeNode::TreeNode(int n)
    : num(n), Sub(nullptr)
{

}
int TreeNode::getNum()
{
    return this->num;
}
std::vector<TreeNode*>* TreeNode::getSub()
{
    return this->Sub;
}
void TreeNode::setNum(int i)
{
    this->num = i;
}
void TreeNode::setSub(std::vector<TreeNode*>* newSub)
{
    this->Sub = newSub;
}
