选择排序：
======
直接选择排序：是最简单的选择排序方法。其基本步骤为（以升序排列为例）首先在一组数据对象里选择具有最小关键码的对象。若它不是这组对象里的第一项，则将它与这组对象中的第一个对象对调。
然后在这组对象中，剔除具有最小关键码的对象。在剩下的对象中重复执行上述步骤。直到剩余对象只有一个为止。
显然在这个过程中，具有相同关键码的对象可能会颠倒次序，直接选择排序算法是一种不稳定的排序算法。
----------
#### 程序运行截图如下：
![selectsort](https://github.com/tycao/opencvgit/blob/master/Qt_DataStructure/Sort_Algorithm/SelectSort/src/SelectSort.png "selectsort")

### 直接选择排序的源代码如下：
#### selectsort.h
```cpp
#pragma once

#include <vector>
#include <iostream>

using namespace std;

class SelectSort
{
public:
    SelectSort(std::vector<int> _list, int _len);   // 构造函数
    void select_sort(); // 直接选择排序
    void swap(int, int);
    void out(); // （直接选择排序）排序后，输出结果
private:
    int len;
    std::vector<int> list;
};

```
#### selectsort.cpp
```cpp
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

```

#### main.cpp
```cpp
#include "selectsort.h"

int main(int argc, char *argv[])
{
    std::vector<int> vInt{1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 15, 17, 29, 18, 53, 34, 27};
    SelectSort sort(vInt, 17);
    sort.select_sort();
    sort.out();

    return 0;
}

```