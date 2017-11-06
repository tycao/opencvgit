#include "heapsort.h"

// ���캯��
HeapSort::HeapSort(std::vector<int> _list, int _len)
    : len(_len)
{
    for (int i = 0; i != len; ++i)
        list.push_back(_list[i]);
}
// ������
void HeapSort::heap_sort()
{
    for (int i = (len - 2) / 2; i >= 0; ++i)
        // ������
        filterDown(i, len - 1);
    for (int i = len - 1; i != 0; --i)
    {
        swap(0, i);
        filterDown(0, i - 1);   // ���ϵ�����Ϊ����
    }
}
// �ѵĽ������ߵ���
void HeapSort::filterDown(int current, int last)
{
    int child = 2 * current + 1;    // child Ϊcurrent����Ůλ��
    int temp = list[current];   // �ݴ��������ڵ�
    while (child <= last)
    {
        // �ж��Ƿ�����β
        if (child < last && list[child] < list[child + 1])
            ++child;
        // ��childָ������Ů�еĴ���
        if (temp >= list[child])
            break;  // temp�Ĺؼ������������
        else
        {
            list[current] = list[child];
            current = child;
            child = 2 * child + 1;  // current�½�����Ůλ��
        }
    }
    list[current] = temp;   // temp���ݴ�Ԫ�طŵ�����λ��
}
// ������Ԫ��λ��
void HeapSort::swap(int i, int j)
{
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}
// ��������Ľ��
void HeapSort::out()
{
    for (int i = 0; i != len; ++i)
    {
        cout << list[i] << " ";
        if ((i + 1) % 9 == 0)
            cout << endl;
    }
    cout << endl;
}
