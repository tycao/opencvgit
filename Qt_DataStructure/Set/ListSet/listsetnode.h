#pragma once

#include <iostream>

using namespace std;

// 类的前视声明
template<typename T> class ListSet;

template<typename T> std::ostream& operator << (std::ostream& os, ListSet<T>& set);

template<typename T>
class ListSetNode
{
    friend class ListSet<T>;    // 将ListSet类声明为ListSetNode的友元类
    friend std::ostream& operator << <>(std::ostream& os, ListSet<T>& set);
public:
    ListSetNode();
    ListSetNode(T value);
private:
    T data;
    ListSetNode<T>* link;
};

// public member function
template<typename T>
ListSetNode<T>::ListSetNode()
    : link(nullptr)
{

}
template<typename T>
ListSetNode<T>::ListSetNode(T value)
    : link(nullptr), data(value)
{

}

