#include <iostream>
#include "inbuf.h"

int main(int argc, char *argv[])
{
    inbuf ib;   // ����һ���������������
    std::istream in(&ib);   // �øոմ������������� ��ʼ��input������ȡ�� �� ��������

    char c;
    for (int i = 1; i <= 20; ++i) {
        // ��ȡ��һ���ַ���������֮�⣩
        in.get(c);

        // ��ӡ�ոն�ȡ���ַ�����ͨ��flush,��ջ�������
        std::cout << c << std::flush;

        // 8���ַ�֮�󣬽�2���ַ���ص�����
        if (i == 8) {
            in.unget();
            in.unget();
        }
    }

    std::cout << "\n";
    return 0;
}
