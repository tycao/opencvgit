#include "queenpuzzle.h"

int main(int argc, char *argv[])
{
    ofstream fout("d:\\board.txt");
    QueenPuzzle queen(1);  // Ĭ�Ϲ��캯��
    queen.placeQueen(1, fout);

    return 0;
}
