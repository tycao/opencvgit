插入排序 ：
=======
直接插入排序：
--------
#### 程序截图如下：
![insert_sort](https://github.com/tycao/opencvgit/blob/master/Qt_DataStructure/Sort_Algorithm/InsertSort/src/insert_sort.png "insert_sort")

### 直接插入排序的源代码如下：
#### insertsort.h
```cpp
#pragma once

#include <iostream>
#include <vector>

using namespace std;

class InsertSort
{
public:
    InsertSort(std::vector<int> _list, int _len);   // 构造函数
    void insert_sort();
    void out();
private:
    int len;
    std::vector<int> list;
};

```
#### insertsort.cpp
```cpp
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

```

### main.cpp
```cpp
#include "insertsort.h"

int main(int argc, char *argv[])
{
    // Unit test
    std::vector<int> vInt{1, 3, 5, 2, 6, 9, 7, 4, 8};
    InsertSort sort(vInt, 9);

    sort.insert_sort();
    sort.out();
    return 0;
}

```