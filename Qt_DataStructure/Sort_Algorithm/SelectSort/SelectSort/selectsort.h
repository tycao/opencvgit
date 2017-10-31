#pragma once

#include <vector>
#include <iostream>

using namespace std;

class SelectSort
{
public:
    SelectSort(std::vector<int> _list, int _len);   // ���캯��
    void select_sort(); // ֱ��ѡ������
    void swap(int, int);
    void out(); // ��ֱ��ѡ�����������������
private:
    int len;
    std::vector<int> list;
};
