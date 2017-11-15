#include <iostream>
#include <set>
#include <deque>
#include <algorithm>
#include <functional>
#include "../../print.h"

using namespace std;

int main(int argc, char *argv[])
{
    std::set<int, greater<int>> coll1;
    deque<int> coll2;   // ���У�LIFO ����ȳ���

    // insert elements from 1 to 9
    for (int i = 1; i != 10; ++i)
        coll1.insert(i);

    // ��ӡ����coll1
    PRINT_ELEMENT(coll1, "initialized: ");

    // transform all elements into coll2 by multiplying 10
    transform(coll1.begin(), coll1.end(),   // ��������coll1������Ԫ��
              back_inserter(coll2), // ���뵽coll2β��
              std::bind(multiplies<int>(), std::placeholders::_1, 10)); // ��ÿ��Ԫ�ض�����10
    coll2.push_back(70);

    // ��ӡ����coll2
    PRINT_ELEMENT(coll2, "transformed: ");

    // ��Ԫ����ֵ����70��Ԫ�� �滻Ϊ 42
    std::replace_if(coll2.begin(), coll2.end(), // ��������coll2
                    std::bind(equal_to<int>(), std::placeholders::_1, 70),  // �ҳ����е���70��Ԫ��
                    42);    // ���任��42

    // ��ӡ�滻���coll2
    PRINT_ELEMENT(coll2, "replaced: ");

    // ɾ��Ԫ����ֵС��50��Ԫ��
    coll2.erase(remove_if(coll2.begin(), coll2.end(),   // ɾ������С��50��Ԫ��
                          std::bind(std::less<int>(), std::placeholders::_1, 50)),
                coll2.end());

    // ��ӡɾ�����coll2
    PRINT_ELEMENT(coll2, "removed: ");

    return 0;
}
