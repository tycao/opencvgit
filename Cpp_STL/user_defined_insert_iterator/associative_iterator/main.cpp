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
