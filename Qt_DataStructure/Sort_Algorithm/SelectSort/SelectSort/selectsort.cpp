#include "selectsort.h"

// ���캯��
SelectSort::SelectSort(std::vector<int> _list, int _len)
    : len(_len)
{
    // ����һ�����ݼ���
    for (int i = 0; i != _len; ++i)
        list.push_back(_list[i]);
}
// ֱ��ѡ������
void SelectSort::select_sort()
{
    int k;
    for (int i = 0; i != len; ++i)
    {
        // ����len�αȽ�
        k = i;
        for (int j = i + 1; j != len; ++j)  // ����СԪ��
            if (list[j] < list[k])
                k = j;
        swap(i, k); // ����СԪ�ز��� i λ��
    }
}
// ������Ԫ��λ��
void SelectSort::swap(int i, int j)
{
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}
// ��ֱ��ѡ�����򣩺����������
void SelectSort::out()
{
    for (int i = 0; i != len; ++i)
    {
        cout << list[i] << " ";
        if ((i + 1) % 9 == 0)
            cout << endl;
    }
    cout << endl;
}
