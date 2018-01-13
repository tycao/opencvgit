#pragma once
#include <memory>   // for allocator<T>
#include <iostream>

namespace std {
// ���ͱ�������
typedef int size_type;

template<typename T, typename Allocator = allocator<T>>
class vector {
public:
    // ���캯��
    explicit vector(const Allocator a = Allocator());
    explicit vector(size_type num, const T& val = T(), const Allocator& a = Allocator());

    template<typename InputIterator>
    vector(InputIterator begin, InputIterator end, const Allocator& = Allocator());

    vector(const vector<T, Allocator>& v);

    void print() const;
private:
    Allocator alloc;    // ������
    T* elems;    // Ԫ������
    size_type numElems; // Ԫ������
    size_type sizeElems;    // ����Ԫ�ص��ڴ��С
};
}

// ����ʵ�ֲ���
namespace std
{
template<typename T, typename Allocator>
vector<T, Allocator>::vector(size_type num, const T& val, const Allocator& a)
    : alloc(a)  // ��ʼ���б���ʼ��������
{
    // allocate memory
    sizeElems = numElems = num;
    elems = alloc.allocate(num);
/*
    // ��ʼ��Ԫ��
    for (size_type i = 0; i != num; ++i) {
        // ��ʼ����i��Ԫ��
        alloc.construct(&elems[i], val);
    }
*/
    // �ڶ��ַ�ʽ��ʼ��Ԫ��
    uninitialized_fill_n(elems, num, val);
}

template<typename T, typename Allocator>
vector<T, Allocator>::vector(const Allocator a)
    : alloc(a), sizeElems(0), numElems(0), elems(nullptr)
{

}

template<typename T, typename Allocator>
void vector<T, Allocator>::print() const {
    for (size_type i = 0; i < numElems; ++i)
    {
        cout << elems[i] << " ";
    }
    cout << "\n";
}
}

