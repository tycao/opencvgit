#pragma once

#include <vector>
#include <iostream>

using namespace std;

class HeapSort
{
public:
    HeapSort(std::vector<int> _list, int _len); // ���캯��
    void heap_sort();   // ������
    void filterDown(int current, int last);  //
    void swap(int i, int j);    // ������Ԫ��λ��
    void out(); // ��������Ľ��
private:
    int len;
    std::vector<int> list;
};
