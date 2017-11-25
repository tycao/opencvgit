#pragma once

#include <cstdlib>
#include <stdexcept>

template<typename T, std::size_t thesize>
class carray
{
public:
    // ���ͱ����Ķ���
    typedef T               value_type;
    typedef T*              iterator;
    typedef const T*        const_iterator;
    typedef T&              reference;
    typedef const T&        const_reference;
    typedef std::size_t     size_type;
    typedef std::ptrdiff_t  different_type;

    // ֧�ֵ���
    iterator begin() { return v; }  // �����������Ԫ��
    const_iterator begin() const { return v; }  // begin()��Ա������ �����汾
    iterator end() { return v + thesize; }  // �������������һ��Ԫ�ص� ��һλ��
    const_iterator end() const { return v + thesize; }  // end() ��Ա������ �����汾

    // ������Ԫ�ص�ֱ�ӷ���
    reference operator[] (std::size_t t)
    {
        check_size(t);
        return v[t];
    }
    const_reference operator [](std::size_t t) const
    {
        check_size(t);
        return v[t];
    }

    // ���鳤���ǳ���
    size_type size() const { return thesize; }
    size_type max_size() const { return thesize; }

    // conversion to ordinary array
    T* as_array() { return v; }

private:
    T v[thesize];   // ӵ�й̶����ȵ�����ΪT��Ԫ������
    check_size(std::size_t t)
    {
        if (t < 0 || t >= thesize)
            throw std::runtime_error("exceed the length of the array.");
    }
};
