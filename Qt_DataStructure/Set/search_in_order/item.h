#pragma once

#include <cassert>
#include <iostream>

using namespace std;

// 首先声明模版类Item
template<typename T> class Item;

// 首先声明全局友元函数
template<typename T>
std::ostream& operator <<(std::ostream& os, const Item<T>& item);

template<typename T>
class Item
{
    friend std::ostream& operator << <>(std::ostream& os, const Item<T>& item);
public:
    Item(); // 默认构造函数
    Item(int keyInput, T value); // 带有形式参数的构造函数
    int GetKey() const; // 获得 关键码
    T GetData() const;  // 获得 键值
private:
    int key;
    T data;
};

// 函数实现
template<typename T>
Item<T>::Item() // 默认构造函数
    : key(-1)
{

}
template<typename T>
Item<T>::Item(int keyInput, T value) // 带有形式参数的构造函数
    : key(keyInput), data(value)
{
    assert(key >= 0);
}
template<typename T>
int Item<T>::GetKey() const // 获得 关键码
{
    return this->key;
}
template<typename T>
T Item<T>::GetData() const  // 获得 键值
{
    return this->data;
}

template<typename T>
std::ostream& operator <<(std::ostream& os, const Item<T>& item)
{
    os << "key: " << item.GetKey() << "\t" << "data:" << item.GetData() << endl;
    return os;
}


