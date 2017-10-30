#include "shellsort.h"

// 构造函数
ShellSort::ShellSort(std::vector<int> _list, int _len)
    : len(_len)
{
    for (int i = 0; i != len; ++i)
        list.push_back(_list[i]);
}
// 希尔排序
void ShellSort::shell_sort()
{
    int insertNum;  // 初始增量
    int gap = len / 2;
    while (gap) // 当 gap >= 1
    {
        for (int i = gap; i != len; ++i)
        {
            // 对gap间隔子序列进行插入排序
            insertNum = list[i];    // 待插入元素
            int j = i;
            while (j >= gap && insertNum < list[j - gap])
            {
                // 寻找插入位置
                list[j] = list[j - gap];
                j -= gap;
            }
            list[j] = insertNum;    // 插入
        }
        gap = gap / 2;  // 缩小增量
    }
}

// 按照顺序输出（希尔）排序后的元素
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
