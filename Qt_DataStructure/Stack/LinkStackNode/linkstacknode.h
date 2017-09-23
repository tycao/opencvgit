#pragma once

template<typename T>
class LinkStackNode
{
public:
    LinkStackNode(); // 默认构造函数
    LinkStackNode(T); // 含有一个形参类型为T的构造函数

    LinkStackNode<T>*& GetLink();   // 用户接口函数：返回对象包含的私有数据成员
    T& GetData();   // 接口函数：返回对象包含的私有数据成员
private:
    LinkStackNode<T>* link; // 数据成员（指针）
    T data; //
};
template<typename T>
LinkStackNode<T>::LinkStackNode() : link(nullptr) { } // 默认构造函数

template<typename T>
LinkStackNode<T>::LinkStackNode(T value) : data(value), link(nullptr) { } // 含有一个形参类型为T的构造函数

template<typename T>
LinkStackNode<T>*& LinkStackNode<T>::GetLink() { return this->link; }

template<typename T>
T& LinkStackNode<T>::GetData() { return this->data; }
