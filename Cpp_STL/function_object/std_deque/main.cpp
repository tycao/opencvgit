#include <algorithm>
#include <deque>
#include <queue>
#include <iterator>
#include <fstream>
#include <cstdlib>
#include "../../print.h"

int main(int argc, char *argv[])
{
#if 1
    // �����ļ���
    std::ifstream in("c:\\list.txt");
    // ����һ���յ�deque
    std::deque<std::string> D(
                (std::istream_iterator<std::string>(in)),
                (std::istream_iterator<std::string>())
                              );

/*
 * ��һ�ַ�ʽ���ļ�������ݣ������ж�ȡ��������deque��
    // ���ļ�����ÿһ�з���deque��
    std::string text;
    while (getline(in, text))
    {
        D.push_back(text);
    }
*/
    // ��ӡD������Ԫ��
    std::copy(D.cbegin(), D.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));
#endif

#if 0
    std::deque<int> dInt;
    std::vector<int> vInt{1, 3, 5, 7, 9, 2, 4, 6, 8};
    try
    {
        int j = 0;
        std::for_each(vInt.begin(), vInt.end(), [&](int i){ dInt.push_back(i); });
        std::for_each(dInt.begin(), dInt.end(), [&](int& i){ std::cout << dInt[j++] << " "; });
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
#endif
    return 0;
}
