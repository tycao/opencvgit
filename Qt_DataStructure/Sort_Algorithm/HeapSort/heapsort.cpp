#include "heapsort.h"

// 构造函数
HeapSort::HeapSort(std::vector<int> _list, int _len)
    : len(_len)
{
    for (int i = 0; i != len; ++i)
        list.push_back(_list[i]);
}
// 堆排序
void HeapSort::heap_sort()
{
    for (int i = (len - 2) / 2; i >= 0; ++i)
        // 建立堆
        filterDown(i, len - 1);
    for (int i = len - 1; i != 0; --i)
    {
        swap(0, i);
        filterDown(0, i - 1);   // 不断调整堆为最大堆
    }
}
// 堆的建立或者调整
void HeapSort::filterDown(int current, int last)
{
    int child = 2 * current + 1;    // child 为current的子女位置
    int temp = list[current];   // 暂存子树根节点
    while (child <= last)
    {
        // 判断是否到最后结尾
        if (child < last && list[child] < list[child + 1])
            ++child;
        // 让child指向两子女中的大者
        if (temp >= list[child])
            break;  // temp的关键码大则不做调整
        else
        {
            list[current] = list[child];
            current = child;
            child = 2 * child + 1;  // current下降到子女位置
        }
    }
    list[current] = temp;   // temp中暂存元素放到合适位置
}
// 交换两元素位置
void HeapSort::swap(int i, int j)
{
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}
// 输出排序后的结果
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
