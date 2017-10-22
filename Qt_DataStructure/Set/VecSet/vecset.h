#pragma once

#include <iostream>
#include <cassert>

using namespace std;

class VecSet
{
    friend std::ostream& operator << (std::ostream& os, VecSet& vset);
public:
    VecSet();   // 默认构造函数
    VecSet(int MaxSize);    // 带有一个int类型形参的构造函数

    // public member function
    void Add(int add);
    void Del(int del);
    void MakeEmpty();
    int GetSize();
    int GetAt(int index);
    VecSet& operator + (VecSet& another);   // 运算符'+'重载
    VecSet& operator - (VecSet& another);   // 运算符'-'重载
    VecSet& operator * (VecSet& another);   // 运算符'*'重载
    VecSet& operator = (VecSet& another);   // 运算符'='重载
    bool operator == (VecSet& another);  // 运算符'=='重载
private:
    void checkSize(VecSet& another);
    int* contain;
    int size;
};
// 全局函数
inline std::ostream& operator << (std::ostream& os, VecSet& vset)
{
    for (int i = 0; i != vset.GetSize(); ++i)
        cout << vset.GetAt(i) << "*";   //输出位向量代表的集合
    return os;
}
