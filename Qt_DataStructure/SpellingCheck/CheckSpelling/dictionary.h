#pragma once

#include <list>
#include <string>
#include <cstdlib>
#include <fstream>

#include "hashset.h"

using namespace std;

// 重载了函数调用运算符的类（函数对象类）
class hash_function
{
public:
    hash_function();  // 默认构造函数
    unsigned int operator ()(const std::string& s) const;   // 重载函数调用运算符（接受两个参数）
};

// 重载了函数调用运算符的类（函数对象类）
class equality
{
public:
    equality(); // 默认构造函数
    bool operator ()(const std::string& A, const std::string& B) const; // 重载函数调用运算符（接受两个参数）
};


class Dictionary : public HashSet<std::string, hash_function, equality>
{
protected:
    std::ifstream infile;
public:
    Dictionary(const std::string& filename);    // 构造函数
};
