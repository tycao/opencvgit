#include "dictionary.h"

// 类hash_function
hash_function::hash_function() { } // 默认构造函数

unsigned int hash_function::operator ()(const std::string& s) const   // 重载函数调用运算符（接受两个参数）
{
    unsigned int res = 0;
    for (int i = 0; i < s.size(); ++i)
        res = res * 1000 + s.at(i);
    return res;
}

// 类equality
equality::equality() { }  // 默认构造函数

bool equality::operator ()(const std::string& A, const std::string& B) const // 重载函数调用运算符（接受两个参数）
{
    return A == B;
}


// 类Dictionary
Dictionary::Dictionary(const std::string& filename)    // 构造函数
{
    infile.open(filename.c_str());
    if (!infile)
    {
        cerr << "can not open " << filename + " for input.\n";
        return;
    }
    string line;
    while (getline(infile, line))
        insert(line);
    infile.close();
}
