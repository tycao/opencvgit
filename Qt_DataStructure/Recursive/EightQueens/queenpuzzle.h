#ifndef QUEENPUZZLE_H
#define QUEENPUZZLE_H

#include <iostream>
#include <fstream>

using namespace std;

// 首先要求皇后不冲突，那么每行只应该有一个皇后
// 使用queens[]数组来存储每个皇后的问题
// 例如：queens[m] = n表示第m行的皇后放在第n列上
#define MAX 8


class QueenPuzzle
{
    int queens[MAX];    // 存储每行皇后的列表
public:
    static int sum;
    QueenPuzzle();
    QueenPuzzle(int i);
    void printOut(std::ostream& os);    // 打印结果
    int IsValid(int n); // 判断第n个皇后放上去以后，是否合法
    void placeQueen(int i, std::ostream& os); // 递归算法放置皇后
};


#endif // QUEENPUZZLE_H
