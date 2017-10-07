#pragma once

#include <vector>
#include "crossings.h"


class Maze
{
private:
    int exit;   //出口编码
    std::vector<Crossings> crossings;   // 路口集合
    std::vector<int> result;
public:
    // 构造函数
    Maze(int the_exit, vector<Crossings> the_crossings);
    int findExit(int entrance); // 迷宫求解
    void getResult();    // 取得迷宫解 并打印
};
