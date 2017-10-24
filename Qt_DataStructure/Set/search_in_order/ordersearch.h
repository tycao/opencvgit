#pragma once

#include "item.h"

// 首先声明类OrderSearch
template<typename T> class OrderSearch;

// 然后声明全局函数（模版类OrderSearch的友元函数）
template<typename T> std::ostream& operator << (std::ostream&, OrderSearch<T>& set);

template<typename T>
class OrderSearch
{
    friend std::ostream& operator << <>(std::ostream& os, OrderSearch<T>& set);
public:
    OrderSearch();  // 默认构造函数
    OrderSearch(int MaxSize);   // 带有一个形参的构造函数

    // 成员函数
    void Add(Item<T> add);  // 添加一条数据
    int GetSize() const;    // 获得数组的尺寸（大小）
    const Item<T>* GetContain() const;  // 获得静态数组的首元素指针
    const Item<T>& search(int k) const;    // 搜索是否含有key位k的 键值对
private:
    Item<T>* contain;
    int size;
};

// 成员函数的实现
template<typename T>
OrderSearch<T>::OrderSearch()  // 默认构造函数
    : contain(nullptr), size(0)
{

}
template<typename T>
OrderSearch<T>::OrderSearch(int MaxSize)   // 带有一个形参的构造函数
    : contain(new Item<T>[MaxSize]),  // 构造函数初始化列表 : 建立数组、存放二元组。
      size(MaxSize) // 记录数组大小
{
    for (int i = 0; i != MaxSize; ++i)  //初始化字典
    {
        Item<T> ini;
        contain[i] = ini;
    }
}

// 成员函数
template<typename T>
void OrderSearch<T>::Add(Item<T> add)  // 添加一条数据
{
    assert(add.GetKey() >= 0 && add.GetKey() < size);   // 判断key的合法性
    contain[add.GetKey()] = add;    // 添加二元组
}
template<typename T>
int OrderSearch<T>::GetSize() const   // 获得数组的尺寸（大小）
{
    return this->size;
}
template<typename T>
const Item<T>* OrderSearch<T>::GetContain() const // 获得静态数组的首元素指针
{
    return this->contain;
}
template<typename T>
const Item<T>& OrderSearch<T>::search(int k) const    // 搜索是否含有key位k的 键值对
{
    assert(k >= 0 && k < size);   // 判断key的合法性
    return contain[k];
}

// 友元函数的实现
template<typename T>
std::ostream& operator << (std::ostream& os, OrderSearch<T>& set)
{
    for (int i = 0; i != set.GetSize(); ++i)
    {
        os << "key:" << set.GetContain()[i].GetKey() << "\t"
             << "data:" << set.GetContain()[i].GetData() << "\n";
    }
    return os;
}
