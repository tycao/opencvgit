#pragma once

#include "item.h"

// ����������OrderSearch
template<typename T> class OrderSearch;

// Ȼ������ȫ�ֺ�����ģ����OrderSearch����Ԫ������
template<typename T> std::ostream& operator << (std::ostream&, OrderSearch<T>& set);

template<typename T>
class OrderSearch
{
    friend std::ostream& operator << <>(std::ostream& os, OrderSearch<T>& set);
public:
    OrderSearch();  // Ĭ�Ϲ��캯��
    OrderSearch(int MaxSize);   // ����һ���βεĹ��캯��

    // ��Ա����
    void Add(Item<T> add);  // ���һ������
    int GetSize() const;    // �������ĳߴ磨��С��
    const Item<T>* GetContain() const;  // ��þ�̬�������Ԫ��ָ��
    const Item<T>& search(int k) const;    // �����Ƿ���keyλk�� ��ֵ��
private:
    Item<T>* contain;
    int size;
};

// ��Ա������ʵ��
template<typename T>
OrderSearch<T>::OrderSearch()  // Ĭ�Ϲ��캯��
    : contain(nullptr), size(0)
{

}
template<typename T>
OrderSearch<T>::OrderSearch(int MaxSize)   // ����һ���βεĹ��캯��
    : contain(new Item<T>[MaxSize]),  // ���캯����ʼ���б� : �������顢��Ŷ�Ԫ�顣
      size(MaxSize) // ��¼�����С
{
    for (int i = 0; i != MaxSize; ++i)  //��ʼ���ֵ�
    {
        Item<T> ini;
        contain[i] = ini;
    }
}

// ��Ա����
template<typename T>
void OrderSearch<T>::Add(Item<T> add)  // ���һ������
{
    assert(add.GetKey() >= 0 && add.GetKey() < size);   // �ж�key�ĺϷ���
    contain[add.GetKey()] = add;    // ��Ӷ�Ԫ��
}
template<typename T>
int OrderSearch<T>::GetSize() const   // �������ĳߴ磨��С��
{
    return this->size;
}
template<typename T>
const Item<T>* OrderSearch<T>::GetContain() const // ��þ�̬�������Ԫ��ָ��
{
    return this->contain;
}
template<typename T>
const Item<T>& OrderSearch<T>::search(int k) const    // �����Ƿ���keyλk�� ��ֵ��
{
    assert(k >= 0 && k < size);   // �ж�key�ĺϷ���
    return contain[k];
}

// ��Ԫ������ʵ��
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
