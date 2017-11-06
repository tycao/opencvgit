#pragma once

#include <vector>
#include <iostream>

using namespace std;

class HeapSort
{
public:
    HeapSort(std::vector<int> _list, int _len); // 构造函数
    void heap_sort();   // 堆排序
    void filterDown(int current, int last);  //
    void swap(int i, int j);    // 交换两元素位置
    void out(); // 输出排序后的结果
private:
    int len;
    std::vector<int> list;
};
