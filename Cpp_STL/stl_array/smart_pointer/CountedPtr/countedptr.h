#pragma once


/*
 * class for counted reference semantics
 * - delete the object to which it refers when the last CountedPtr that refers to it is destroyed
*/
template<typename T>
class CountedPtr
{
public:
    explicit CountedPtr(T* p = nullptr)
        : ptr(p),   // 初始化为空指针
          count(new long(1))    // 初始化为 1
    { }    // 空的函数体 ： 不做任何操作

    // 拷贝构造函数
    CountedPtr(const CountedPtr<T>& p) noexcept(false)
        : ptr(p.ptr),
          count(p.count)
    {
        ++(*count);
    }

    // 拷贝赋值运算符
    CountedPtr& operator =(const CountedPtr<T>& p)
    {
        // 防止自赋值
        if (this != &p)
        {
            dispose();
            ptr = p.ptr;
            count = p.count;
            ++*count;
        }
        return *this;
    }

    // 析构函数
    ~CountedPtr() noexcept(false)
    {
        dispose();  // 若当前对象没有被其他对象引用了，则小慧当前对象 以及 相应的引用计数
    }

    // 重载 自定义运算符
    T& operator *() const noexcept(false)
    {
        return *this->ptr;
    }

    T* operator ->() const noexcept(false)
    {
        return this->ptr;
    }
private:
    T* ptr;     // 引用的对象
    long* count;    // 引用计数 ： 用来记录一个对象被引用多少次

    // 判断引用计数是否为0，若是，则销毁被引用的对象 以及 引用计数
    void dispose()
    {
        if (--*count == 0)
        {
            delete count;
            delete ptr;
        }
    }
};
