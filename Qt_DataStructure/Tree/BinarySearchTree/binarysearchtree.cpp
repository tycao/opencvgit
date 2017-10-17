#include "binarysearchtree.h"

// 默认构造函数
BinaryNode::BinaryNode(int theElement, BinaryNode* lt, BinaryNode* rt)
    : element(theElement), leftChild(lt), rightChild(rt)
{

}

// 获得结点里存储的数据的 接口函数
int BinaryNode::GetElement()
{
    return this->element;
}
