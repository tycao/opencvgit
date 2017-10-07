#include "queenpuzzle.h"
#include <algorithm>


int QueenPuzzle::sum = 0;

QueenPuzzle::QueenPuzzle() = default;

QueenPuzzle::QueenPuzzle(int i)
{
   int queens_temp[MAX] = {i};
   std::swap(queens, queens_temp);
}

void QueenPuzzle::printOut(std::ostream& os)    // 打印结果
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
    os << endl << "按q键盘退出，按其它键继续..." << endl << endl;
    char c;
    if (cin >> c)
        if (c == 'q')
            exit(0);
}


// 判断第n个皇后放上去以后，是否合法，即是否无冲突
int QueenPuzzle::IsValid(int n) // 判断第n个皇后放上去以后，是否合法
{

    // 将第n个皇后的位置依次与前n-1个皇后的位置作比较
    for (int i = 0; i != n; ++i)
    {
        // 两个皇后在同一列上，返回0
        if (queens[i] == queens[n])
            return false;
        // 两个皇后在同一对角线上，返回0
        if (abs(queens[i] - queens[n]) == (n - i))
            return false;
    }
    // 没有冲突，返回1
    return true;
}
// 在第i行放置皇后
void QueenPuzzle::placeQueen(int i, std::ostream& os) // 递归算法放置皇后
{
    for (int j = 0; j != MAX; ++j)
    {
        // 如果全部放完了，输出结果。
        if (i == MAX)
        {
            ++sum;
            os << "第" << sum << "组解： " << endl;
            printOut(os);
            return;
        }
        // 放置皇后
        queens[i] = j;
        // 此位置不能放置皇后，继续试验下一个
        if (IsValid(i))
            placeQueen(i + 1, os);
    }
}
