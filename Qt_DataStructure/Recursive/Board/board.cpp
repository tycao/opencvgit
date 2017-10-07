#include "board.h"

// ********************************************************
// ******** Public Member Function of class Board *********
// ********************************************************
// 构造函数
Board::Board(int x, int y) : startX(x), startY(y)
{
    int i, j;
    direct[0][0] = 1;
    direct[0][1] = -2;
    direct[1][0] = 2;
    direct[1][1] = -1;
    direct[2][0] = 2;
    direct[2][1] = 1;
    direct[3][0] = 1;
    direct[3][1] = 2;
    direct[4][0] = -1;
    direct[4][1] = 2;
    direct[5][0] = -2;
    direct[5][1] = 1;
    direct[6][0] = -2;
    direct[6][1] = -1;
    direct[7][0] = -1;
    direct[7][1] = -2;

    step = 1;
    No = 0;
    for (j = 0; j != 8; ++j)
        for (i = 0; i != 8; ++i)
            board[j][i] = -1;
    board[y][x] = 0;

}
// 得到路径
void Board::GetPath(std::ostream& os)
{
    init();
    dg(startX, startY, os);
    if (No == 0)
        cout << "No Result!" << endl;
}

// ********************************************************
// ******** Private Member Function of class Board ********
// ********************************************************
// 初始化整个棋盘布局
void Board::init()
{
    int i, j, k;
    int x, y;
    // 确定从棋盘上每个位置可以跳出的方向数目
    for (j = 0; j != 8; ++j)
        for (i = 0; i != 8; ++i)
        {
            wayCount[j][i] = 0;
            for (k = 0; k != 8; ++k)
            {
                x = i + direct[k][0];
                y = j + direct[k][1];
                if (check(x, y))
                    ++wayCount[j][k];
            }
        }
    // 为棋盘上每个位置确定搜索的方向顺序
    for (y = 0; y != 8; ++y)
        for (x = 0; x != 8; ++x)
        {
            // 默认搜索顺序为顺时针方向
            for (k = 0; k != 8; ++k)
                dir[y][x][k] = k;
            // 寻找最优搜索顺序
            for (i = 0; i != 7; ++i)
            {
                k = i;
                int x1 = x + direct[dir[y][x][k]][0];
                int y1 = y + direct[dir[y][x][k]][1];
                // 为各个搜索方向，按照规则排序
                // 希望搜索时 优先到达下一步可能性较少的位置
                for (j = i + 1; j != 8; ++j)
                {
                    int x2 = x + direct[dir[y][x][j]][0];
                    int y2 = y + direct[dir[y][x][j]][1];
                    // 若从当前位置出发的方向j优于方向k，则将k替换为j
                    if ((!check(x1, y1) && check(x2, y2))
                            || (check(x1, y1) && check(x2, y2) && wayCount[x1][y1] > wayCount[x2][y2]))
                    {
                        k = j;
                        x1 = x + direct[dir[y][x][k]][0];
                        y1 = y + direct[dir[y][x][k]][1];
                    }
                }
                j = dir[y][x][k];
                dir[y][x][k] = dir[y][x][i];
                dir[y][x][i] = j;
            }
        }
}
// 检查x y是否为合法位置
int Board::check(int x, int y)
{
    if (x < 0 || x > 7 || y < 0 || y > 7)
        return 0;
    else
        return 1;
}
// 从指定位置（x, y）出发，寻找路径
void Board::dg(int x, int y, std::ostream& os)
{
    int i, nx, ny;
    // 如果当前为最后一步，则终止递归
    if (step == 64)
    {
        printPath(os);
        return;
    }
    // 按照最优的搜索方向顺序，依次向各可能方向搜索
    for (i = 0; i != 8; ++i)
    {
        nx = x + direct[dir[y][x][i]][0];
        ny = y + direct[dir[y][x][i]][1];
        if (nx > 0 && nx < 8 && ny > 0 && ny < 8)
            // 如果成功到达下一个位置，则从新位置开始继续搜索
            if (board[ny][nx] < 0)
            {
                board[ny][nx] = step;
                ++step;
                dg(nx, ny, os);
                board[ny][nx] = -1;
                --step;
            }
    }
}
// 打印走过的路径
void Board::printPath(std::ostream& os)
{
    int i, j;
    ++No;
    os << "No" << No << " : " << endl;
    for (j = 0; j != 8; ++j)
    {
        for (i = 0; i != 8; ++i)
        {
            os << board[j][i] << " ";
            if (board[j][i] < 10)
                os << " ";
        }
        os << endl;
    }
}
//
void Board::printwc()
{
    int i, j;
    ++No;
    cout << "No" << No << " : " << endl;
    for (j = 0; j != 8; ++j)
    {
        for (i = 0; i != 8; ++i)
        {
            cout << wayCount[j][i] << " ";
            if (wayCount[j][i] < 10)
                cout << " ";
        }
        cout << endl;
    }
}
