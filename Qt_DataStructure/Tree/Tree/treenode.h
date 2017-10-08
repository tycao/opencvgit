#pragma once

template<typename T>
class TreeNode
{
public:
    TreeNode(const T&); // 构造函数
    ~TreeNode();    // 析构函数
    bool isLeaf();  // 是否为叶子节点

    T getValue();   // 获取当前节点存储的数据
    TreeNode<T>* getLeftChild();    // 获取当前节点的最左子节点
    TreeNode<T>* getRightSibling(); // 获取当前节点的右兄弟节点

    void setValue(T& value);    // 设置当前节点内存储的数据
    void setLeftChild(TreeNode<T>*);    // 设置当前节点的最左子节点
    void setRightSibling(TreeNode<T>*); // 设置当前节点的右兄弟节点

private:
    T m_value;  // 树节点存储的数据
    TreeNode<T>* leftChild; // 第一个子节点，即最左子节点
    TreeNode<T>* rightSiblings; // 该节点的右兄弟节点
};
// 构造函数
template<typename T>
TreeNode<T>::TreeNode(const T& value)
    : m_value(value), leftChild(nullptr), rightSiblings(nullptr) { }

// 析构函数
template<typename T>
TreeNode<T>::~TreeNode() { }

// 判断当前节点 是否为叶子节点
template<typename T>
bool TreeNode<T>::isLeaf()
{
    if (nullptr == leftChild)
        return true;
    else
        return false;
}

// 获取当前节点存储的数据
template<typename T>
T TreeNode<T>::getValue()
{
    return this->m_value;
}

template<typename T>
TreeNode<T>* TreeNode<T>::getLeftChild()    // 获取当前节点的最左子节点
{
    return this->leftChild;
}
template<typename T>
TreeNode<T>* TreeNode<T>::getRightSibling() // 获取当前节点的右兄弟节点
{
    return this->rightSiblings;
}

template<typename T>
void TreeNode<T>::setValue(T& value)    // 设置当前节点内存储的数据
{
    this->m_value = value;
}

template<typename T>
void TreeNode<T>::setLeftChild(TreeNode<T>* leftChild)    // 设置当前节点的最左子节点
{
    this->leftChild = leftChild;
}

template<typename T>
void TreeNode<T>::setRightSibling(TreeNode<T>* rightSibling) // 设置当前节点的右兄弟节点
{
    this->rightSiblings = rightSibling;
}
