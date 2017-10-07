#ifndef QUEENPUZZLE_H
#define QUEENPUZZLE_H

#include <iostream>
#include <fstream>

using namespace std;

// ����Ҫ��ʺ󲻳�ͻ����ôÿ��ֻӦ����һ���ʺ�
// ʹ��queens[]�������洢ÿ���ʺ������
// ���磺queens[m] = n��ʾ��m�еĻʺ���ڵ�n����
#define MAX 8


class QueenPuzzle
{
    int queens[MAX];    // �洢ÿ�лʺ���б�
public:
    static int sum;
    QueenPuzzle();
    QueenPuzzle(int i);
    void printOut(std::ostream& os);    // ��ӡ���
    int IsValid(int n); // �жϵ�n���ʺ����ȥ�Ժ��Ƿ�Ϸ�
    void placeQueen(int i, std::ostream& os); // �ݹ��㷨���ûʺ�
};


#endif // QUEENPUZZLE_H
