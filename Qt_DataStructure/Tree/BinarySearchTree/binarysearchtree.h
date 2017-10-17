#pragma once

#include <iostream>

using namespace std;

// �����������������ࣺ��Ϊ������ �����������ڵ��ࡱ ���õ� �������������ࡱ
//class BinarySearchTree;

class BinaryNode
{
    // �������������� ����Ϊ���������ڵ������Ԫ�ࣨ��� �������������ࡱ ���Է��� �����������ڵ��ࡱ �����г�Ա��
    friend class BinarySearchTree;
public:
    BinaryNode(int theElement, BinaryNode* lt, BinaryNode* rt);   // Ĭ�Ϲ��캯��
    // ��ý����洢�����ݵ� �ӿں���
    int GetElement();

private:
    int element;    // �ڵ��д洢����ֵ
    BinaryNode* leftChild;  // �ڵ�����ӽڵ�ָ��
    BinaryNode* rightChild; // �ڵ���Һ��ӽڵ�ָ��

};
