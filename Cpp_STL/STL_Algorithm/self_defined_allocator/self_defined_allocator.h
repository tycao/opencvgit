#pragma once

#include <iostream>
#include <limits>   // for numeric_limits<T>

namespace std {
template<typename T>
class my_allocator
{
public:
    // ���Ͷ���
    typedef     size_t      size_type;
    typedef     ptrdiff_t   difference_type;
    typedef     T*          pointer;
    typedef     const T*    const_pointer;
    typedef     T&          reference;
    typedef     const T&    const_reference;
    typedef     T           value_type;

    // rebind my_allocator to type U
    template<typename U>
    struct rebind {
        typedef my_allocator<U>    other;
    };

    // return address of value
    pointer address(reference value) const {
        return &value;
    }

    const_pointer address(const_reference value) const {
        return &value;
    }

    /*
     * constructors and destructor
     * - nothing to do because the my_allocator has no state
    */
    my_allocator() noexcept { /* nothing to do here */ }   // ��֤�����׳��쳣
    my_allocator(const my_allocator&) noexcept { /*nothing to do here*/ } // ��֤���׳��쳣

    template<typename U>
    my_allocator(const my_allocator<U>&) noexcept { } // ��֤���׳��쳣
    // ��������
    ~my_allocator() noexcept { }

    // return maximum number of elements that can be allocated
    size_type max_size() const noexcept {
        return std::numeric_limits<size_t>::max() / sizeof(T);
    }

    // allocate but don't initialize num elements of type T
    pointer allocate(size_type num, allocator<void>::const_pointer hint = nullptr) {
        // ʹ��ȫ��new������ �����ڴ�
        return static_cast<pointer>(::operator new(num * sizeof(T)));
    }

    // initialize elements of allocated storage p with value val
    void construct(pointer p, const_reference val) {
        // ʹ�� ����λnew�� (placement new) ��ʼ���ڴ�
        new(static_cast<void*>(p))T(val);   // ��pָ��ģ��Ѿ��ڶ�������ģ��ڴ������У�����T����Ĺ��캯��
    }

    // destroy elements of initialized storage p �����ڣ��Ѿ��ڶ��������һ�飩�ڴ����Ѿ���ʼ����Ԫ��
    void destroy(pointer p) {
        p->~T();
    }

    // deallocate storage p of deleted elements
    void deallocate(pointer p, size_type num) {
        // deallocate memory with global new ʹ��ȫ��new ��deallocate �ڴ�
        ::operator delete(static_cast<void*>(p));
    }
};

// return that all specializations of this allocator are interchangable
template<typename T1, typename T2>
bool operator ==(const my_allocator<T1>&, const my_allocator<T2>&) noexcept
{
    return true;
}

template<typename T1, typename T2>
bool operator !=(const my_allocator<T1>&, const my_allocator<T2>&) noexcept
{
    return false;
}
}
