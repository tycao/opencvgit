#pragma once

#include <vector>
#include <iostream>

using namespace std;

class BinaryInsertSort
{
public:
    BinaryInsertSort(std::vector<int> _list, int _len); // 构造函数
    void binary_insert_sort();  // 二分插入排序
    void out(); // 排好序之后，输出结果
private:
    int len;
    std::vector<int> list;
};
