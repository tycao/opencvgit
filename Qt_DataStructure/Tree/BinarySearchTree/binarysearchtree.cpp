#include "binarysearchtree.h"

// Ĭ�Ϲ��캯��
BinaryNode::BinaryNode(int theElement, BinaryNode* lt, BinaryNode* rt)
    : element(theElement), leftChild(lt), rightChild(rt)
{

}

// ��ý����洢�����ݵ� �ӿں���
int BinaryNode::GetElement()
{
    return this->element;
}
