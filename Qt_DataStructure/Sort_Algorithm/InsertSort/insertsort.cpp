#include "insertsort.h"

// ���캯��
InsertSort::InsertSort(std::vector<int> _list, int _len)
    : len(_len)
{
    // ��_list��ǰ_len��Ԫ�أ�������ӵ�list��
    for (int i = 0; i != _len; ++i)
        list.push_back(_list[i]);
}
// ֱ�Ӳ�������
void InsertSort::insert_sort()
{
    int insertNum;
    for (int i = 1; i != len; ++i)  // �ܹ�����len�β���
    {
        insertNum = list[i];    // ������Ԫ��
        int j = i;
        while (j > 0 && insertNum < list[j - 1])
        {
            list[j] = list[j - 1];
            --j;
        }
        list[j] = insertNum;
    }
}
// ��������������
void InsertSort::out()
{
    for (int i = 0; i != len; ++i)
    {
        cout << list[i] << " ";
        if ((i + 1) % 18 == 0)  // ��18��Ԫ�أ��ͻ���
            cout << endl;
    }
    cout << "\n";
}
