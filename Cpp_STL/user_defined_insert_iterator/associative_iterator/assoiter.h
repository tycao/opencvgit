#pragma once

#include <iterator>

/*
 * 这是一个关联式容器的insert迭代器 的模版类的创建源代码
*/
template<typename Container>
class asso_insert_iterator : public std::iterator<std::output_iterator_tag, void, void, void, void>
{
public:
    // 构造函数
    explicit asso_insert_iterator(Container& c)
        : container(c)
    {

    }

    // 拷贝赋值运算符
    // 将一条数据插入到容器内
    asso_insert_iterator<Container>& operator =(const typename Container::value_type& value)
    {
        container.insert(value);
        return *this;
    }

    // 解引用运算符
    // 不做任何操作，直接返回迭代器自身
    asso_insert_iterator<Container>& operator *()
    {
        return *this;
    }

    // 前置递增运算符
    // 不做任何操作，直接返回迭代器自身
    asso_insert_iterator<Container>& operator ++()
    {
        return *this;
    }

    // 后置递增运算符
    // 不做任何操作，直接返回迭代器自身
    asso_insert_iterator<Container>& operator ++(int)
    {
        return *this;
    }
protected:
    Container& container;   // 元素需要插入到此容器内
private:

};

// 更简单的接口，用来创建插入迭代器
// 是个内联函数 ： 编译器就可以展开该函数，降低运行时开销
template<typename Container>
inline asso_insert_iterator<Container> asso_insert(Container& c)
{
    return asso_insert_iterator<Container>(c);
}
