// ϣ������
#pragma once

#include <vector>
#include <iostream>

using namespace std;

class ShellSort
{
public:
    // ���캯��
    ShellSort(std::vector<int> _list, int _len);
    void shell_sort();  // ϣ������
    void out(); // ����˳�������ϣ����������Ԫ��
private:
    int len;
    std::vector<int> list;
};
