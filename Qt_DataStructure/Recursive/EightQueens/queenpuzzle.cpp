#include "queenpuzzle.h"
#include <algorithm>


int QueenPuzzle::sum = 0;

QueenPuzzle::QueenPuzzle() = default;

QueenPuzzle::QueenPuzzle(int i)
{
   int queens_temp[MAX] = {i};
   std::swap(queens, queens_temp);
}

void QueenPuzzle::printOut(std::ostream& os)    // ��ӡ���
{
    for (int i = 0; i != MAX; ++i)
    {
        for (int j = 0; j != MAX; ++j)
            if (j == queens[i])
                os << "Q ";
            else
                os << "0 ";
        os << endl;
    }
    os << endl << "��q�����˳���������������..." << endl << endl;
    char c;
    if (cin >> c)
        if (c == 'q')
            exit(0);
}


// �жϵ�n���ʺ����ȥ�Ժ��Ƿ�Ϸ������Ƿ��޳�ͻ
int QueenPuzzle::IsValid(int n) // �жϵ�n���ʺ����ȥ�Ժ��Ƿ�Ϸ�
{

    // ����n���ʺ��λ��������ǰn-1���ʺ��λ�����Ƚ�
    for (int i = 0; i != n; ++i)
    {
        // �����ʺ���ͬһ���ϣ�����0
        if (queens[i] == queens[n])
            return false;
        // �����ʺ���ͬһ�Խ����ϣ�����0
        if (abs(queens[i] - queens[n]) == (n - i))
            return false;
    }
    // û�г�ͻ������1
    return true;
}
// �ڵ�i�з��ûʺ�
void QueenPuzzle::placeQueen(int i, std::ostream& os) // �ݹ��㷨���ûʺ�
{
    for (int j = 0; j != MAX; ++j)
    {
        // ���ȫ�������ˣ���������
        if (i == MAX)
        {
            ++sum;
            os << "��" << sum << "��⣺ " << endl;
            printOut(os);
            return;
        }
        // ���ûʺ�
        queens[i] = j;
        // ��λ�ò��ܷ��ûʺ󣬼���������һ��
        if (IsValid(i))
            placeQueen(i + 1, os);
    }
}
