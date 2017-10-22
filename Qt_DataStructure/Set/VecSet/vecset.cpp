#include "vecset.h"

// 默认构造函数
VecSet::VecSet()
    : contain(nullptr), size(0)
{

}
// 带有一个int类型形参的构造函数
VecSet::VecSet(int MaxSize)
    : size(MaxSize)
{
    assert(MaxSize > 0);    // 判断MaxSize是否合法
    contain = new int[size];    // 创建位向量
    for (int i = 0; i != size; ++i)
        contain[i] = 0;     // 位相量赋初值，默认为空
}

// public member function
void VecSet::Add(int add)
{
    assert(add >= 0 && add < size);  // 判断add是否合法
    contain[add] = 1;   // 添加新元素
}
void VecSet::Del(int del)
{
    assert(del >= 0 && del < size); // 判断del是否合法
    contain[del] = 0;   // 删除元素
}
void VecSet::MakeEmpty()
{
    for (int i = 0; i != size; ++i)
        contain[i] = 0; // 循环删除，直到位向量为空
}
int VecSet::GetSize()
{
    return this->size;
}
int VecSet::GetAt(int index)
{
    assert(index >= 0 && index < size);  // 判断index是否合法
    if (contain[index] == 1)    // 若位相量中存在索引为index的元素
        return index;           // 则返回这个元素
    else
        return -1;              // 否则返回-1
}

// 运算符重载
VecSet& VecSet::operator + (VecSet& another)   // 运算符'+'重载
{
    checkSize(another);   // 首先判断两个集合是否等大
    for (int i = 0; i != size; ++i)
        contain[i] = contain[i] || another.contain[i];  // 利用 “或” 操作实现集合的 “并”
    return *this;
}
VecSet& VecSet::operator - (VecSet& another)   // 运算符'-'重载
{
    checkSize(another);   // 首先判断两个集合是否等大
    for (int i = 0; i != size; ++i)
        contain[i] = this->contain[i] && (!another.contain[i]);     // 利用 “与或” 运算及 “&&” 的求值顺序，求集合间的差
    return *this;
}
VecSet& VecSet::operator * (VecSet& another)   // 运算符'*'重载
{
    checkSize(another);   // 首先判断两个集合是否等大
    for (int i = 0; i != size; ++i)
        contain[i] = contain[i] && another.contain[i];  // 利用 “与” 操作，实现集合的交集
    return *this;
}
VecSet& VecSet::operator = (VecSet& another)   // 运算符'='重载
{
    checkSize(another);   // 首先判断两个集合是否等大
    for (int i = 0; i != size; ++i)
        this->contain[i] = another.contain[i];  // 循环赋值
    return *this;
}
bool VecSet::operator == (VecSet& another)  // 运算符'=='重载
{
    checkSize(another);   // 首先判断两个集合是否等大
    for (int i = 0; i != size; ++i)
        if (contain[i] != another.contain[i])
            return false;   // 若有一个元素不等，则返回false
    return true;
}

// private member function
void VecSet::checkSize(VecSet &another)
{
    assert(this->GetSize() == another.GetSize());
}
