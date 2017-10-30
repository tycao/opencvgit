��������
========
ϣ������
---------
#### ϣ������ �ֳ�Ϊ��С�������򡣸��㷨��ȡһ��С�����ݱ���Ԫ�ظ���n������gap�����Դ���Ϊ��һ����������ݱ��Ϊgap�������У����о���Ϊgap�Ķ��󶼴����ͬһ���������С�������Ҳ�Ͱ����ݱ��е�����Ԫ�طֳ���gap���顣
### �����ͼ���£�
![shellsort](https://github.com/tycao/opencvgit/blob/master/Qt_DataStructure/Sort_Algorithm/ShellSort/src/ShellSort.png "shellsort")

### ϣ�������Դ����������ʾ��
#### shellsort.h
```cpp
// ϣ������
#pragma once

#include <vector>
#include <iostream>

using namespace std;

class ShellSort
{
public:
    // ���캯��
    ShellSort(std::vector<int> _list, int _len);
    void shell_sort();  // ϣ������
    void out(); // ����˳�������ϣ����������Ԫ��
private:
    int len;
    std::vector<int> list;
};

```
#### shellsort.cpp
```cpp
#include "shellsort.h"

// ���캯��
ShellSort::ShellSort(std::vector<int> _list, int _len)
    : len(_len)
{
    for (int i = 0; i != len; ++i)
        list.push_back(_list[i]);
}
// ϣ������
void ShellSort::shell_sort()
{
    int insertNum;  // ��ʼ����
    int gap = len / 2;
    while (gap) // �� gap >= 1
    {
        for (int i = gap; i != len; ++i)
        {
            // ��gap��������н��в�������
            insertNum = list[i];    // ������Ԫ��
            int j = i;
            while (j >= gap && insertNum < list[j - gap])
            {
                // Ѱ�Ҳ���λ��
                list[j] = list[j - gap];
                j -= gap;
            }
            list[j] = insertNum;    // ����
        }
        gap = gap / 2;  // ��С����
    }
}

// ����˳�������ϣ����������Ԫ��
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