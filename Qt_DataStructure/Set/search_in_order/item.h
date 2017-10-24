#pragma once

#include <cassert>
#include <iostream>

using namespace std;

// ��������ģ����Item
template<typename T> class Item;

// ��������ȫ����Ԫ����
template<typename T>
std::ostream& operator <<(std::ostream& os, const Item<T>& item);

template<typename T>
class Item
{
    friend std::ostream& operator << <>(std::ostream& os, const Item<T>& item);
public:
    Item(); // Ĭ�Ϲ��캯��
    Item(int keyInput, T value); // ������ʽ�����Ĺ��캯��
    int GetKey() const; // ��� �ؼ���
    T GetData() const;  // ��� ��ֵ
private:
    int key;
    T data;
};

// ����ʵ��
template<typename T>
Item<T>::Item() // Ĭ�Ϲ��캯��
    : key(-1)
{

}
template<typename T>
Item<T>::Item(int keyInput, T value) // ������ʽ�����Ĺ��캯��
    : key(keyInput), data(value)
{
    assert(key >= 0);
}
template<typename T>
int Item<T>::GetKey() const // ��� �ؼ���
{
    return this->key;
}
template<typename T>
T Item<T>::GetData() const  // ��� ��ֵ
{
    return this->data;
}

template<typename T>
std::ostream& operator <<(std::ostream& os, const Item<T>& item)
{
    os << "key: " << item.GetKey() << "\t" << "data:" << item.GetData() << endl;
    return os;
}


