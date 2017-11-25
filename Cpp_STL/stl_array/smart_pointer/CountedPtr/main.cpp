#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <iterator>
#include"countedptr.h"

// ���³���˵�����ʹ�� CountedPtr ����ָ��

// ����һ��ȫ�ֺ�����������ӡCountedPtr�����õĶ���
void printCountedPtr(const CountedPtr<int>& elem)
{
    std::cout << *elem << " ";
}

int main(int argc, char *argv[])
{
    // ��̬����
    static int value[] = {3, 5, 9, 1, 6, 4};

    // ���ֲ�ͬ������
    typedef CountedPtr<int> IntPtr;
    std::deque<IntPtr> coll1;
    std::list<IntPtr> coll2;

    // �����õĶ������������
    for (int i = 0; i != sizeof(value) / sizeof(value[0]); ++i)
    {
        IntPtr ptr(new int(value[i]));
        coll1.push_back(ptr);
        coll2.push_front(ptr);  // reverse order comapred with coll1
    }

    // �ֱ��ӡ����������Ԫ��
    std::for_each(coll1.begin(), coll1.end(), [&](CountedPtr<int>& i){ std::cout << *i << " "; });
    std::cout << "\n\n";
    std::for_each(coll2.begin(), coll2.end(), printCountedPtr);
    std::cout << "\n\n";

    *coll1[2] *= *coll1[2];
    **coll1.begin() *= -1;
    **coll2.begin() = 0;

    // �޸����ݺ󣬷ֱ��ӡ���������ڵ�����Ԫ��
    std::for_each(coll1.begin(), coll1.end(), printCountedPtr);
    std::cout << "\n\n";
    std::for_each(coll2.begin(), coll2.end(), printCountedPtr);
    std::cout << "\n\n";

    return 0;
}
