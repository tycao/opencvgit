#include "binaryinsertsort.h"

// ���캯�� : ����һ��˳��
BinaryInsertSort::BinaryInsertSort(std::vector<int> _list, int _len)
    : len(_len)
{
    for (int i = 0; i != _len; ++i)
        list.push_back(_list[i]);
}
// ���ֲ�������
void BinaryInsertSort::binary_insert_sort()
{
    int middle;
    for (int i = 0; i != len; ++i)
    {
        int insertNum = list[i];
        int left = 0;
        int right = i - 1;
        while (left <= right)   // ���ַ�Ѱ�Ҳ���λ��
        {
            middle = (left + right) / 2;
            if (insertNum > list[middle])
                left = middle + 1;
            else
                right = middle - 1;
        }
        for (int j = i; j > left; --j)
            list[j] = list[j - 1];
        list[left] = insertNum;
    }
}
// �����ֲ��������ź���֮��������
void BinaryInsertSort::out()
{
    for (int i = 0; i != len; ++i)
    {
        cout << list[i] << " ";
        if ((i + 1) % 18 == 0) cout << "\n";    // ��18��Ԫ�أ���һ�����
    }
    cout << "\n";
}
