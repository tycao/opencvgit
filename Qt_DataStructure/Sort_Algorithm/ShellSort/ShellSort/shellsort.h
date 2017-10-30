// 希尔排序
#pragma once

#include <vector>
#include <iostream>

using namespace std;

class ShellSort
{
public:
    // 构造函数
    ShellSort(std::vector<int> _list, int _len);
    void shell_sort();  // 希尔排序
    void out(); // 按照顺序输出（希尔）排序后的元素
private:
    int len;
    std::vector<int> list;
};
