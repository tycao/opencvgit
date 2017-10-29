#include "insertsort.h"

// 构造函数
InsertSort::InsertSort(std::vector<int> _list, int _len)
    : len(_len)
{
    // 将_list的前_len个元素，拷贝添加到list里
    for (int i = 0; i != _len; ++i)
        list.push_back(_list[i]);
}
// 直接插入排序
void InsertSort::insert_sort()
{
    int insertNum;
    for (int i = 1; i != len; ++i)  // 总共进行len次插入
    {
        insertNum = list[i];    // 待插入元素
        int j = i;
        while (j > 0 && insertNum < list[j - 1])
        {
            list[j] = list[j - 1];
            --j;
        }
        list[j] = insertNum;
    }
}
// 输入排序后的数组
void InsertSort::out()
{
    for (int i = 0; i != len; ++i)
    {
        cout << list[i] << " ";
        if ((i + 1) % 18 == 0)  // 满18个元素，就换行
            cout << endl;
    }
    cout << "\n";
}
