#include <set>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

/*
 * set������ :
 * set_intersection��ȡ���Ͻ�������set_union��ȡ���ϲ�������
 * set_difference��ȡ���ϲ����set_symmetric_difference��ȡ���϶ԳƲ��
 * �Ⱥ���
*/

int main(int argc, char *argv[])
{
    std::set<int> MySet2;
    std::set<int> MySet3;
    std::set<int>::iterator i;
    int a[] = {1, 2, 3, 4, 5};
    set<int> MySet1{begin(a), begin(a) + 5};

    // Operation on MySet1
    cout << MySet1.size() << endl;
    i = MySet1.begin();
    cout << "MySet1 :";
    // ���� ���
    while (i != MySet1.end())
        cout << *i++ << " ";

    // operation on MySet2
    MySet2.insert(2);
    MySet2.insert(3);
    MySet2.insert(5);
    MySet2.insert(7);
    cout << endl;
    // ������� MySet2
    cout << "MySet2 :";
    std::for_each(MySet2.begin(), MySet2.end(), [&](int i){ cout << i << " "; });

    cout << endl;
    if (MySet2.find(5) != MySet2.end())
        cout << "MySet2 contains 5";
    ostream_iterator<int> out(cout, " ");   // ostream_iterator : ������ͷ�ļ� <iterator> ��
    // �󼯺�MySet1��MySet2�Ľ���
    cout << "\nMySet1��MySet2�Ľ�����";
    set_intersection( MySet1.begin(), MySet1.end(),
                      MySet2.begin(), MySet2.end(),
                      out );
    // �󼯺�MySet1��MySet2�Ĳ���
    cout << "\nMySet1��MySet2�Ĳ�����";
    set_union(MySet1.begin(), MySet1.end(),
              MySet2.begin(), MySet2.end(),
              out);
    // �󼯺�MySet1��MySet2�Ĳ
    cout << "\nMySet1��MySet2�Ĳ��";
    set_difference(MySet1.begin(), MySet1.end(),
                   MySet2.begin(), MySet2.end(),
                   out);

    cout << "\nMySet2��MySet1�Ĳ��";
    set_difference(MySet2.begin(), MySet2.end(),
                   MySet1.begin(), MySet1.end(),
                   out);

    cout << endl;
    // �󼯺�MySet1��MySet2�ĶԳƲ�
    set_symmetric_difference(MySet1.begin(), MySet1.end(),
                             MySet2.begin(), MySet2.end(),
                             inserter(MySet3, MySet3.begin())); // inserter : ������ͷ�ļ� <iterator> ��

    cout << "MySet1��MySet2�ĶԳƲ";
    set<int>::iterator j = MySet3.begin();
    //while (j != MySet3.end())
      //  cout << *j++ << " ";
    std::for_each(MySet3.begin(), MySet3.end(), [&](int i){ cout << i << " "; });
    cout << endl;

    return 0;
}
