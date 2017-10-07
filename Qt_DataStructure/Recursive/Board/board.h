#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class Board
{
public:
    // 构造函数
    Board(int x, int y);
    // 得到路径
    void GetPath(std::ostream& os);
private:
    int board[8][8];    // 棋盘
    int step;   // 当前走的步数
    int No; // 当前解的编号
    int direct[8][2];   // 各前进方向的坐标偏移
    int wayCount[8][8]; // 棋盘上每个位置可跳出的方向数目
    int startX; // 起始点坐标X
    int startY; // 起始点坐标Y
    int dir[8][8][8];   // 保存最优的搜索方向顺序

    // 初始化整个棋盘布局
    void init();
    // 检查x y是否为合法位置
    int check(int x, int y);
    // 从指定位置出发，寻找路径
    void dg(int x, int y, std::ostream& os);
    // 打印走过的路径
    void printPath(std::ostream& os);
    //
    void printwc();
};
