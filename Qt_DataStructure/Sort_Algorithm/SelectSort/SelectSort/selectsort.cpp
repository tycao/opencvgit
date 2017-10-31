#include "selectsort.h"

// 构造函数
SelectSort::SelectSort(std::vector<int> _list, int _len)
    : len(_len)
{
    // 构造一个数据集合
    for (int i = 0; i != _len; ++i)
        list.push_back(_list[i]);
}
// 直接选择排序
void SelectSort::select_sort()
{
    int k;
    for (int i = 0; i != len; ++i)
    {
        // 进行len次比较
        k = i;
        for (int j = i + 1; j != len; ++j)  // 找最小元素
            if (list[j] < list[k])
                k = j;
        swap(i, k); // 将最小元素插入 i 位置
    }
}
// 交换两元素位置
void SelectSort::swap(int i, int j)
{
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}
// （直接选择排序）后，输出排序结果
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
