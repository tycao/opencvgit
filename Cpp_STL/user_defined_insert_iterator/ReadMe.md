User-Defined iterator��ʹ�����Զ���ĵ�������
========
�������Լ���д���������ɣ�
--------
### ����һ������ʽ�����ĵ�������
#### ����Ŀ¼�����£�
![tree](https://github.com/tycao/opencvgit/blob/master/Cpp_STL/user_defined_insert_iterator/src/tree.png "tree")

### �Զ���� ������������£�
#### assoiter.h
```cpp
#pragma once

#include <iterator>

/*
 * ����һ������ʽ������insert������ ��ģ����Ĵ���Դ����
*/
template<typename Container>
class asso_insert_iterator : public std::iterator<std::output_iterator_tag, void, void, void, void>
{
public:
    // ���캯��
    explicit asso_insert_iterator(Container& c)
        : container(c)
    {

    }

    // ������ֵ�����
    // ��һ�����ݲ��뵽������
    asso_insert_iterator<Container>& operator =(const typename Container::value_type& value)
    {
        container.insert(value);
        return *this;
    }

    // �����������
    // �����κβ�����ֱ�ӷ��ص���������
    asso_insert_iterator<Container>& operator *()
    {
        return *this;
    }

    // ǰ�õ��������
    // �����κβ�����ֱ�ӷ��ص���������
    asso_insert_iterator<Container>& operator ++()
    {
        return *this;
    }

    // ���õ��������
    // �����κβ�����ֱ�ӷ��ص���������
    asso_insert_iterator<Container>& operator ++(int)
    {
        return *this;
    }
protected:
    Container& container;   // Ԫ����Ҫ���뵽��������
private:

};

// ���򵥵Ľӿڣ������������������
// �Ǹ��������� �� �������Ϳ���չ���ú�������������ʱ����
template<typename Container>
inline asso_insert_iterator<Container> asso_insert(Container& c)
{
    return asso_insert_iterator<Container>(c);
}
```

#### main.cpp
```cpp
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

#include "../../../print.h"
#include "assoiter.h"

int main(int argc, char *argv[])
{
    set<int> coll;
    // �ó�ʼ����ʽ��ԭʼ��ʽ����Ϊstd::set���ϵĶ��� ����һ�����������
    asso_insert_iterator<set<int>> iter(coll);
    *iter = 1;
    iter++;
    *iter = 2;
    ++iter;
    ++iter = 3;

    // ��ӡ ��ֵ֮��� std::set<int>���� coll
    PRINT_ELEMENT(coll, "coll : ");

    // ʹ�ø����㷽ʽ���ӿں���������Ϊstd::set<int>���� �������������
    asso_insert<set<int>>(coll) = 55;
    asso_insert<set<int>>(coll) = 66;

    // ��ӡset����
    PRINT_ELEMENT(coll, "coll after inserting values with an convenient way : ");

    // ʹ���㷨��������Ԫ��
    int vals[] = {33, 88, -7, 9, 25, 13, 2, 3, 18};
    copy(vals, vals + (sizeof(vals) / sizeof(vals[0])), // source iterator : Դ��������Χ
         asso_insert<set<int>>(coll));  // Ŀ�ĵ� ������

    // ��ӡ����
    PRINT_ELEMENT(coll, "coll after using algorithm to insert values : ");
    return 0;
}
```

### ������������
![output](https://github.com/tycao/opencvgit/blob/master/Cpp_STL/user_defined_insert_iterator/src/output.png "output")