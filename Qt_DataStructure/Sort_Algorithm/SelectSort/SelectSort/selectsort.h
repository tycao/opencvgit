#pragma once

#include <vector>
#include <iostream>

using namespace std;

class SelectSort
{
public:
    SelectSort(std::vector<int> _list, int _len);   // 构造函数
    void select_sort(); // 直接选择排序
    void swap(int, int);
    void out(); // （直接选择排序）排序后，输出结果
private:
    int len;
    std::vector<int> list;
};
