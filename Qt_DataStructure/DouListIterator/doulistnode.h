#pragma once

template<typename T>
class DouListNode
{
public:
    DouListNode() : link(nullptr), prior(nullptr) { }   // 默认构造函数
    DouListNode(T value) : link(nullptr), prior(nullptr), data(value) { }   // 含有一个T类型参数的构造函数（也可称为：转换构造函数）
    ~DouListNode() { }  // 析构函数

    void SetLink(DouListNode<T>*);  // 设置节点类中的link的值
    void SetPrior(DouListNode<T>*); // 设置节点类中的prior的值
    DouListNode<T>* GetLink();  // 返回节点类中的后继结点
    DouListNode<T>* GetPrior(); // 返回节点类中的前驱结点
    T& GetData();   // 返回节点中保存的数据
private:
    T data; // 节点类存储的数据
    DouListNode<T>* prior;  // 前驱结点
    DouListNode<T>* link;   // 后继结点
};

// 数据成员的实现
template<typename T>
void DouListNode<T>::SetLink(DouListNode<T>* next)
{
    link = next;
}

template<typename T>
void DouListNode<T>::SetPrior(DouListNode<T>* pre)
{
    prior = pre;
}

template<typename T>
DouListNode<T>* DouListNode<T>::GetLink()
{
    return link;
}

template<typename T>
DouListNode<T>* DouListNode<T>::GetPrior()
{
    return prior;
}

template<typename T>
T& DouListNode<T>::GetData()
{
    return data;
}
