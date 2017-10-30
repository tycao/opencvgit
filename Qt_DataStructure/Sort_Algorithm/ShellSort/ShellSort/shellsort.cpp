#include "shellsort.h"

// ���캯��
ShellSort::ShellSort(std::vector<int> _list, int _len)
    : len(_len)
{
    for (int i = 0; i != len; ++i)
        list.push_back(_list[i]);
}
// ϣ������
void ShellSort::shell_sort()
{
    int insertNum;  // ��ʼ����
    int gap = len / 2;
    while (gap) // �� gap >= 1
    {
        for (int i = gap; i != len; ++i)
        {
            // ��gap��������н��в�������
            insertNum = list[i];    // ������Ԫ��
            int j = i;
            while (j >= gap && insertNum < list[j - gap])
            {
                // Ѱ�Ҳ���λ��
                list[j] = list[j - gap];
                j -= gap;
            }
            list[j] = insertNum;    // ����
        }
        gap = gap / 2;  // ��С����
    }
}

// ����˳�������ϣ����������Ԫ��
void ShellSort::out()
{
    for (int i = 0; i != len; ++i)
    {
        cout << list[i] << " ";
        if ((i + 1) % 9 == 0)
            cout << endl;
    }
    cout << "\n";
}
