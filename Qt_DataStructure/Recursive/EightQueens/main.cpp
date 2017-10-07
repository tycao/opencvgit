#include "queenpuzzle.h"

int main(int argc, char *argv[])
{
    ofstream fout("d:\\board.txt");
    QueenPuzzle queen(1);  // 默认构造函数
    queen.placeQueen(1, fout);

    return 0;
}
