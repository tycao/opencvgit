ѡ������
======
ֱ��ѡ����������򵥵�ѡ�����򷽷������������Ϊ������������Ϊ����������һ�����ݶ�����ѡ�������С�ؼ���Ķ��������������������ĵ�һ���������������еĵ�һ������Ե���
Ȼ������������У��޳�������С�ؼ���Ķ�����ʣ�µĶ������ظ�ִ���������衣ֱ��ʣ�����ֻ��һ��Ϊֹ��
��Ȼ����������У�������ͬ�ؼ���Ķ�����ܻ�ߵ�����ֱ��ѡ�������㷨��һ�ֲ��ȶ��������㷨��
----------
#### �������н�ͼ���£�
![selectsort](https://github.com/tycao/opencvgit/blob/master/Qt_DataStructure/Sort_Algorithm/SelectSort/src/SelectSort.png "selectsort")

### ֱ��ѡ�������Դ�������£�
#### selectsort.h
```cpp
#pragma once

#include <vector>
#include <iostream>

using namespace std;

class SelectSort
{
public:
    SelectSort(std::vector<int> _list, int _len);   // ���캯��
    void select_sort(); // ֱ��ѡ������
    void swap(int, int);
    void out(); // ��ֱ��ѡ�����������������
private:
    int len;
    std::vector<int> list;
};

```
#### selectsort.cpp
```cpp
#include "selectsort.h"

// ���캯��
SelectSort::SelectSort(std::vector<int> _list, int _len)
    : len(_len)
{
    // ����һ�����ݼ���
    for (int i = 0; i != _len; ++i)
        list.push_back(_list[i]);
}
// ֱ��ѡ������
void SelectSort::select_sort()
{
    int k;
    for (int i = 0; i != len; ++i)
    {
        // ����len�αȽ�
        k = i;
        for (int j = i + 1; j != len; ++j)  // ����СԪ��
            if (list[j] < list[k])
                k = j;
        swap(i, k); // ����СԪ�ز��� i λ��
    }
}
// ������Ԫ��λ��
void SelectSort::swap(int i, int j)
{
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}
// ��ֱ��ѡ�����򣩺����������
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