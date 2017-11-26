#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main(int argc, char *argv[])
{
    // Ϊ��׼����� ���� �����������
    // ÿ��ֵ �Ի��з��ָ�
    ostream_iterator<int> intWrite(cout, "\n");

    // write elements with the usual iterator interface
    *intWrite = 42;
    ++intWrite;
    *intWrite = 77;
    ++intWrite;
    *intWrite = -5;
    ++intWrite;

    // ����һ����vector��Ԫ�ش�1��9
    vector<int> coll;
    for (int i = 1; i != 10; ++i)
        coll.push_back(i);

    // write all elements without any delimiter
    copy(coll.cbegin(), coll.cend(),
         ostream_iterator<int>(cout));
    cout << endl;

    // write all elements with " < " delimiter
    copy(coll.cbegin(), coll.cend(),
         ostream_iterator<int>(cout, " < "));
    cout << "\n";

    return 0;
}
