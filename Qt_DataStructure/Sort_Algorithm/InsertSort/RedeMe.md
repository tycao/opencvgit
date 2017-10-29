�������� ��
=======
ֱ�Ӳ�������
--------
#### �����ͼ���£�
![insert_sort](https://github.com/tycao/opencvgit/blob/master/Qt_DataStructure/Sort_Algorithm/InsertSort/src/insert_sort.png "insert_sort")

### ֱ�Ӳ��������Դ�������£�
#### insertsort.h
```cpp
#pragma once

#include <iostream>
#include <vector>

using namespace std;

class InsertSort
{
public:
    InsertSort(std::vector<int> _list, int _len);   // ���캯��
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

// ���캯��
InsertSort::InsertSort(std::vector<int> _list, int _len)
    : len(_len)
{
    // ��_list��ǰ_len��Ԫ�أ�������ӵ�list��
    for (int i = 0; i != _len; ++i)
        list.push_back(_list[i]);
}
// ֱ�Ӳ�������
void InsertSort::insert_sort()
{
    int insertNum;
    for (int i = 1; i != len; ++i)  // �ܹ�����len�β���
    {
        insertNum = list[i];    // ������Ԫ��
        int j = i;
        while (j > 0 && insertNum < list[j - 1])
        {
            list[j] = list[j - 1];
            --j;
        }
        list[j] = insertNum;
    }
}
// ��������������
void InsertSort::out()
{
    for (int i = 0; i != len; ++i)
    {
        cout << list[i] << " ";
        if ((i + 1) % 18 == 0)  // ��18��Ԫ�أ��ͻ���
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