#pragma once

#include <vector>
#include <iostream>

using namespace std;

class BinaryInsertSort
{
public:
    BinaryInsertSort(std::vector<int> _list, int _len); // ���캯��
    void binary_insert_sort();  // ���ֲ�������
    void out(); // �ź���֮��������
private:
    int len;
    std::vector<int> list;
};
