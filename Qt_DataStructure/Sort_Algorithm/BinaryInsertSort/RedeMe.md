��������
=======
���ַ���������
---------
### �������н�ͼ���£�
![BinaryInsertSort](https://github.com/tycao/opencvgit/blob/master/Qt_DataStructure/Sort_Algorithm/BinaryInsertSort/src/BinaryInsertSort.png "BinaryInsertSort")
### ���ַ����������Դ�������£�
#### binaryinsertsort.h
```cpp
#pragma once

#include <vector>
#include <iostream>

using namespace std;

class BinaryInsertSort
{
public:
    BinaryInsertSort(std::vector<int> _list, int _len); // ���캯��
    void binary_insert_sort();  // ���ֲ�������
    void out(); // �ź���֮��������
private:
    int len;
    std::vector<int> list;
};

```
#### binaryinsertsort.cpp
```cpp
#include "binaryinsertsort.h"

// ���캯�� : ����һ��˳��
BinaryInsertSort::BinaryInsertSort(std::vector<int> _list, int _len)
    : len(_len)
{
    for (int i = 0; i != _len; ++i)
        list.push_back(_list[i]);
}
// ���ֲ�������
void BinaryInsertSort::binary_insert_sort()
{
    int middle;
    for (int i = 0; i != len; ++i)
    {
        int insertNum = list[i];
        int left = 0;
        int right = i - 1;
        while (left <= right)   // ���ַ�Ѱ�Ҳ���λ��
        {
            middle = (left + right) / 2;
            if (insertNum > list[middle])
                left = middle + 1;
            else
                right = middle - 1;
        }
        for (int j = i; j > left; --j)
            list[j] = list[j - 1];
        list[left] = insertNum;
    }
}
// �����ֲ��������ź���֮��������
void BinaryInsertSort::out()
{
    for (int i = 0; i != len; ++i)
    {
        cout << list[i] << " ";
        if ((i + 1) % 18 == 0) cout << "\n";    // ��18��Ԫ�أ���һ�����
    }
    cout << "\n";
}

```
#### main.cpp
```cpp
#include "binaryinsertsort.h"

int main(int argc, char *argv[])
{
    // Unit Test
    std::vector<int> vInt{1, 3, 5, 7, 9, 2, 4, 6, 8, 13, 15, 17, 19};
    BinaryInsertSort binSort(vInt, 13);
    binSort.binary_insert_sort();
    binSort.out();
    return 0;
}

```
