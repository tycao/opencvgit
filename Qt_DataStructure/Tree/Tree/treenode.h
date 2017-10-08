#pragma once

template<typename T>
class TreeNode
{
public:
    TreeNode(const T&); // ���캯��
    ~TreeNode();    // ��������
    bool isLeaf();  // �Ƿ�ΪҶ�ӽڵ�

    T getValue();   // ��ȡ��ǰ�ڵ�洢������
    TreeNode<T>* getLeftChild();    // ��ȡ��ǰ�ڵ�������ӽڵ�
    TreeNode<T>* getRightSibling(); // ��ȡ��ǰ�ڵ�����ֵܽڵ�

    void setValue(T& value);    // ���õ�ǰ�ڵ��ڴ洢������
    void setLeftChild(TreeNode<T>*);    // ���õ�ǰ�ڵ�������ӽڵ�
    void setRightSibling(TreeNode<T>*); // ���õ�ǰ�ڵ�����ֵܽڵ�

private:
    T m_value;  // ���ڵ�洢������
    TreeNode<T>* leftChild; // ��һ���ӽڵ㣬�������ӽڵ�
    TreeNode<T>* rightSiblings; // �ýڵ�����ֵܽڵ�
};
// ���캯��
template<typename T>
TreeNode<T>::TreeNode(const T& value)
    : m_value(value), leftChild(nullptr), rightSiblings(nullptr) { }

// ��������
template<typename T>
TreeNode<T>::~TreeNode() { }

// �жϵ�ǰ�ڵ� �Ƿ�ΪҶ�ӽڵ�
template<typename T>
bool TreeNode<T>::isLeaf()
{
    if (nullptr == leftChild)
        return true;
    else
        return false;
}

// ��ȡ��ǰ�ڵ�洢������
template<typename T>
T TreeNode<T>::getValue()
{
    return this->m_value;
}

template<typename T>
TreeNode<T>* TreeNode<T>::getLeftChild()    // ��ȡ��ǰ�ڵ�������ӽڵ�
{
    return this->leftChild;
}
template<typename T>
TreeNode<T>* TreeNode<T>::getRightSibling() // ��ȡ��ǰ�ڵ�����ֵܽڵ�
{
    return this->rightSiblings;
}

template<typename T>
void TreeNode<T>::setValue(T& value)    // ���õ�ǰ�ڵ��ڴ洢������
{
    this->m_value = value;
}

template<typename T>
void TreeNode<T>::setLeftChild(TreeNode<T>* leftChild)    // ���õ�ǰ�ڵ�������ӽڵ�
{
    this->leftChild = leftChild;
}

template<typename T>
void TreeNode<T>::setRightSibling(TreeNode<T>* rightSibling) // ���õ�ǰ�ڵ�����ֵܽڵ�
{
    this->rightSiblings = rightSibling;
}
