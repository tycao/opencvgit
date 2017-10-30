插入排序：
========
希尔排序：
---------
#### 希尔排序 又称为缩小增量排序。该算法先取一个小于数据表中元素个数n的整数gap，并以此作为第一间隔。将数据表分为gap个子序列，所有距离为gap的对象都存放在同一个子序列中。这样，也就把数据表中的所有元素分成了gap个组。
### 程序截图如下：
![shellsort](https://github.com/tycao/opencvgit/blob/master/Qt_DataStructure/Sort_Algorithm/ShellSort/src/ShellSort.png "shellsort")

### 希尔排序的源代码如下所示：
#### shellsort.h
```cpp
// 希尔排序
#pragma once

#include <vector>
#include <iostream>

using namespace std;

class ShellSort
{
public:
    // 构造函数
    ShellSort(std::vector<int> _list, int _len);
    void shell_sort();  // 希尔排序
    void out(); // 按照顺序输出（希尔）排序后的元素
private:
    int len;
    std::vector<int> list;
};

```
#### shellsort.cpp
```cpp
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

```

#### main.cpp
```cpp
#include "shellsort.h"

int main(int argc, char *argv[])
{
    std::vector<int> vInt{1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 13, 15, 17};
    ShellSort sort(vInt, 13);
    sort.shell_sort();
    sort.out();

    return 0;
}

```